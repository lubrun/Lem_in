/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 16:18:12 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 16:47:08 by qbarrier    ###    #+. /#+    ###.fr     */
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
//	ft_putendl("GetRoomByName Enter");
	while (list)
	{
//		ft_putendl("GRBN while");
//		printf("name == |%s| listname == |%s|\n", name, list->name);
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
	{
	//	ft_putendl("Retour -1 addlink");
		return (-1);// retour -1 au lieu de 0
	}
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] != '#')//	passer les commentaires
		{
			if (set_room(&from, &to, room, ft_strsplit(line, '-')) == 0)
				return(-1);		/////// j'ai remplace le break
//			ft_putendl(line);
			from->link_count++;
			insert_link(from, to);
			to->link_count++;
			insert_link(to, from);
			ft_strdel(&line);
		}
	}
	return (1);
}
