/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 17:53:19 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 19:07:44 by qbarrier    ###    #+. /#+    ###.fr     */
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

int			link_valid(t_room *from, t_room *to, t_info *info)
{
	if (from->link_count > 0)
	{
		if (link_exist(from->index, to->index, info))
		{
			return (0);
		}
	}
	if (!ft_strcmp(from->name, to->name))
		return (0);
	return (1);
}

int			set_room(t_room **afrom, t_room **ato,
		char **str_info, t_info *info)
{
	t_room	*from;
	t_room	*to;

	from = get_room_by_name(str_info[0], info->rooms);
	to = get_room_by_name(str_info[1], info->rooms);
	if (!from || !to)
	{
		ft_2dstrdel(&str_info);
		return (0);
	}
	if (!link_valid(from, to, info))
	{
		ft_2dstrdel(&str_info);
		return (0);
	}
	ft_2dstrdel(&str_info);
	*afrom = from;
	*ato = to;
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

int			set_lastline_link(char *last_line, t_info *info)
{
	t_room	*from;
	t_room	*to;

	from = NULL;
	to = NULL;
	if (set_room(&from, &to, ft_strsplit(last_line, '-'), info) == 0)
		return (0);
	ft_putendl(last_line);
	from->link_count++;
	info->link_tab[from->index][to->index] =
		(t_link) {NULL, from, to, NOT_USED, create_id(), -1};
	to->link_count++;
	info->link_tab[to->index][from->index] =
		(t_link) {NULL, to, from, NOT_USED, create_id(), -1};
	ft_strdel(&last_line);
	return (1);
}
