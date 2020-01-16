/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 17:21:17 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int						ft_build_path(t_info *info, int index_start,
		t_path *path, int heat)
{
	int		index2;
	t_link	link;

	index2 = 0;
	while (index2 < info->room_count)
	{
		link = info->link_tab[index_start][index2];
		if (link.state > NONE && link.id[path->id_from_start] > -1
				&& link.id[path->id_from_start] < heat)
		{
			if (--info->lock > -1)
				path->rooms[info->lock] = link.to;
			ft_build_path(info, index2, path, link.id[path->id_from_start]);
			if (link.to != info->start)
			{
				path->tab_bin_room[link.to->index] = 1;
				path->tab_index_room[heat - 2] = link.to->index;
			}
			break ;
		}
		index2++;
	}
	return (1);
}

void					ft_prepare_path(t_info *info, int index,
		t_link link, t_path *path)
{
	int			id_from_start;
	static int	id_path;
	int			heat;

	id_from_start = path->id_from_start;
	heat = link.id[id_from_start];
	path->length = heat - 1;
	path->id_path = id_path++;
	info->lock = heat - 1;
	path->rooms[heat - 1] = link.to;
	path->tab_index_room[0] = link.to->index;
	path->tab_bin_room[link.to->index] = 1;
	if (ft_strcmp(link.to->name, info->start->name))
		ft_build_path(info, index, path, heat);
	path->id_end = path->rooms[path->length]->index;
	path->tab_index_room[heat - 1] = 0;
	path->rooms[heat] = NULL;
	info->max_path_count = id_path;
}

t_path					*ft_opti_new_path(t_info *info, t_path *path,
		int id_from_start, int heat)
{
	static int	id;

	if (!path || id_from_start != id)
	{
		id = id_from_start;
		path = new_path(info, id_from_start, 0, heat);
		info->paths[id] = path;
	}
	else
	{
		path->next = new_path(info, id_from_start, 0, heat);
		path = path->next;
	}
	return (path);
}

int						ft_all_path(t_info *info, int end_index,
		int id_from_start, int index)
{
	t_path	*path;
	t_link	link;

	path = NULL;
	while (id_from_start < MIN(SIZE_TAB, info->start->link_count))
	{
		while (index < info->room_count)
		{
			link = info->link_tab[end_index][index];
			if (link.state > NONE && link.id[id_from_start] > -1
					&& count_link(info, link.to) > 1)
			{
				path = ft_opti_new_path(info, path, id_from_start,
						link.id[id_from_start] + 2);
				ft_prepare_path(info, index, link, path);
			}
			index++;
		}
		index = 0;
		id_from_start++;
	}
	return (1);
}

unsigned long long int	**ft_pathfind(t_info *info, int start, int max_id_size)
{
	t_link	link;
	int		index;
	int		id;
	int		*tab;

	if (!(tab = ft_memalloc(sizeof(int) * 2)))
		return (0);
	id = 0;
	index = 0;
	while (index < info->room_count && id < max_id_size)
	{
		link = info->link_tab[start][index];
		if (link.state > NONE && count_link(info, link.to) > 1)
		{
			if (link.from == info->end)
				return (NULL);
			info->link_tab[index][start].id[id] = 1;
			printf("SET ID START\n");
			ft_prepare_set_id(info, link, tab, id);
			++id;
		}
		index++;
	}
	printf("SET ID END\n");
	free(tab);
	ft_all_path(info, info->end->index, 0, 0);
//	ft_display_info(info);
//	ft_display_pat(info);
	return (NULL);
}
