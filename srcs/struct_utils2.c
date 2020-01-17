/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 17:53:19 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:09:18 by qbarrier    ###    #+. /#+    ###.fr     */
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

	printf("SET ROOM 1\n");
	from = get_room_by_name(str_info[0], info->rooms);
	to = get_room_by_name(str_info[1], info->rooms);
	printf("SET ROOM 1\n");
	if (!from || !to)
	{
	printf("SET ROOM 2\n");
		ft_2dstrdel(&str_info);
		return (0);
	}
	if (!link_valid(from, to, info))
	{
	printf("SET ROOM 3\n");
		ft_2dstrdel(&str_info);
		return (0);
	}
	printf("SET ROOM 4\n");
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

	printf("SET LAST LINE 1\n");
	from = NULL;
	to = NULL;
	if (set_room(&from, &to, ft_strsplit(last_line, '-'), info) == 0)
	{
		printf("SET LAST LINE 2\n");
		return (0);
	}
	ft_putendl(last_line);
	from->link_count++;
		printf("SET LAST LINE 3\n");
	info->link_tab[from->index][to->index] =
		(t_link) {NULL, from, to, NOT_USED, create_id(), -1};
	to->link_count++;
	info->link_tab[to->index][from->index] =
		(t_link) {NULL, to, from, NOT_USED, create_id(), -1};
		printf("SET LAST LINE 4\n");
	ft_strdel(&last_line);
	printf("SET LAST LINE 5\n");
	return (1);
}
