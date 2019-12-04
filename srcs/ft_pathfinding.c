/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:03:40 by qbarrier    ###    #+. /#+    ###.fr     */
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
/*
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
*/

int		*ft_pre_set_turn(t_info *info, int *tab, int turn)
{
	t_link	new;
	int 	index;
	int		index_tab;
	int		index_next_tab;

//	printf("\n\t\t\t --------ENTER S.I.R\n");
//	printf("malloc\n");

	index_next_tab = 0;
	index_tab = 0;
	index = 0;

//	printf("LINK FROM[%s] TO[%s] - STATE{%d} - ID{%d} - TURN{%d}\n", new.from->name, new.to->name, new.state, id, new.id[id]);

	while (tab[index_tab] > -1)
	{
//		printf("BITE0\n");
		if (get_room_by_index(tab[index_tab], info->rooms)->link_count == 2)
		{
			while (index < info->room_count)
			{
//				printf("BITE1\n");
				new = info->link_tab[tab[index_tab]][index];
				if (new.state > NONE)
				{	
//					printf("BITE2\n");
//					printf("--NEW INDEX ROOM == [%d] NAME == [%s] - TURN{%d}\n",new.to->index, new.to->name, new.turn);
					if ((new.to->heat_min == -1) && ft_strcmp(new.to->name, info->start->name))
					{
						if (new.to->link_count > 2)
						{
//							info->link_tab[index][tab[index_tab]].turn = turn + 1;
//							new.turn = turn + 1;
//							tab[index_tab] = new.to->index;
							index = 0;
//							printf("LINK FROM[%s] TO[%s] - STATE{%d} - TURN{%d}\n", new.from->name, new.to->name, new.state, new.turn);

							break;
						}
						new.to->heat_max =  new.from->heat_max + 1;
						new.to->heat_min = turn;
						tab[index_tab] = new.to->index;
//						printf("LINK FROM[%s] TO[%s] - STATE{%d} - TURN{%d}[%d]\n", new.from->name, new.to->name, new.state, new.to->heat_min, new.to->heat_max);
							index = -1;
					}
				}
				index++;
			}
			index = 0;
		}
		++index_tab;
	}
	return (tab);
}
int set_id_room(t_info *info, int *tab, int turn)
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
//				printf("--NEW INDEX ROOM == [%d] NAME == [%s] - TURN{%d}actuel[%d]\n",new.to->index, new.to->name,  new.to->heat_min, turn);
				if ((new.to->heat_min == -1) && ft_strcmp(new.to->name, info->start->name))
				{
					new.to->heat_max =  new.from->heat_max + 1;
					new.to->heat_min = turn;
//					printf("2LINK FROM[%s] TO[%s] - STATE{%d} - TURN{%d}[%d]\n", new.from->name, new.to->name, new.state, new.to->heat_min, new.to->heat_max);
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
		set_id_room(info, ft_pre_set_turn(info, next_tab, turn), turn + 1);
	free(next_tab);
	return (0);
}


int		*ft_pre_set_heuristique(t_info *info, int *tab, int turn)
{
	t_link	new;
	int 	index;
	int		index_tab;
	int		index_next_tab;

//	printf("\n\t\t\t --------ENTER S.I.R\n");
//	printf("malloc\n");

	index_next_tab = 0;
	index_tab = 0;
	index = 0;

//	printf("LINK FROM[%s] TO[%s] - STATE{%d} - ID{%d} - TURN{%d}\n", new.from->name, new.to->name, new.state, id, new.id[id]);

	while (tab[index_tab] > -1)
	{
//		printf("BITE0\n");
		if (get_room_by_index(tab[index_tab], info->rooms)->link_count == 2)
		{
			while (index < info->room_count)
			{
//				printf("BITE1\n");
				new = info->link_tab[tab[index_tab]][index];
				if (new.state > NONE)
				{	
//					printf("BITE2\n");
//					printf("--NEW INDEX ROOM == [%d] NAME == [%s] - TURN{%d}\n",new.to->index, new.to->name, new.turn);
					if ((new.to->heat_end_min == -1) && ft_strcmp(new.to->name, info->end->name))
					{
						if (new.to->link_count > 2)
						{
//							info->link_tab[index][tab[index_tab]].turn = turn + 1;
//							new.turn = turn + 1;
//							tab[index_tab] = new.to->index;
							index = 0;
//							printf("LINK FROM[%s] TO[%s] - STATE{%d} - TURN{%d}\n", new.from->name, new.to->name, new.state, new.turn);

							break;
						}
						new.to->heat_end_max =  new.from->heat_end_max + 1;
						new.to->heat_end_min = turn;
						new.to->heuristique_max = new.to->heat_end_max + new.to->heat_max;
						new.to->heuristique_min = new.to->heat_end_min + new.to->heat_min;
//					printf("LINK FROM[%s] TO[%s] - STATE{%d} - HERU{%d}[%d]\n", new.from->name, new.to->name, new.state, new.to->heuristique_min, new.to->heuristique_min);

						tab[index_tab] = new.to->index;
							index = -1;
					}
				}
				index++;
			}
			index = 0;
		}
		++index_tab;
	}
	return (tab);
}

