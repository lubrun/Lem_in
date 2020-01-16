/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 01:12:02 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 18:07:30 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*create_id(void)
{
	int	*id;
	int	index;

	if (!(id = malloc(sizeof(int) * (SIZE_TAB + 1))))
		return (NULL);
	index = 0;
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
			info->link_tab[index][index1] =
				(t_link) {NULL, NULL, NULL, NONE, NULL, -1};
			index1++;
		}
		info->link_tab[index][index1] =
			(t_link) {NULL, NULL, NULL, TAB_END, NULL, -1};
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

t_path	*new_path(t_info *info, int id_from_start, int id_path, int size_room)
{
	t_path	*path;

	if (!(path = ft_memalloc(sizeof(t_path))))
		return (NULL);
	if (!(path->rooms = ft_memalloc(sizeof(t_room) * (size_room - 1))))
		return (NULL);
	if (!(path->tab_bin_room = ft_memalloc(sizeof(int) * info->room_count)))
		return (NULL);
	if (!(path->tab_index_room = ft_memalloc(sizeof(int) * (size_room - 1))))
		return (NULL);
	if (!(path->tab_path_index = ft_memalloc(sizeof(int*)
					* (info->start->link_count + 1))))
		return (NULL);
	path->id_from_start = id_from_start;
	path->id_end = 0;
	path->ant = 0;
	path->save = 0;
	path->id_path = id_path;
	path->length = 0;
	path->next = NULL;
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
