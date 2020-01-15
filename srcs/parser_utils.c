/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 16:18:12 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 19:07:31 by qbarrier    ###    #+. /#+    ###.fr     */
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

int			link_exist(int from, int to, t_info *info)
{
	return (info->link_tab[from][to].state > NONE ||
		info->link_tab[from][to].state > NONE ? 1 : 0);
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

t_room		*get_room_by_index(int index, t_room *list)
{
	while (list)
	{
		if (index == list->index)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int			add_link(char *last_line, t_info *info)
{
	char	*line;
	t_room	*from;
	t_room	*to;

	if (!create_link_tab(info) ||
		set_lastline_link(last_line, info) == 0)
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] != '#')
		{
			if (set_room(&from, &to, ft_strsplit(line, '-'), info) == 0)
				return (-1);
			from->link_count++;
			info->link_tab[from->index][to->index] =
				(t_link) {NULL, from, to, NOT_USED, create_id(), -1};
			to->link_count++;
			info->link_tab[to->index][from->index] =
				(t_link) {NULL, to, from, NOT_USED, create_id(), -1};
			ft_strdel(&line);
		}
	}
	return (1);
}
