/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 17:09:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:25:29 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_del_last_path(t_group *group)
{
	int index;
	int index_room;

	index_room = 1;
	index = 0;
	while (group->paths[index])
		index++;
	index--;
	group->total_len -= group->paths[index]->length;
	while (group->tab[index_room] > -1)
		index_room++;
	group->tab[index_room - 1] = -1;
	group->paths[index] = NULL;
	group->nb_paths--;
}

void	ft_add_path_to_group(t_path *path, t_group *group)
{
	int index;

	index = 0;
	while (group->paths[index])
		index++;
	group->paths[index] = path;
	group->nb_paths++;
	group->total_len += path->length;
}

void	ft_display_tmp(t_group *group)
{
	int		index;
	int		index_room;
	t_path	*path;

	index_room = 0;
	index = 0;
	printf("\t\t---------BEST WAY------------\n\n");
	printf("groupe len = [%d] nbpath[%d] turn_min [%d]\n",
			group->total_len, group->nb_paths, group->turn_min);
	while (index < group->nb_paths)
	{
		path = group->paths[index];
		printf("\nPATH IDP[%d] IDS[%d] LEN [%d]\n-\n",
				path->id_path, path->id_from_start, path->length);
		index_room = 0;
		index++;
	}
}

t_group	*ft_next(t_info *info, t_path *new_path, t_group *group, t_group **tmp)
{
	int id;

	id = new_path->id_from_start;
	ft_add_path_to_group(new_path, group);
	ft_turn_min(info->ant_count, group);
	group = ft_best_group(info, id, group, tmp);
	ft_del_last_path(group);
	return (group);
}

void	ft_groupcpy(t_group **tmp, t_group *group)
{
	int index;

	index = 0;
	(*tmp)->turn_min = group->turn_min;
	(*tmp)->total_len = group->total_len;
	(*tmp)->nb_paths = group->nb_paths;
	while (group->paths[index])
	{
		(*tmp)->paths[index] = group->paths[index];
		index++;
	}

}

t_group	*ft_best_group(t_info *info, int id, t_group *group, t_group **tmp)
{
	static int		tmp_turn;
	int				index;
	t_path			*new_path;

	if (tmp_turn == 0 || group->turn_min < tmp_turn ||
			(group->turn_min == tmp_turn &&
		group->nb_paths < (*tmp)->nb_paths))
	{
		printf("\t BEST is [%d]\n", group->turn_min);
		tmp_turn = group->turn_min;
		ft_groupcpy(tmp, group);
	//	**tmp = *group;
	}
	while (group->paths[0]->tab_path_index[++id])
	{
		index = -1;
		while (id < info->start->link_count && ++index < info->max_path_count)
		{
			new_path = get_path_by_id(info,
					group->paths[0]->tab_path_index[id][index]);
			if (!new_path || (new_path->length > tmp_turn && tmp_turn > 0))
				break ;
			if (ft_test_path(new_path, group, info))
				group = ft_next(info, new_path, group, tmp);
		}
	}
	return (group);
}

void	ft_algo(t_info *info)
{
	t_group	*group;
	t_group	*tmp;
	int		index;
	t_path	*path;

	index = 0;
	group = new_group(info);
	tmp = new_group(info);
	while (info->matrice[index])
	{
		info->lock = 0;
		path = get_path_by_id(info, index);
		if (path)
		{
			ft_add_path_to_group(path, group);
			ft_turn_min(info->ant_count, group);
			group->tab[0] = path->id_path;
			group = ft_best_group(info, path->id_from_start, group, &tmp);
			ft_del_last_path(group);
		}
		index++;
	}
	info->group = tmp;
	ft_free_group(group);
	ft_display_tmp(tmp);
	printf("END ALGO\n");
}
