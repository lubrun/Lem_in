/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 01:12:02 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 14:12:00 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		create_link_tab(t_info *info)
{
	int		index;
	int		index1;

	index = 0;
	if (!(info->link_tab = ft_memalloc(sizeof(t_link *) *
		(info->room_count + 1))))
		return (0);
	while (index < info->room_count)
	{
		if (!(info->link_tab[index] = ft_memalloc(sizeof(t_link) *
			(info->room_count + 1))))
			return (0);
		index1 = 0;
		while (index1 < info->room_count)
		{
			info->link_tab[index][index1] = (t_link) {NULL, NULL, NONE, -1, -1};
			index1++;
		}
		info->link_tab[index][index1] = (t_link) {NULL, NULL, TAB_END, -1, -1};
		index++;
	}
	info->link_tab[index] = NULL;
	return (1);
}

void	sort_list(t_path **list)
{
	t_path	*tmp;
	int		index;
	int		sort;

	sort = 0;
	while (sort == 0)
	{
		index = 0;
		sort = 1;
		tmp = NULL;
		while (list[index])
		{
			if (list[index + 1] &&
					list[index + 1]->length > list[index]->length)
			{
				tmp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = tmp;
				sort = 0;
			}
			index++;
		}
	}
}

t_path	*new_path(t_info info)
{
	t_path	*path;

	if (!(path = ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->rooms = NULL;
	path->id = info.path_count;
	path->length = 0;
	path->perfum = 0;
	path->ant_needed = -1;
	return (path);
}

int		add_room_into_path(t_path *apath, t_room **aroom)
{
	t_room	**rooms;
	int		index;

	if (!(rooms = ft_memalloc(sizeof(t_room*) * (apath->length + 2))))
		return (-1);
	index = 0;
	while (index < apath->length)
	{
		rooms[index] = apath->rooms[index];
		index++;
	}
	rooms[index++] = *aroom;
	rooms[index] = NULL;
	free(apath->rooms);
	apath->rooms = rooms;
	return (1);
}

int		count_link(t_info *info, t_room *room)
{
	t_link	link;
	int		count;
	int		index;

	count = 0;
	index = -1;
	link = info->link_tab[room->index][0];
	while (link.state > TAB_END)
	{
		if (link.state != NONE)
			count++;
		link = info->link_tab[room->index][++index];
	}
	return (count);
}