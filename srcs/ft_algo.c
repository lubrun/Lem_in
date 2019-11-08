/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 17:09:15 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 17:11:04 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"


void	ft_del_last_path(t_group *group)
{
	int index;
	int index_room;

	index_room = 1;
	index = 0;
	while (group->paths[index])
		index++;
	index--;
	group->total_len -= group->paths[index]->length;
	while (group->paths[index]->rooms[index_room + 1])
	{
		group->tab[group->paths[index]->rooms[index_room]->index] = 0;
		index_room++;
	}
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
/*
 *	FIRST TRY
 *
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
*/


// GOOD OONE

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
	printf ("turn == %d\n", turn);
	group->turn_min = turn;
}



//GOOD ONE

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
			if (path->length < tmp_turn || tmp_turn == 0)
			{
				if (ft_test_path(path, group))
				{
					ft_add_path_to_group(path, group);
					group = ft_best_group(info, id + 1, group, tmp);
	//				printf("BITE3\n");
					if (tmp_turn == 0 || group->turn_min < tmp_turn)
					{
						printf("\tBEST is [%d]\n", group->turn_min);
						tmp_turn = group->turn_min;
						**tmp = *group;
					}
					ft_del_last_path(group);
				}
			}
			path = path->next;
		}
		id++;
	}
	if (group->nb_paths > 0)
		ft_turn_min(info, group);
	return (group);
}



/*
////////////GOOD TWO
int		ft_turn_min(t_info *info, t_group *group, t_path *path, int *tmp_turn)
{
	int ant;
	int turn;

	ant = 0;
	turn = 0;
//	printf("group [len][nbpath] == [%d][%d] && anttotal = [%d]\n", group->total_len, group->nb_paths, info->ant_count);
	while (ant < info->ant_count)
	{
		turn++;
		ant = ((group->nb_paths + 1) * turn) - (group->total_len + path->length);
//		printf("ANT == [%d]\n",ant);
	}
	group->turn_min = turn;


	if (*tmp_turn == 0 || *tmp_turn > turn)
		return (turn);
	else
		return (0);

}

//////////// GOOD TWO
t_group	*ft_best_group(t_info *info, int id, t_group *group, t_group **tmp)
{
	t_path	*path;
	static int		tmp_turn;
	static int		tmp_nb_path;
	int				test;

	test = -1;

//	printf("START BEST GROUP TMPTURN == [%d]\n", tmp_turn);

	while (id < MIN(info->start->link_count, SIZE_TAB))
	{
//		printf("ID == [%d]\n",id);
		path = info->paths[id];
		while (path)
		{
//			printf("PATH ID ==[%d]\n", path->id_path);
			if (path->length < tmp_turn || tmp_turn == 0)
			{
				if (ft_turn_min(info, group, path, &tmp_turn) && (test = ft_test_path(path, group)))
				{
					ft_add_path_to_group(path, group);
	//				if (group->nb_paths > 0)
	//					ft_turn_min(info, group);
	//				printf("BITE3\n");
	//				if (tmp_turn == 0 || group->turn_min <= tmp_turn)
	//				{
						printf("\tBEST is [%d]\n", group->turn_min);
						tmp_turn = group->turn_min;
						**tmp = *group;
						tmp_nb_path = group->nb_paths;
						group = ft_best_group(info, id + 1, group, tmp);
	//				}
	//				else if (tmp_nb_path == 0 || tmp_nb_path > group->nb_paths)
	//				{
	//	//				tmp_nb_path = group->nb_paths;
	//					group = ft_best_group(info, id + 1, group, tmp);
	//				}
					ft_del_last_path(group);
				}
				else if ((tmp_nb_path == 0 || tmp_nb_path > (group->nb_paths)) && (test == 1 || (test != 0 && ft_test_path(path, group) == 1)))
				{
	//				tmp_nb_path = group->nb_paths;
	//				printf("BITE4\n");
					ft_add_path_to_group(path, group);
					group = ft_best_group(info, id + 1, group, tmp);
					ft_del_last_path(group);
				}
			}

			path = path->next;
		}
		id++;
	}

	return (group);
}
*/



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
		printf("\nPATH IDP[%d] IDS[%d] LEN [%d]\n-\n", path->id_path, path->id_from_start, path->length);
		while(path->rooms[index_room])
		{
//			printf("ROOM NAME[%s]\n", path->rooms[index_room]->name);
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

	group = new_group(info);
	tmp = new_group(info);
	ft_best_group(info, 0, group, &tmp);
	ft_display_tmp(tmp);
}
