/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tri_paths.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 15:47:37 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 13:55:43 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_display_path(t_info *info)
{
	int	index_path = 0;
	t_path *path;
	int index = 0;
	while(index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		path = info->paths[index_path];
		printf("----------TEST FOR ID [%d]-----------\n-\n", index_path);
		while (path)
		{
			while (path->rooms[index])
			{
				printf("PATH == IDP[%d] IDS[%d] NAME[%s] LEN{%d} PERF{%d}\n", path->id_path, path->id_from_start, path->rooms[index]->name, path->length, path->rooms[index]->perfum[index_path]);
				index++;
			}

			index = 0;
			printf("-\n");
			path = path->next;
		}
		index_path++;
	}
	index_path = 0;
	while (index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		path = info->paths[index_path];
		if (path)
			printf("----------TEST FOR IDS/P[%d]/[%d] LEN MIN == [%d] PERF-PATH [%d]-----------\n-\n", index_path, path->id_path, path->length, path->perfum);
		index_path++;
	}
	printf("\t\t-----LINK COUNT S[%d] E[%d]-------", info->start->link_count, info->end->link_count);
}

void	ft_swap_list(t_path *lst1, t_path *lst2)
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
}

t_path	*ft_tri_by_next(t_path *path)
{
	t_path *tmp;
	t_path *tmp2;

	tmp = path;
	tmp2 = path;
	while (tmp)
	{
		while (tmp2)
		{
			if (tmp->length > tmp2->length)
				ft_swap_list(tmp, tmp2);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp;
	}
	return (path);
}

void	ft_swap_tablist(t_path *lst1, t_path *lst2)
{
	int		id_path;
	int		id;
	t_path	*next;

	ft_swap_list(lst1, lst2);
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

void	ft_tri_by_id(t_path **path, t_info *info)
{
	int		id;
	int		id2;
	t_path	**tmp;
	t_path	**tmp2;

	id2 = 0;
	id = 0;
	tmp = path;
	tmp2 = path;
	while (id < MIN(SIZE_TAB, info->start->link_count))
	{
		while (id2 < MIN(SIZE_TAB, info->start->link_count))
		{
			if (tmp[id] && tmp[id2] && tmp[id]->length > tmp2[id2]->length)
				ft_swap_tablist(tmp[id], tmp2[id2]);
			id2++;
		}
		id++;
		id2 = id;
	}
}

void	ft_tri_paths(t_info *info)
{
	int index_path;

	index_path = 0;
	while (index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		info->paths[index_path] = ft_tri_by_next(info->paths[index_path]);
		index_path++;
	}
	ft_tri_by_id(info->paths, info);
	ft_display_path(info);
}
