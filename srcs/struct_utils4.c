/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils4.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 17:57:53 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 18:15:54 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_group		*new_group(t_info *info)
{
	t_group	*group;
	int		index;

	index = 0;
	if (!(group = ft_memalloc(sizeof(t_group))))
		return (NULL);
	group->nb_paths = 0;
	group->total_len = 0;
	if (!(group->tab = ft_memalloc(sizeof(int) *
					(info->start->link_count + 1))))
		return (NULL);
	while (index <= info->start->link_count)
		group->tab[index++] = -1;
	return (group);
}

t_path		*get_path_by_id(t_info *info, int id_path)
{
	int		id_start;
	t_path	*path;

	if (id_path < 0)
		return (NULL);
	id_start = 0;
	while (id_start < info->start->link_count)
	{
		path = info->paths[id_start];
		if (path)
		{
			if (!info->paths[id_start + 1] ||
					info->paths[id_start + 1]->id_path > id_path)
				break ;
		}
		id_start++;
	}
	while (path && path->id_path < id_path)
		path = path->next;
	return (path);
}

int			**ft_malloc_matrice(t_info *info, int **matrice)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	if (!(matrice = ft_memalloc(sizeof(int*) * (info->max_path_count + 1))))
		return (NULL);
	while (info->max_path_count > count)
	{
		if (!(matrice[count] = ft_memalloc(sizeof(int) *
						(info->max_path_count + 1))))
			return (NULL);
		while (index <= info->max_path_count)
		{
			matrice[count][index] = 0;
			index++;
		}
		index = 0;
		count++;
	}
	matrice[count] = NULL;
	return (matrice);
}

int			count_link(t_info *info, t_room *room)
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

void		ft_swap_list_end(t_path *lst1, t_path *lst2, t_info *info)
{
	if (info->tab_id_end[lst1->id_end] == -1 ||
			info->tab_id_end[lst1->id_end] > lst1->length)
		info->tab_id_end[lst1->id_end] = lst1->length;
	if (info->tab_id_end[lst2->id_end] == -1 ||
			info->tab_id_end[lst2->id_end] > lst2->length)
		info->tab_id_end[lst2->id_end] = lst2->length;
	if (lst1->length > info->max_path_len)
		info->max_path_len = lst1->length;
	if (lst2->length > info->max_path_len)
		info->max_path_len = lst2->length;
}