int set_id_heuristique(t_info *info, int *tab, int turn)
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
//				printf("--NEW INDEX ROOM == [%d] NAME == [%s] - TURN{%d}actuel[%d]\n",new.to->index, new.to->name,  new.to->heat_min, turn);
				if ((new.to->heat_end_min == -1) && ft_strcmp(new.to->name, info->end->name))
				{
					new.to->heat_end_max =  new.from->heat_end_max + 1;
					new.to->heat_end_min = turn;
					new.to->heuristique_max = new.to->heat_end_max + new.to->heat_max;
					new.to->heuristique_min = new.to->heat_end_min + new.to->heat_min;
//					printf("2LINK FROM[%s] TO[%s] - STATE{%d} - HERU{%d}[%d]\n", new.from->name, new.to->name, new.state, new.to->heuristique_min, new.to->heuristique_min);


					if (ft_strcmp(new.to->name, info->start->name) != 0)
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
		set_id_heuristique(info, ft_pre_set_heuristique(info, next_tab, turn), turn + 1);
	free(next_tab);
	return (0);
}



t_path					*ft_opti_new_path(t_info *info, t_path *path, int id_from_start)
{
	int static id;

	if (!path || id_from_start != id)
	{
		id = id_from_start;
		path = new_path(info, id_from_start, 0, info->room_count);
		info->paths[id] = path;
	}
	else
	{
		path->next = new_path(info, id_from_start, 0, info->room_count);
		path = path->next;
	}
	return (path);

}


/*
t_path					*ft_build_path(t_info *info, int index_start, t_path *path, int lock)
{
	int		index2;
	t_link	link;
	t_path	*tmp;
	t_path **swap;
	static int index_rooms;

//	printf("BUILD ON \n");
	index_rooms++;
	swap = NULL;
	swap = &path;
	tmp = NULL;
	index2 = 0;
	while(index2 < info->room_count)
	{
		link = info->link_tab[index_start][index2];
		if (link.state > NONE && link.to->heuristique_min <= link.from->heuristique_min && link.to->lock != lock && link.to->heat_max < link.from->heat_max)
		{
			printf("TEST == [%d] name == [%s]\n", index_rooms, link.to->name);
//			printf("PATH FROM[%s]=> TO[%s] IDP[%d]\n", link.from->name, link.to->name, path->id_path);
//			printf("\tROOM3 == [%s]\n", path->rooms[i_rooms - 1]->name);
			link.to->lock = lock;
				printf("PATH FROM[%s]=> TO[%s] IDP[%d] NAMETO [%s][%d]\n", link.from->name, link.to->name, path->id_path, link.to->name, link.to->index);

//			printf("TEST2 == [%d] name == [%s]\n", index_rooms, link.to->name);
			if (link.to != info->start)
			{
				path->rooms[index_rooms] = link.to;
			printf("\tROOM3 == [%s]\n", path->rooms[index_rooms]->name);
				path->tab_bin_room[link.to->index] = 1;
				path->length++;
			}
			while(link.to->link_count > 2 && (index2 = ft_test_next_link(info, index_start, ++index2)) > 0)
			{
				printf("TEST LINK\n");
					while (path->next)
						path = path->next;
					tmp = ft_copy_path(info, tmp, path);
					path->next = ft_build_path(info, index2, tmp, lock);
					*path = **swap;
			}
			ft_build_path(info, index2, path, lock);
		}
		index2++;
	}
	index_rooms--;
	return (*swap);
}
*/
int						ft_test_next_link(t_info *info, int index_start, int index)
{
	t_link link;

	printf ("testlink\n");
	index++;
	while (index < info->room_count)
	{
		link = info->link_tab[index_start][index];
		if (link.state > NONE && link.to->heat_min < link.from->heat_min)
		{
			printf("TEST FROM[%s]TO[%s]--HEU[%d][%d]Heat[%d][%d]\n", link.from->name, link.to->name, link.from->heuristique_min, link.to->heuristique_min, link.from->heat_max, link.to->heat_max);
			return(index);
		}
		index++;
	}
	return (0);
}

