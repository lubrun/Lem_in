/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tri_group.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 17:35:20 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 18:03:40 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_swap_group(t_path *lst1, t_path *lst2, t_info	 *info)
{
	int		len;
	t_room	**rooms;
	int		*tab_index_room;
	int		*tab_bin_room;

	tab_index_room = lst1->tab_index_room;
	tab_bin_room = lst1->tab_bin_room;
	lst1->tab_index_room = lst2->tab_index_room;
	lst1->tab_bin_room = lst2->tab_bin_room;
	lst2->tab_index_room = tab_index_room;
	lst2->tab_bin_room = tab_bin_room;
	len = lst1->length;
	rooms = lst1->rooms;
	lst1->length = lst2->length;
	lst1->rooms = lst2->rooms;
	lst2->length = len;
	lst2->rooms = rooms;
	lst2->id_end = lst2->rooms[lst2->length]->index;
	lst1->id_end = lst1->rooms[lst1->length]->index;
	ft_swap_list_end(lst1, lst2, info);
}

void		ft_swap_tabgroup(t_path *lst1, t_path *lst2, t_info *info)
{
	int		id_path;
	int		id;
	t_path	*next;

	ft_swap_group(lst1, lst2, info);
	next = lst1->next;
	lst1->next = lst2->next;
	lst2->next = next;
	id = lst1->id_from_start;
	id_path = lst1->id_path;
	while (lst1)
	{
		lst1->id_path = id_path++;
		lst1->id_from_start = id;
		lst1 = lst1->next;
	}
	id = lst2->id_from_start;
	id_path = lst2->id_path;
	while (lst2)
	{
		lst2->id_path = id_path++;
		lst2->id_from_start = id;
		lst2 = lst2->next;
	}
}

void		ft_tri_group(t_info *info)
{
	int		index;
	int		index2;

	index = 0;
	while (info->group->paths[index] && index < info->group->nb_paths)
	{
		index2 = 0;
		while (info->group->paths[index2] && index2 < info->group->nb_paths)
		{
			if (info->group->paths[index] && info->group->paths[index2] &&
					info->group->paths[index]->length > info->group->paths[index2]->length)
				ft_swap_tabgroup(info->group->paths[index], info->group->paths[index2], info);
			index2++;
		}
		index++;
	}
}
