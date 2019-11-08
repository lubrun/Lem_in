/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 01:12:02 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 17:45:20 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*create_id(t_info *info)
{
	int *id;
	int index;
	int a_virer;

	a_virer= info->ant;
	if (!(id = malloc(sizeof(int) * (SIZE_TAB))))
			return (NULL);
	index = 0;
//	printf("LINK START == %d\n", info->start->link_count);
	while (index < SIZE_TAB)
		id[index++] = -1;
	id[index] = 0;
	return (id);
}

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
			info->link_tab[index][index1] = (t_link) {NULL, NULL, NULL, NONE, create_id(info), -1};
			index1++;
		}
		info->link_tab[index][index1] = (t_link) {NULL, NULL, NULL, TAB_END, create_id(info), -1};
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

t_path	*new_path(int id_from_start, int id_path, int size_room)
{
	t_path	*path;

	if (!(path = ft_memalloc(sizeof(t_path))))
		return (NULL);
	if (!(path->rooms = ft_memalloc(sizeof(t_room) * (size_room + 1))))
		return (NULL);
	path->id_from_start = id_from_start;
	path->id_path = id_path;
	path->length = 0;
	path->next = NULL;
//	path->perfum = 0;
//	path->ant_needed = -1;
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
