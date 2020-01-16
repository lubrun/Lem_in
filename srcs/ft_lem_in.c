/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 09:59:49 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 19:07:22 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		send_all(t_info *info)
{
	int	count;

	count = 0;
	//printf("SEND ALL %d\n", info->ant_count);
	while (info->ant < info->ant_count)
		printf("L%d-%s ", ++info->ant, info->end->name);
}

void		move_ant(t_info *info)
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

int			ant_remains(t_info *info)
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

void		ft_display_paths(t_path **paths)
{
	int	index_path;
	int	index_room;

	index_room = 0;
	index_path = 0;
	printf("Display PATHS\n");
	while (paths[index_path])
	{
		while (paths[index_path]->rooms[index_room])
		{
			index_room++;
		}
		index_room = 0;
		index_path++;
	}
}

int			main(void)
{
	t_info	info;

	if (!(info = ft_pars()).rooms)
	{
		printf("ZOOB2\n");
		return (0);
	}
	if (!info.end)
		printf("BUG\n");
	printf("PARSE OK\n\n");
	if (!(ft_pathfind(&info, info.start->index,
					MIN(SIZE_TAB, info.start->link_count))))
	{
		printf("CHECK START NEIGHOUR\n");
	}
	printf("TRI START\n");
	ft_tri_paths(&info);
	printf("MATRICE\n");
	ft_paths_matrice(&info);
	printf("MATRICE OK, NOW OPTI IT\n");
	printf("ALGO START\n");
	ft_algo(&info);
	ft_tri_group(&info);
	ft_write_ant(&info);
	ft_free_all(&info);
	return (0);
}
