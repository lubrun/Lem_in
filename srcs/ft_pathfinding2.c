/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 15:12:52 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 17:10:47 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*get_shortest_path(t_room *start, char *end_str)
{
	t_path	*path;
	t_room	*room;
	
	if (!(path = ft_memalloc(sizeof(t_path))))
		return (NULL);
	ft_bzero(path, sizeof(t_path));
	room = start;
	while (ft_strcmp(room->name, end_str) != 0)
	{
		if (!(room = next_room(room, end_str)))
			return (NULL);
		if (path->length == 0)
		{
			if (!(path->rooms = ft_memalloc(sizeof(t_room *) * room->heat_min + 2)))
				return (NULL);
		}
		if (ft_strcmp(room->name, end_str) != 0)
			path->perfum += room->perfum;
		path->rooms[path->length++] = room;
	}
	return (path);
}
