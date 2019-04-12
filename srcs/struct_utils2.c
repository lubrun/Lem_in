/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 17:53:19 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 17:01:37 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			set_info(t_room *room, int *spec, t_info *info)
{
	if (*spec == 1)
	{
		if (!info->start)
			info->start = room;
		else
		{
			*spec = 0;
			return (-1);
		}
	}
	else if (*spec == 2)
	{
		if (!info->end)
			info->end = room;
		else
		{
			*spec = 0;
			return (-1);
		}
	}
	*spec = 0;
	return (1);
}

int			link_valid(t_room *from, t_room *to)
{
	if (from->link_count > 0)
	{
		if (get_room_link_by_name(to->name, from) != NULL)
			return (0);
	}
	else if (to->link > 0)
	{
		if (get_room_link_by_name(from->name, to) != NULL)
			return (0);
	}
	if (ft_strcmp(from->name, to->name) == 0)
		return (0);
	return (1);
}

int			set_room(t_room **afrom, t_room **ato, t_room *room, char **info)
{
	if (!(*afrom = get_room_by_name(info[0], room)))
	{
		ft_2dstrdel(&info);
		return (0);
	}
	if (!(*ato = get_room_by_name(info[1], room)))
	{
		ft_2dstrdel(&info);
		return (0);
	}
	if (link_valid(*afrom, *ato) == 0)
	{
		ft_2dstrdel(&info);
		return (0);
	}
	ft_2dstrdel(&info);
	return (1);
}

void		insert_link(t_room *room1, t_room *room2)
{
	t_room	**tmp;
	int		index;

	tmp = ft_memalloc(sizeof(t_room*) * (room1->link_count + 1));
	index = -1;
	while (++index < room1->link_count - 1)
		tmp[index] = room1->link[index];
	tmp[index++] = room2;
	tmp[index] = NULL;
	free(room1->link);
	room1->link = tmp;
}

int			set_lastline_link(char *last_line, t_room *room)
{
	t_room	*from;
	t_room	*to;

	if (set_room(&from, &to, room, ft_strsplit(last_line, '-')) == 0)
		return (0);
	ft_putendl(last_line);
	from->link_count++;
	insert_link(from, to);
	to->link_count++;
	insert_link(to, from);
	ft_strdel(&last_line);
	return (1);
}
