/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:47:17 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 13:39:30 by qbarrier    ###    #+. /#+    ###.fr     */
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

t_room	*next_room(t_room *room, char *s_name)
{
	int		index;
	t_room	*saved;
	t_room	*test;
	
	index = 0;
	saved = NULL;
//	printf("\n");
	//printf("FOR ROOM [%s]\n", room->name);
//	ft_putendl("NextRoom Enter");
	while (index < room->link_count)
	{
		test = room->link[index];
//		printf("TEST ROOM [%s] | HEAT_MIN %d | HEAT_MAX %d | PERFUME %d | LOCK %d\n", test->name, test->heat_min, test->heat_max, test->perfum, test->lock);	
		/*
		 * Ajout Du If pour skip les cul de sacs depuis Start
		 */
//		printf("GP Room Name == %s LOCK ? %d perf == %d, H_min = %d\n", room->link[index]->name, room->link[index]->lock, room->link[index]->perfum, room->link[index]->heat_min);
		if (test->heat_min < 0 || test->heat_max == -1)
			index++;
		else
		{
			if (ft_strcmp(test->name, s_name) == 0)
			{
//				printf("NextRoom Sortie 1 NAME == %s\n\n", test->name);
				return (test);
			}
			if (test->lock == 0 && !saved)
			{
//				ft_putnbr(test->heat_min);
//				ft_putendl("NextRoom Save 1");
//				printf("NextRoom Save 1 NAME == %s\n", test->name);
				saved = test;
			}
			else if (test->lock == 0)
			{
	//			printf("TEST2\n");
				if ((saved->perfum > test->perfum && test->perfum > 0) || (saved->perfum <= 0 && test->perfum > 0))
				{
					printf("NextRoom Save 2 NAME == %s\n", test->name);
					saved = test;
				}
				else if (saved->perfum == test->perfum && test->heat_min < saved->heat_min) 
				{
//					printf("NextRoom Save 3 NAME == %s\n", test->name);
					saved = test;
				}
			}
	//		printf("TEST3\n");
			index++;
		}
	}
//	if (test->lock == 2 && !saved)
//		return (NULL);
//		printf("testname = %s\n",test->name);
//	printf("NextRoom Sortie 2 NAME == %s\n\n", saved->name);

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
	
	printf("GP ENTER\n\n");
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
			printf("GetPath NUll 1\n");
			return (NULL);
		}
//		printf("\n");
		if ((edit = edit_path(path, &room, *info)) != 1)
		{
			path->id = edit;
			return (path);
		}
		else if (edit == -1)
		{	
			printf("GetPath NUll 2\n");
			return (NULL);
		}
		if (ft_strcmp(room->name, info->end->name) != 0)
		{
			room->lock = 2;
			path->perfum += room->perfum;
		}
		path->length++;
	}

	return (path);
}




void	ft_test_lock(t_room *room, char *s_name, char *e_name)
{
	int index;

	index = 0;
	while (room->link[index])
	{
		if (room->link[index]->heat_max < 0 || room->link[index]->heat_min < 0 ||
				ft_strcmp(room->link[index]->name, s_name) == 0 ||
				ft_strcmp(room->link[index]->name, e_name) == 0)
		{	
			printf("TESTLOCK");

			index++;
		}
		else
		{
			printf("TESTLOCK Roomname == %s, Hmin == %d, Hmax == %d, Perf = %d, Lock = %d\n", room->link[index]->name, room->link[index]->heat_min, room->link[index]->heat_max, room->link[index]->perfum, room->link[index]->lock);
			if (room->link[index]->lock == 0)
			{
				room->link[index]->lock = 2;
				ft_test_lock(room->link[index], s_name, e_name);
			}
			index++;
		}
	}

}



t_path	**ft_pathfind(t_info *info)
{
//	ft_putendl("PATH0");
//	printf("PATHFINDING enter");
	t_path	**paths;
	t_path	*path;
	int		count;

	paths = NULL;
	count = 0;
	info->end->heat_min = 0;
	info->end->heat_max = 0;

//	while (set_heat(info->end, ++count) != 0)
//		;
//	set_heat(info->end, 1, info->start->name, info->end->name);

/////////// F heat max
	int index;
	index = 0;
	info->end->lock = 1;
//	ft_putendl("PATH1");
//	printf("BITE0\n");


//
	while(info->end->link[index])
	{
//		ft_putendl("PATH1.5");
//		printf("SET HEAT MAX\n");
		set_heat_max(info->end->link[index++], 0, info->start->name, info->end->name, 1);
	}
//	printf("BITE1\n");
//	ft_putendl("PATH2");
	info->end->lock = 0;
/////////
	info->max_path_len = get_max_path_len(*info) * 2;
	info->max_path_count = ft_get_min(info->start->link_count, info->end->link_count);
	info->shortest_path = get_shortest_path(info->start, info->end->name);
	
//	ft_putnbr(info->max_path_count);
	if (!(paths = ft_memalloc(sizeof(t_path*) * (info->max_path_count + 1))))
		return (NULL);
//	ft_putendl("PATH3");

	count = 0;
	while (info->end->link[count])
	{
		//printf("count == %d\n", count);
		ft_perfum(info->end->link[count++], info->start->name, info->end->name);
		//printf("ENDPARFUM\n");
	}
//ft_putendl("PATH4");
/*
	index = 0;
	while (info->start->link[index])
	{
		printf("START ROOM LINKED NAME = %s, Hmin = %d, Hmax = %d, perfum = %d\n", info->start->link[index]->name, info->start->link[index]->heat_min, info->start->link[index]->heat_max, info->start->link[index]->perfum);
		index++;
	}
*/
//	ft_test_lock(info->start, info->start->name, info->end->name);

	while ((path = get_path(info)) && path->id >= 0)
	{
		printf("ADD New Path\n");
		if (!path)
		{
			ft_putendl("NO PATH");
			break;

		}
		paths[info->path_count++] = path;
	}
//	ft_putendl("PATH5");

	if (!path)			//////////////
		return (paths);
	if (path->id == -2)
		return (paths);

	return (NULL);
}
