/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 15:34:55 by qbarrier    ###    #+. /#+    ###.fr     */
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
		printf("MAX | TEST %s | HEAT_min %d | HEAT max %d\n", info.start->link[index]->name, info.start->link[index]->heat_min, info.start->link[index]->heat_max);
		if (max == -1 || info.start->link[index]->heat_min > max)
		{
			max = info.start->link[index]->heat_min;
			printf("save {%d}\n", max);
		}
		index++;
	}
	return (max + 1);
}

t_room	*next_room(t_room *room, char *s_name)
{
	int		index;
	t_room	*saved;
	t_room	*test;
	
	index = 0;
	saved = NULL;
	printf("FOR ROOM [%s]\n", room->name);

	
	while (index < room->link_count)
	{
		test = room->link[index];
		printf("TEST ROOM [%s] | HEAT_MIN %d | HEAT_MAX %d | PERFUME %d | LOCK %d\n", test->name, test->heat_min, test->heat_max, test->perfum, test->lock);	
		if (ft_strcmp(test->name, s_name) == 0)
		{
			printf("BUTE\n");
			return (test);
		}
		if (test->lock == 0 && !saved)
		{
			saved = test;
		}
		else if (test->lock == 0)
		{
//			printf("TEST2\n");
			if ((saved->perfum > test->perfum && test->perfum > 0) || (saved->perfum == 0 && test->perfum != 0))
				saved = test;
			else if (saved->perfum == test->perfum && test->heat_min < saved->heat_min)
				saved = test;
		}
//		printf("TEST3\n");
		index++;
	}
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
	path->length = 0;
	path->perfum = 0;
	if (info->path_count == info->max_path_count)
	{
		printf("Erf\n");
		path->id = -2;
		return (path);
	}
	
	room = info->start;
	while (ft_strcmp(room->name, info->end->name) != 0)
	{
		edit = 0;
		if (!(room = next_room(room, info->end->name)))
		{
			printf("BITE\n");
			return (NULL);
		}
		if ((edit = edit_path(path, &room, *info)) != 1)
		{
			path->id = edit;
			return (path);
		}
		else if (edit == -1)
			return (NULL);
		if (ft_strcmp(room->name, info->end->name) != 0)
		{
			room->lock = 1;
			path->perfum += room->perfum;
		}
		path->length++;
	}
	
/*	room = info->end;
	while (ft_strcmp(room->name, info->start->name) != 0)
	{
		edit = 0;
		if (!(room = next_room(room, info->start->name)))
		{
			printf("BITE\n");
			return (NULL);
		}
		if ((edit = edit_path(path, &room, *info)) != 1)
		{
			path->id = edit;
			return (path);
		}
		else if (edit == -1)
			return (NULL);
		if (ft_strcmp(room->name, info->start->name) != 0)
		{
			room->lock = 1;
			path->perfum += room->perfum;
		}
		path->length++;
	}

*/



	return (path);
}

t_path	**ft_pathfind(t_info *info)
{
	t_path	**paths;
	t_path	*path;
	int		count;

	paths = NULL;
	count = 0;
	info->end->heat_min = 0;
	info->end->heat_max = 0;

//	while (set_heat(info->end, ++count) != 0)
//		;
	set_heat(info->end, 1, info->start->name, info->end->name);

/////////// F heat max
	int index;
	index = 0;
	info->end->lock = 1;
	while(info->end->link[index])
		set_heat_max(info->end->link[index++], 0, info->start->name, info->end->name);
	info->end->lock = 0;
/////////
	info->max_path_len = get_max_path_len(*info) * 2;
	info->max_path_count = ft_get_min(info->start->link_count, info->end->link_count);
	info->shortest_path = get_shortest_path(info->start, info->end->name);
	if (!(paths = ft_memalloc(sizeof(t_path*) * (info->max_path_count + 1))))
		return (NULL);
	count = 0;
	while (info->start->link[count])
	{
		printf("count == %d\n", count);
		ft_perfum(info->end->link[count++], info->start->name, info->end->name);
		printf("ENDPARFUM\n");
	}
	while ((path = get_path(info)) && path->id >= 0)
		paths[info->path_count++] = path;
	if (!path)			//////////////
		return (paths);
	if (path->id == -2)
		return (paths);

	return (NULL);
}
