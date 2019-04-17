/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 15:05:00 by qbarrier    ###    #+. /#+    ###.fr     */
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
		if (max == -1 || info.start->link[index]->heat > max)
			max = info.start->link[index]->heat;
		index++;
	}
	return (max + 1);
}

t_room	*next_room(t_room *room, t_info info)
{
	int		index;
	t_room	*saved;

	index = 0;
	saved = NULL;
	printf("FOR ROOM [%s]\n", room->name);
	while (index < room->link_count)
	{
		printf("TEST ROOM [%s] | HEAT %d | LOCK %d\n", room->link[index]->name, room->link[index]->heat, room->link[index]->lock);
		if (info.lock == 0)
		{
			if (!saved || saved->heat > room->link[index]->heat)
				saved = room->link[index];
		}
		else
		{
			if ((!saved || saved->heat > room->link[index]->heat) && room->link[index]->lock == 0)
				saved = room->link[index];
		}
		index++;
	}
	if (saved)
		printf("SAVED [%s]\n", saved->name);
	return (saved);
}

int		edit_path(t_path *apath, t_room **aroom, t_info info)
{
	if (apath->length == 0)
	{
		if (!(apath->rooms = ft_memalloc(sizeof(t_room*) * 2)))
			return (-1);
		apath->rooms[0] = *aroom;
	}
	else
	{
		if (apath->length + 1 > info.max_path_len)
			return (-3);
		if (add_room_into_path(apath, aroom) == -1)
			return (-1);
	}
	return (1);
}

t_path		*get_path(t_info *info)
{
	t_room	*room;
	t_path	*path;
	int		edit;

	if (!(path = new_path(*info)))
		return (NULL);
	if (info->path_count == info->max_path_count)
	{
		path->id = -2;
		return (path);
	}
	room = info->start;
	while (ft_strcmp(room->name, info->end->name) != 0)
	{
		edit = 0;
		if (ft_strcmp((room = next_room(room, *info))->name, info->end->name) == 0)
			return (path);
		if ((edit = edit_path(path, &room, *info)) != 1)
		{
			path->id = edit;
			return (path);
		}
		room->lock = 1;
		path->length++;
	}
	return (path);
}

t_path	**ft_pathfind(t_info *info)
{
	t_path	**paths;
	t_path	*path;
	int		count;

	paths = NULL;
	count = 0;
	if (!(paths = ft_memalloc(sizeof(t_path*) * (info->max_path_count + 1))))
		return (NULL);
	info->end->heat = 0;
////	printf("BITE1\n");
	while (set_heat(info->end, ++count) != 0)
		;
	////////// 
////	printf("BITE2\n");

	int index;

	index = 0;
	while (info->start->link[index])
		ft_perfum(info->start->link[index++], info->start->name, info->end->name);
	printf("BITE3\n");
	//////////////
	info->max_path_len = get_max_path_len(*info);
	info->max_path_count = ft_get_min(info->start->link_count, info->end->link_count);
	while ((path = get_path(info)) && path->id >= 0)
		paths[info->path_count++] = path;
	if (path->id == -2)
		return (paths);
	return (NULL);
}
