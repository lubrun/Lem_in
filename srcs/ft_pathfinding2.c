/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 15:12:52 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 09:50:59 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*get_shortest_path(t_room *start, char *end_str)
{
	t_path	*path;
	t_room	*room;
	
	ft_putendl("Pathfiding2");
	if (!(path = ft_memalloc(sizeof(t_path))))
	{
		ft_putendl("Get_shortPass Malloc error");
		return (NULL);
	}

	ft_bzero(path, sizeof(t_path));
	room = start;	

	while (ft_strcmp(room->name, end_str) != 0)
	{
		ft_putendl(room->name);
		ft_putnbr(room->heat_min);
		if (!(room = next_room(room, end_str)))
		{
			ft_putendl("Get_shortPass NUll 1");
			return (NULL);
		}
//		ft_putnbr(room->heat_min);	/////////
		if (path->length == 0)
		{


			if (!(path->rooms = ft_memalloc(sizeof(t_room *) * room->heat_min + 2)))
			{
//				ft_putnbr(room->heat_min);
				ft_putendl("Get_shortPass NUll 2");
				return (NULL);
			}
		}
		if (ft_strcmp(room->name, end_str) != 0)
		{

			path->perfum += room->perfum;
		}
		path->rooms[path->length++] = room;
//		printf("LOCK ? %d\n", path->rooms[path->length - 1]->lock);
	}

	return (path);
}