t_path					*ft_copy_path(t_info *info, t_path *tmp, t_path *path)
{
	int index;

	index = 0;
	tmp = ft_opti_new_path(info, tmp, path->id_from_start);
	tmp->length = path->length;
	tmp->tab_bin_room = path->tab_bin_room;
	tmp->id_path = path->id_path + 1;
	while (index < info->room_count)
	{
		tmp->rooms[index] = path->rooms[index];
		index++;
	}
	return (tmp);
}

t_path					*ft_build_path(t_info *info, int index_start, t_path *path, int *tab)
{
	int index;
	t_link link;
	int	index_tab;

	index_tab = 0;
	index = 0;
	while (index < info->room_count)
	{
		link = info->link_tab[index_start][index];
		if (link.state > NONE && link.to->heuristique_min <= link.from->heuristique_min && link.to->lock == 0 && link.to->heat_max < link.from->heat_max)
		{
			if (link.to != info->start)
			{	
				link.to->lock = 1;
				while (tab[index_tab])
					index_tab++;
				tab[index_tab] = link.to->index;
			}
			else
			{
				index_tab = 0;
				while (tab[index_tab])
				{
					printf("RoomSaved [%s]\n", get_room_by_index(tab[index_tab], info->rooms)->name);
					index_tab++;
				}
				index_tab--;
				printf("-\n");
			}
			ft_build_path(info, index, path, tab);
			tab[index_tab] = 0;

/////////////////////////fT_SAVE_PATH

			while (link.from->link_count > 2 && (index = ft_test_next_link(info, index_start, index)) > 0)
	{
		printf("ROOM VOISINE [%s]\n", info->link_tab[index_start][index].to->name);
		tab[index_tab] = info->link_tab[index_start][index].to->index;
		ft_build_path(info, index, path, tab);
		///////////////////FT_SAVEPATH
		tab[index_tab] = 0;
	}
			link.to->lock = 0;
			break;
		}
		index++;
	}

	return(path);
}


int					ft_prepare_path(t_info *info, int index, t_link link, t_path *path)
{
	static int	id_path;
	int			index_room;
	int			*tab;

	if (!(tab = ft_memalloc(sizeof(int) * info->room_count)))
		return (0);
	index_room = 0;
//	printf("PREPARE  PATH 1 \n");
	path->id_path = id_path++;
	path->tab_bin_room[link.to->index] = 1;
	path->length++;
	path->rooms[0] = link.to;
	tab[0] = link.to->index;
	link.to->lock = 1;
	if (ft_strcmp(link.to->name, info->start->name))
		ft_build_path(info, index, path, tab);
	link.to->lock = 0;

	free(tab);
//	printf("PREPARE  PATH 3 \n");
	info->max_path_count = id_path;
	return (1);
}




int						ft_all_path(t_info *info, int end_index, int id_from_start, int index)
{
	t_path	*path;
	t_link link;

	path = NULL;
//		printf("ALLPATH1\n");
		while(index < info->room_count)
		{
//			printf("ALLPATH2\n");
			link = info->link_tab[end_index][index];
			if (link.state > NONE)
			{
//				printf("ALLPATH3\n");
//				printf("TO == [%s]Heat[%d]\n",link.to->name, link.id[id_from_start]);
				path = ft_opti_new_path(info, path, id_from_start);
//				printf("ALLPATH4\n");
				ft_prepare_path(info, index, link, path);
				id_from_start++;
//				printf("ALLPATH5\n");
			}
			index++;
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
		printf("----------FOR ID [%d]-----------\n", index_path);
		while (path)
		{
			printf("-IDP[%d]\n", path->id_path);
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


/*
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
	index = 0;
	printf("PATHFINDING (SET TURN)\n");
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
*/

unsigned long long int	**ft_pathfind(t_info *info, int start, int max_id_size)
{
	int		turn;
	int		*tab;
	int		a_supprimer;

	a_supprimer = max_id_size;
	if (!(tab = ft_memalloc(sizeof(int) * 2)))
			return (0);
	printf("PATHFINDING (SET TURN)\n");
	turn = 0;
//			printf("SET IN ROOM\n");
			tab[0] = start;
			tab[1] = -1;
	set_id_room(info, tab, ++turn);
	tab[0] = info->end->index;
	set_id_heuristique(info, tab, ++turn);
//			printf("END SIROOM\n");
	free(tab);
	printf("\n\t\tstart ALL PATH\n");
	ft_all_path(info, info->end->index, 0, 0);
	printf("\n\t\tend PAHT\n");
//	ft_display_info(info);
	ft_display_pat(info);
	return (NULL);
}

