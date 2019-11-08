/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:52:26 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
int get_max_path_len(t_info info)
{
	int index;
	int max;

	index = 0;
	max = -1;
	while (index < info.start->link_count)
	{
		//printf("MAX | TEST %s | HEAT_min %d | HEAT max %d\n", info.start->link[index]->name, info.start->link[index]->heat_min, info.start->link[index]->heat_max);
		if (max == -1 || info.start->link[index]->heat_min > max)
		{
			max = info.start->link[index]->heat_min;
			//printf("save {%d}\n", max);
		}
		index++;
	}
	return (max + 1);
}

*/
void	ft_display_info(t_info *info)
{
	int index = 0;
	int index2 = 0;
	t_link link;

	while (index < info->room_count)
	{
		while(index2 < info->room_count)
		{
			link = info->link_tab[index][index2];
			if (link.state > NONE)
				printf("NAME->NAME=TURN :[%s]->[%s]=[%d]\n", link.from->name, link.to->name, link.id[0]);
			index2++;
		}
		index2 = 0;
		index++;
	}


/*
	int id = 0;
	while (id < info->start->link_count)
	{
		printf("id = [%d] val = [%d]\n",id, link.id[id]);
		id++;
	}
*/
}




int set_id_room(t_info *info, t_link link, int turn, int id)
{
	t_link	new;
	int 	index;

	index = 0;

//	printf("LINK FROM[%s] TO[%s] - STATE{%d} - ID{%d} - TURN{%d}\n", link.from->name, link.to->name, link.state, id, link.id[id]);

	while (index < info->room_count)
	{
		new = info->link_tab[link.to->index][index];
		if (new.state > NONE)
		{
//			printf("--NEW ID == NAME == [%s] ID{%d} - TURN{%d}\n",new.to->name, id, new.id[id]);
			if ((new.id[id] == -1) && ft_strcmp(new.to->name, info->start->name))
			{
				info->link_tab[link.to->index][index].id[id] = turn;
				info->link_tab[index][link.to->index].id[id] = turn;
//				printf("\tLINK FROM[%s] TO[%s] - STATE{%d} - ID{%d} - TURN{%d}\n", link.from->name, link.to->name, link.state, id, link.id[id]);
				if (ft_strcmp(new.to->name, info->end->name) != 0)
					set_id_room(info, info->link_tab[link.to->index][index], turn + 1, id);
			}
			else if (new.id[id] == -1)
			{
				info->link_tab[index][link.to->index].id[id] = turn;
				info->link_tab[link.to->index][index].id[id] = turn;
			}
		}
		index++;
	}
	return (0);
}


int					ft_build_path(t_info *info, int index, t_path *path, int heat)
{
	int		index2;
	t_link	link;
	int		i_rooms;

	i_rooms = 0;
	index2 = 0;
//	printf("BUILD ON \n");
	while(index2 < info->room_count)
	{
		link = info->link_tab[index][index2];
		if (link.state > NONE && link.id[path->id_from_start] > -1 && link.id[path->id_from_start] < heat)
		{
//			printf("PATH FROM[%s]=> TO[%s] IDP[%d]\n", link.from->name, link.to->name, path->id_path);
			while (path->rooms[i_rooms])
				i_rooms++;
//			printf("\tROOM3 == [%s]\n", path->rooms[i_rooms - 1]->name);
			path->rooms[i_rooms] = link.to;
			ft_build_path(info, index2, path, link.id[path->id_from_start]);
		}
		index2++;
	}
	return (1);
}

void					ft_prepare_path(t_info *info, int index, t_link link, t_path *path)
{
	int			id_from_start;
	static int	id_path;

	id_from_start = path->id_from_start;
	path->length = link.id[id_from_start] - 1;
	path->id_path = id_path++;
	path->rooms[0] = link.from;
	path->rooms[1] = link.to;
	if (ft_strcmp(link.to->name, info->start->name))
		ft_build_path(info, index, path, link.id[path->id_from_start]);
	path->rooms[link.id[id_from_start] +1] = NULL;
}

t_path					*ft_opti_new_path(t_info *info, t_path *path, int id_from_start, int heat)
{
	int static id;

	if (!path || id_from_start != id)
	{
		id = id_from_start;
		path = new_path(id_from_start, 0, heat);
		info->paths[id] = path;
	}
	else
	{
		path->next = new_path(id_from_start, 0, heat);
		path = path->next;
	}
	return (path);
}


int						ft_all_path(t_info *info, t_link link, int id_from_start, int index)
{
	t_path	*path;

	path = NULL;
	while (id_from_start < MIN(SIZE_TAB, info->start->link_count))
	{
		while(index < info->room_count)
		{
			link = info->link_tab[info->end->index][index];
			if (link.state > NONE && link.id[id_from_start] > -1 && count_link(info, link.to) > 1)
			{
				
//				printf("TO == [%s]Heat[%d]\n",link.to->name, link.id[id_from_start]);
				path = ft_opti_new_path(info, path, id_from_start, link.id[id_from_start] + 2);
				ft_prepare_path(info, index, link, path);
			}
			index++;
		}
		index = 0;
		id_from_start++;
	}

	return (1);
}



void	ft_display_pat(t_info *info)
{
	int	index_path = 0;
	t_path *path;
	int index = 0;
	while(index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		path = info->paths[index_path];
		printf("----------FOR ID [%d]-----------\n-\n", index_path);
		while (path)
		{
			while (path->rooms[index])
			{
				printf("PATH == IDP[%d] IDS[%d] NAME[%s] LEN{%d}\n", path->id_path, path->id_from_start, path->rooms[index]->name, path->length);
				index++;
			}
			index = 0;
			printf("-\n");
			path = path->next;
		}
		index_path++;
	}
}



 unsigned long long int	**ft_pathfind(t_info *info)
{
	t_link	link;
	int		index;
	int		turn;
	int		id;

	id = 0;
	index = 0;
	while (index < info->room_count && id < MIN(info->start->link_count, SIZE_TAB))
	{
		link = info->link_tab[info->start->index][index];
		if (link.state > NONE && count_link(info, link.to) > 1)
		{
			turn = 1;
//			printf("START PATH [%s]->[%s]\n", link.from->name, link.to->name);
			if (link.from == info->end)
				return (NULL);
			link.state = USED;
			info->link_tab[index][info->start->index].id[id] = turn;
			link.id[id] = turn;
			set_id_room(info, link, ++turn, id++);
		}
		index++;
	}
	printf("\n\t\tend PAHT\n");
	ft_all_path(info, link, 0, 0);
//	ft_display_info(info);
//	ft_display_pat(info);
	return (NULL);
}
