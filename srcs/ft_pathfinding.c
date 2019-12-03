/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 03:53:22 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
//				printf("NAME->NAME=TURN :[%s]->[%s]=[%d]\n", link.from->name, link.to->name, link.id[0]);
			index2++;
		}
		index2 = 0;
		index++;
	}


}

// TEST LARGEUR
int		*ft_malloc_next_tab(t_info *info, int *next_tab, int *tab)
{
	int index;
	int nb_link;

	nb_link = 1;
	index = 0;
	while (tab[index] > -1)
	{
//		printf("\t\tROOM TESTED [%s] LINK [%d]\n", get_room_by_index(tab[index], info->rooms)->name, get_room_by_index(tab[index], info->rooms)->link_count);
		nb_link += get_room_by_index(tab[index], info->rooms)->link_count - 1;
		index++;
	}
//	printf("\tnb_link == %d\n\n",nb_link);
	if (!(next_tab = ft_memalloc(sizeof(int) * nb_link)))
		return (NULL);
	return (next_tab);
}
//
int set_id_room(t_info *info, int *tab, int turn, int id)
{
	t_link	new;
	int 	index;
	int		index_tab;
	int		index_next_tab;
	int		*next_tab;

//	printf("\n\t\t\t --------ENTER S.I.R\n");
	next_tab = NULL;
	if (!(next_tab = ft_malloc_next_tab(info, next_tab, tab)))
		return (-1);
//	printf("malloc\n");

	index_next_tab = 0;
	index_tab = 0;
	index = 0;

//	printf("LINK FROM[%s] TO[%s] - STATE{%d} - ID{%d} - TURN{%d}\n", new.from->name, new.to->name, new.state, id, new.id[id]);

	while (tab[index_tab] > -1)
	{
//		printf("BITE0\n");
		while (index < info->room_count)
		{
//			printf("BITE1\n");

			new = info->link_tab[tab[index_tab]][index];
			if (new.state > NONE)
			{
//				printf("--NEW INDEX ROOM == [%d] NAME == [%s] ID{%d} - TURN{%d}\n",new.to->index, new.to->name, id, new.id[id]);
				if ((new.id[id] == -1) && ft_strcmp(new.to->name, info->start->name))
				{
					info->link_tab[index][tab[index_tab]].id[id] = turn;
					new.id[id] = turn;
//					printf("2LINK FROM[%s] TO[%s] - STATE{%d} - ID{%d} - TURN{%d}\n", new.from->name, new.to->name, new.state, id, new.id[id]);
					if (ft_strcmp(new.to->name, info->end->name) != 0)
					{
						next_tab[index_next_tab++] = new.to->index;
//						printf("new tab == [%d]\n", next_tab[index_next_tab - 1]);
					}
				}

			}
			index++;



		}
		++index_tab;
		index = 0;
	}
	next_tab[index_next_tab] = -1;
	if (index_next_tab > 0)
		set_id_room(info, next_tab, turn + 1, id);
	free(next_tab);
	return (0);
}

int					ft_build_path(t_info *info, int index_start, t_path *path, int heat)
{
	int		index2;
	t_link	link;
	static int index_rooms;

	index_rooms++;
	index2 = 0;
//	printf("BUILD ON \n");
	while(index2 < info->room_count)
	{
		link = info->link_tab[index_start][index2];
		if (link.state > NONE && link.id[path->id_from_start] > -1 && link.id[path->id_from_start] < heat)
		{
//			printf("TEST == [%d] name == [%s]\n", index_rooms, link.to->name);
//			printf("PATH FROM[%s]=> TO[%s] IDP[%d]\n", link.from->name, link.to->name, path->id_path);
//			printf("\tROOM3 == [%s]\n", path->rooms[i_rooms - 1]->name);
			ft_build_path(info, index2, path, link.id[path->id_from_start]);
//			printf("TEST2 == [%d] name == [%s]\n", index_rooms, link.to->name);
			path->rooms[index_rooms] = link.to;
			if (link.to != info->start)
			{
				path->tab_bin_room[link.to->index] = 1;
				path->tab_index_room[heat - 2] = link.to->index;
//				printf("PATH FROM[%s]=> TO[%s] IDP[%d] NAMETO [%s][%d] index_room[%d][%d]\n", link.from->name, link.to->name, path->id_path,link.to->name,  link.to->index, heat - 2, path->tab_index_room[heat - 2]);
			}

			break;
//			printf("\tROOM3 == [%s]\n", path->rooms[i_rooms - 1]->name);
		}
		index2++;
	}
	index_rooms--;
	return (1);
}

