/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 03:56:12 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_max_path_len(t_info info)
{
	int		index;
	int		max;

	index = 0;
	max = -1;
	while (index < info.start->link_count)
	{
		printf("CHECK LEN{%s -> %d}\n", info.start->link[index]->name, info.start->link[index]->heat);
		if (max == -1 || info.start->link[index]->heat > max)
			max = info.start->link[index]->heat;
		index++;
	}
	return ((int)(max * 1.5));
}

t_room	*next_room(t_room *room, int *lock)
{
	int		index;
	int		min;

	index = 0;
	min = -1;
	while (index < room->link_count)
	{
		if (min == -1 || min < room->link[index]->heat)
			if (*lock == 1 && room->link[index]->lock == 0)
				min = index;
		index++;
	}
	return (room->link[min]);
}

int		edit_path(t_path *apath, t_room *room, t_info info)
{
	if (apath->length == 0)
	{
		if (!(apath->rooms = ft_memalloc(sizeof(t_room*) * 2)))
			return (-1);
		apath->rooms[0] = room;
	}
	else
	{
		if (apath->length + 1 == info.max_path_len)
			return (2);
		if (add_room_into_path(apath, room) == -1)
			return (-1);
	}
	return (1);
}

int		get_path(int *lock, t_info *info, t_path *paths)
{
	t_room	*room;
	t_path	path;
	int		edit;

	if (info->path_count == info->max_path_count)
		return (0);
	room = info->start;
	path = (t_path){.rooms = NULL, .length = 0};
	while (ft_strcmp(room->name, info->end->name) != 0)
	{
		printf("%s|%s\n", room->name, info->end->name);
		edit = 0;
		room = next_room(room, lock);
		if ((edit = edit_path(&path, room, *info)) == -1)
			return (-1);
		else if (edit == 2)
		{
			info->path_count--;
			return (1);
		}
	}
	paths[info->path_count] = path;
	return (1);
}

t_path	*ft_pathfind(t_info *info)
{
	t_path	*path;
	t_room	*room;
	int		lock;
	int		count;

	path = NULL;
	lock = 1;
	count = -1;
	if (!(path = ft_memalloc(sizeof(t_path) * (info->max_path_count + 1))))
		return (NULL);
	info->end->heat = 0;
	while (set_heat(info->end, ++count) != 0)
		;
	room = info->rooms;
	while (room)
	{
		printf("{%s}{%d}\n", room->name, room->heat);
		room = room->next;
	}
/*	info->max_path_len = get_max_path_len(*info);
	info->max_path_count = ft_get_min(info->start->link_count, info->end->link_count) * 2;
	//while (get_path(&lock, info) == 1)
	if (get_path(&lock, info, path) == 1)
		info->path_count++;*/
	return (path);
}
