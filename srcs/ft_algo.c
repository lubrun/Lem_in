/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 17:09:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 18:09:01 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"


void		ft_turn_min(t_info *info, t_group *group)
{
	int ant;
	int turn;

	ant = 0;
	turn = 0;
//	printf("group [len][nbpath] == [%d][%d] && anttotal = [%d]\n", group->total_len, group->nb_paths, info->ant_count);
	while (ant < info->ant_count)
	{
		turn++;
		ant = (group->nb_paths * turn) - group->total_len;
//		printf("ANT == [%d]\n",ant);
	}
	group->turn_min = turn;
}

void	ft_del_last_path(t_group *group)
{
	int index;

	index = 0;
	while (group->paths[index])
		index++;
	group->total_len -= group->paths[index - 1]->length;
	group->paths[index - 1] = NULL;
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

t_group	*ft_best_group(t_info *info, int id, t_group *group, t_group **tmp)
{
	t_path	*path;
	static int		tmp_turn;

//	printf("START BEST GROUP TMPTURN == [%d]\n", tmp_turn);

	while (id < MIN(info->start->link_count, SIZE_TAB))
	{
		path = info->paths[id];
		while (path)
		{
//			printf("PATH ID ==[%d]\n", path->id_path);
			if (ft_test_path(path, group))
			{
				ft_add_path_to_group(path, group);
				group = ft_best_group(info, id + 1, group, tmp);
//				printf("BITE3\n");
				if (tmp_turn == 0 || group->turn_min <= tmp_turn)
				{
					printf("\tBEST is [%d]\n", group->turn_min);
					tmp_turn = group->turn_min;
					**tmp = *group;
				}
				ft_del_last_path(group);
			}
			path = path->next;
		}
		id++;
	}
	if (group->nb_paths > 0)
		ft_turn_min(info, group);
	return (group);
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
	while (group->paths[index])
	{
		path = group->paths[index];
		printf("\nPATH IDP[%d] IDS[%d]\n-\n", path->id_path, path->id_from_start);
		while(path->rooms[index_room])
		{
			printf("ROOM NAME[%s]\n", path->rooms[index_room]->name);
			index_room++;

		}
		index_room = 0;
		index++;
	}
}

void	ft_algo(t_info *info)
{
	t_group	*group;
	t_group *tmp;

	group = new_group();
	tmp = new_group();
	ft_best_group(info, 0, group, &tmp);
	ft_display_tmp(tmp);
}

