/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 16:18:12 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 14:45:40 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**get_rooms_name(t_room *room)
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

t_room		*get_room_link_by_name(char *name, t_room *room)
{
	int	index;

	index = 0;
	while (index < room->link_count)
	{
		if (ft_strcmp(room->link[index]->name, name) == 0)
			return (room->link[index]);
		index++;
	}
	return (NULL);
}

t_room		*get_room_by_name(char *name, t_room *list)
{
	while (list)
	{
		if (ft_strcmp(name, list->name) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int			add_link(char *last_line, t_room *room)
{
	char	*line;
	t_room	*from;
	t_room	*to;

	if (set_lastline_link(last_line, room) == 0)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (set_room(&from, &to, room, ft_strsplit(line, '-')) == 0)
			break;
		ft_putendl(line);
		from->link_count++;
		insert_link(from, to);
		to->link_count++;
		insert_link(to, from);
		ft_strdel(&line);
	}
	return (1);
}
