/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 09:59:49 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 16:59:08 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	send_all(t_info *info)
{
	int	count;

	count = 0;
	//printf("SEND ALL %d\n", info->ant_count);
	while (info->ant < info->ant_count)
		printf("L%d-%s ", ++info->ant, info->end->name);
}

void	move_ant(t_info *info)
{
	t_room	*room;
	t_path	*path;
	int		room_i;
	int		path_i;

	path_i = 0;
//	printf("MOVE START\n");
	while (info->paths[path_i])
	{
		path = info->paths[path_i];
		room_i = path->length - 2;
		while (room_i >= 0)
		{
			room = path->rooms[room_i];
//			printf(" ROOM TESTED [%s] (%d) ", room->name, room->ant_id);
			if (room->ant_id != -1)
			{
				if (room_i == path->length - 2)
					printf("L%d-%s ", room->ant_id, info->end->name);
				else
					printf("L%d-%s ", room->ant_id, path->rooms[room_i + 1]->name);
				path->rooms[room_i + 1]->ant_id = room->ant_id; 
				room->ant_id = -1;
			}
			room_i--;
		}	
		path_i++;
	}
}

int		ant_remains(t_info *info)
{
	t_room	*room;
	t_path	*path;
	int		room_i;
	int		path_i;

	path_i = 0;
	while (path_i < info->path_count)
	{
		path = info->paths[path_i];
		room_i = path->length - 2;
		while (path->rooms[room_i] && room_i >= 0)
		{
			room = path->rooms[room_i];
			if (room->ant_id != -1)
				return (1);
			room_i--;
		}
		path_i++;
	}
	return (0);
}

/*

int		send_ant(t_info *info, int min_ant, t_path *s_path)
{
	t_path	*path;
	int		index;
	int		count;
	int		erf;
	
	count = 0;
	erf = 0;
	while ((info->ant < info->ant_count || ant_remains(info) == 1))
	{
		move_ant(info);
		index = 0;
		while (info->paths[index])
		{
			path = info->paths[index];
			//printf("info->ant %d || ant_count %d || needed %d\n", info->ant, info->ant_count, path->ant_needed);
			//printf("LAST ROOM [%s] IN PATH [%d]\n", path->rooms[path->length - 1]->name, index);
			//printf("LEN %d - ANT %d - FIRST %s\n", path->length, path->ant_needed, path->rooms[0]->name);
			//printf("PATH %d -> ANT NEEDED %d | ANT %d\n", index, path->ant_needed, info->ant);
			if (ft_strcmp(path->rooms[0]->name, info->end->name) == 0)
			{
				send_all(info);
				info->ant = info->ant_count;
				break ;
			}
			else if (info->ant_count - info->ant >= path->ant_needed &&
			path->rooms[0]->ant_id == -1 && info->ant < info->ant_count)
			{
				//printf("tour ant qui reste = %d\n", path->ant_needed);
				//printf(" Z OBEUR ");
				path->rooms[0]->ant_id = ++info->ant;
				printf("L%d-%s ", info->ant, path->rooms[0]->name);
				//printf("<-- SENT (%d)", info->ant);
			}
			index++;
		}
///////////////////////////////////////////////

		if (min_ant > 1 && min_ant > (info->ant_count - info->ant))
		{
			printf("Shor LEN = %d, Ant restant? = %d\n", s_path->length, (info->ant_count - info->ant));
			return (1);

			/////////// AJOUTER FONCTION POUR ENVOYER LES ANT DEPUIS SHORTED ????
			/////////  MAIS JE PENSE AUE LES FOURMIS VONT SE CHEVAUCHER
		}


//////////////////////////////////////////

		printf("\n");
	//	printf("|info->ant %d|erf %d|\n", info->ant, erf);
		erf++;
	}
	printf("%d tours\n", erf);
	return (1);
}

*/

void ft_display_paths(t_path **paths)
{
	int index_path;
	int index_room;

	index_room = 0;
	index_path = 0;
	printf("Display PATHS\n");
	while (paths[index_path])
	{
//		printf("Path Id == %d, Path length = =%d Path perf == %d, Path Antneed == %d\n", paths[index_path]->id, paths[index_path]->length, paths[index_path]->perfum, paths[index_path]->ant_needed);
		while (paths[index_path]->rooms[index_room])
		{
			index_room++;
		}
		index_room = 0;
		index_path++;
	}

}

void ft_display_Shorted_paths(t_path *paths)
{
	int index;

	index = 0;
	printf("Display SPATHS\n");

//		printf("SPath length = =%d SPath perf == %d, SPath Antneed == %d\n", paths->length, paths->perfum, paths->ant_needed);
	while (index < paths->length)
	{
		printf("RoomName = %s, RoomHeat_min == %d, RoomHeatMax == %d, lock == %d tour == %d\n",paths->rooms[index]->name, paths->rooms[index]->heat_min, paths->rooms[index]->heat_max, paths->rooms[index]->lock, paths->rooms[index]->tour);
		index++;
	}
	}




int		main(void)
{
	t_info	info;



	if (!(info = ft_pars()).rooms)
	{
		printf("ZOOB2\n");
		return (0);
	}
	if (!info.end)
		printf("BUG\n");
//////////


///////////
		printf("PARSE OK\n\n");
	if (!(ft_pathfind(&info, info.start->index, MIN(SIZE_TAB, info.start->link_count))))
	{
		printf("CHECK START NEIGHOUR\n");
//		return (0);
	}
//	printf("DEL PATH\n");
//	ft_del_path(&info);
//	ft_heuristique(&info, info.end->index, MIN(SIZE_TAB, info.start->link_count));
	printf("TRI START\n");
	ft_tri_paths(&info);
	ft_paths_matrice(&info);
	printf("MATRICE OK, NOW OPTI IT\n");
//	ft_opti_matrice(&info);
	printf("ALGO START\n");

	ft_algo(&info);
	printf("info->maxPathlen{%d]\n", info.max_path_len);
	ft_free_all(&info);

	return (0);
//ft_putendl("AllPath");


/*
		printf("PATHFINDING OK\n\n");
	info.shortest_path->ant_needed = 0;
	ft_putendl("Shortedpath");

	int min_ant;

	min_ant = ft_ant_needed(info.shortest_path->length, 1, info.paths, -1);
	ft_putendl("Antneeded end");

	printf("\n------------MIN ANT == %d LEN FIRST == %d\n", min_ant, info.paths[0]->length);
////////	if (min_ant > 1)
	{
		index = 0;
		while (info.paths[index])
		{
			info.paths[index]->ant_needed = -1;
			index++;
		}
		index--;
		ft_ant_needed(info.paths[index]->length, 1, info.paths, -1);

	}
///////////
	sort_list(info.paths);
	ft_parse_tour_shortest(&info);

	ft_display_paths(info.paths);
	ft_display_Shorted_paths(info.shortest_path);

	send_ant(&info, min_ant, info.shortest_path);
*/

	return (1);
}
