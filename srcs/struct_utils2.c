/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 17:53:19 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 18:42:12 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**get_rooms_name(t_room *room)
{
	char	**tab;
	int		index;

	if (!(tab = ft_memalloc(sizeof(char*) * (get_room_count(room) + 1))))
		return (NULL);
	index = 0;
	while (room)
	{
		tab[index] = ft_strdup(room->name);
		index++;
		room = room->next;
	}
	tab[index] = NULL;
	return (tab);
}

t_room	*get_room_by_name(char *name, t_room *list)
{
	while (list)
	{
		if (ft_strcmp(name, list->name) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
