/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 01:12:02 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 01:25:40 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		add_room_into_path(t_path *apath, t_room *room)
{
	t_room	**rooms;
	int		index;

	if (!(rooms = ft_memalloc(sizeof(t_room*) * (apath->length + 1))))
		return (-1);
	index = 0;
	while (index < apath->length - 1)
	{
		rooms[index] = apath->rooms[index];
		index++;
	}
	rooms[index++] = room;
	rooms[index] = NULL;
	free(apath->rooms);
	apath->rooms = rooms;
	return (1);
}
