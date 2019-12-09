/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 17:09:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 13:11:03 by qbarrier    ###    #+. /#+    ###.fr     */
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
	int index;
	int index_room;
	t_path *path;

	index_room = 0;
	index = 0;
	printf("\t\t---------BEST WAY------------\n\n");
	printf("groupe len = [%d] nbpath[%d] turn_min [%d]\n", group->total_len, group->nb_paths, group->turn_min);
	while (index < group->nb_paths)
	{
		path = group->paths[index];
		printf("\nPATH IDP[%d] IDS[%d] LEN [%d]\n-\n", path->id_path, path->id_from_start, path->length);
//		while(index_room < path->length)
//		{
//			printf("ROOM NAME[%s]\n", path->rooms[index_room]->name);
//			index_room++;
//
//		}
		index_room = 0;
		index++;
	}
}

// GOOD OONE

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

t_group	*ft_best_group(t_info *info, int id, t_group *group, t_group **tmp)
{
	static int		tmp_turn;
	int				index;
	t_path			*new_path;

//	index = info->lock;
//	if (!group->paths[0]->tab_path_index[id])
//		return (group);
//	printf("1test ta maman\n");
	if (tmp_turn == 0 || group->turn_min < tmp_turn ||
			(group->turn_min == tmp_turn &&
			  group->nb_paths < (*tmp)->nb_paths))
	{
//		printf("\tBEST is [%d]\n", group->turn_min);
		tmp_turn = group->turn_min;
		**tmp = *group;
//		ft_display_tmp(group);
	}
	while (group->paths[0]->tab_path_index[++id])
	{
//	printf("2test ta maman ID [%d]index[%d]\n", id, index);
		index =-1;
		while (id < info->start->link_count && ++index < info->max_path_count)
		{
	//		printf("\tINDEX des paths FOR[%d]-TO[%d] index[%d]\n", group->paths[0]->id_path, group->paths[0]->tab_path_index[id][index], index);
	//		printf("3test ta maman\n");
//			if (!(group->paths[0]->tab_path_index[id][index] > -1))
//				break;
			new_path = get_path_by_id(info,
					group->paths[0]->tab_path_index[id][index]);
			if (!new_path || (new_path->length > tmp_turn && tmp_turn > 0))
				break;
			if (ft_test_path(new_path, group, info))
				group = ft_next(info, new_path, group, tmp);
		}
	}
	return (group);
}

void	ft_ptitdisplay(t_info* info, int id)
{
	t_path *path;
	int index;

	index = 0;
	while (index < info->start->link_count)
	{
		path = info->paths[index];
		if (path)
			break;
		index++;
	}
	index = 0;
	while (path->tab_path_index[id][index] > -1)
	{
		printf("----\t--\t-\tINDEX DE PATHS SAVES [%d]index[%d]LEN[%d]\n",path->tab_path_index[id][index], index, get_path_by_id(info, path->tab_path_index[id][index])->length);
		index++;
	}
		printf("MAX PATH == [%d]\n", info->max_path_count);

}

void	ft_algo(t_info *info)
{
	t_group	*group;
	t_group *tmp;
	int index;
	t_path	*path;

	printf("Allo\n");
//	ft_ptitdisplay(info, 0);
	index = 0;
	group = new_group(info);
	tmp = new_group(info);
	while (info->matrice[index])
	{
		info->lock = 0;
		path = get_path_by_id(info, index);
		printf("START Index [%d]\n", index);
		if (path)
		{

//			ft_display_tmp(group);
			ft_add_path_to_group(path, group);
			ft_turn_min(info->ant_count, group);
			group->tab[0] = path->id_path;
			group = ft_best_group(info, path->id_from_start, group, &tmp);
			ft_del_last_path(group);
		}
		index++;
	}
	printf("end algo\n");
	ft_display_tmp(tmp);
}