void					ft_prepare_path(t_info *info, int index, t_link link, t_path *path)
{
	int			id_from_start;
	static int	id_path;
	int			heat;
	int			index_room;

	index_room = 0;
//	printf("PREPARE  PATH 1 \n");
	id_from_start = path->id_from_start;
	heat = link.id[id_from_start];
	path->length = heat - 1;
	path->id_path = id_path++;
	path->rooms[0] = link.to;
	path->tab_index_room[0] = link.to->index;
	path->tab_bin_room[link.to->index] = 1;
	if (ft_strcmp(link.to->name, info->start->name))
		ft_build_path(info, index, path, heat);
//	printf("PREPARE  PATH 3 \n");
	path->tab_index_room[heat - 1] = 0;
	path->rooms[heat] = NULL;
	info->max_path_count = id_path;
}

t_path					*ft_opti_new_path(t_info *info, t_path *path, int id_from_start, int heat)
{
	int static id;

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


int						ft_all_path(t_info *info, int end_index, int id_from_start, int index)
{
	t_path	*path;
	t_link link;

	path = NULL;
	while (id_from_start < MIN(SIZE_TAB, info->start->link_count))
	{
//		printf("ALLPATH1\n");
		while(index < info->room_count)
		{
//			printf("ALLPATH2\n");
			link = info->link_tab[end_index][index];
			if (link.state > NONE && link.id[id_from_start] > -1 && count_link(info, link.to) > 1)
			{
//				printf("ALLPATH3\n");
//				printf("TO == [%s]Heat[%d]\n",link.to->name, link.id[id_from_start]);
				path = ft_opti_new_path(info, path, id_from_start, link.id[id_from_start] + 2);
//				printf("ALLPATH4\n");
				ft_prepare_path(info, index, link, path);
//				printf("ALLPATH5\n");
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
	while (index_path < MIN(SIZE_TAB, info->start->link_count))
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

	//TEST LARGEUR
 unsigned long long int	**ft_pathfind(t_info *info, int start, int max_id_size)
{
	t_link	link;
	int		index;
	int		turn;
	int		id;
	int		*tab;

	if (!(tab = ft_memalloc(sizeof(int) * 2)))
			return (0);
	id = 0;
	index = 0;
	printf("PATHFINDING (SET ID)\n");
	while (index < info->room_count && id < max_id_size)
	{
		link = info->link_tab[start][index];
		if (link.state > NONE && count_link(info, link.to) > 1)
		{
			turn = 1;
//			printf("START PATH [%s]->[%s]\n", link.from->name, link.to->name);
			if (link.from == info->end)
				return (NULL);
			link.state = USED;
			info->link_tab[index][start].id[id] = turn;
			link.id[id] = turn;
//			printf("SET IN ROOM\n");
			tab[0] = index;
			tab[1] = -1;
			set_id_room(info, tab, ++turn, id);
//			printf("END SIROOM\n");
			++id;
		}
		index++;
	}
	free(tab);
	printf("\n\t\tstart ALL PATH\n");
	ft_all_path(info, info->end->index, 0, 0);
	printf("\n\t\tend PAHT\n");
//	ft_display_info(info);
//	ft_display_pat(info);
	return (NULL);
}
