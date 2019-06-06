/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrun <lubrun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 10:44:36 by lubrun            #+#    #+#             */
/*   Updated: 2019/06/05 15:45:28 by lubrun           ###   ########.fr       */
/*                                                                            */
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

int		send_ant(t_info *info)
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
				//printf(" Z OBEUR ");
				path->rooms[0]->ant_id = ++info->ant;
				printf("L%d-%s ", info->ant, path->rooms[0]->name);
				//printf("<-- SENT (%d)", info->ant);
			}
			index++;
		}
		printf("\n");
	//	printf("|info->ant %d|erf %d|\n", info->ant, erf);
		erf++;
	}
	printf("%d tours\n", erf);
	return (1);
}

int		main(void)
{
	t_info	info;

	if (!(info = ft_pars()).rooms)
		return (0);
	//	printf("PARSE\n\n");
	if (!(info.paths = ft_pathfind(&info)))
		return (0);

	//	printf("PATHFINDING\n\n");
	info.shortest_path->ant_needed = 0;
	ft_ant_needed(info.shortest_path->length, 1, info.paths);
	sort_list(info.paths);
	send_ant(&info);
	return (1);
}
