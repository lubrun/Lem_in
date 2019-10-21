/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 18:21:52 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 15:35:44 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_room_count(t_room *room)
{
	int		count;

	if (!room)
		return (0);
	count = 1;
	while (room->next)
	{
		room = room->next;
		count++;
	}
	return (count);
}

int		check_error(char **info, t_room *room)
{
	char	**rooms;
	int		tab_len;
	
	rooms = get_rooms_name(room);
	if (ft_2dcontains(rooms, info[0]))
	{
		get_room_by_name(info[0], room)->coord =
		ft_newcoord(ft_atoi(info[1]), ft_atoi(info[2]));
		ft_2dstrdel(&info);
		ft_2dstrdel(&rooms);
		return (0);
	}
	ft_2dstrdel(&rooms);
	if ((tab_len = ft_tablenstr(info)) != 3)
	{
		if (tab_len == 1 && ft_index(info[0], '-') != -1)
		{
			ft_2dstrdel(&info);
			return (2);
		}
		ft_2dstrdel(&info);
		return (-1);
	}
	ft_2dstrdel(&info);
	return (1);
}

t_room	*new_room(char **room_info, int *spec, t_info *info)
{
	t_room	*new;

	if (!(new = ft_memalloc(sizeof(t_room))) || !room_info ||
		!room_info[0] || !room_info[1] || !room_info[2])
		return (NULL);
	new->next = NULL;
	new->link = NULL;
	new->link_count = 0;
	new->ant_id = -1;
	new->name = ft_strdup(room_info[0]);
	new->coord = ft_newcoord(ft_atoi(room_info[1]), ft_atoi(room_info[2]));
	new->spec = *spec;
	new->heat_min = -1;
	new->heat_max = -1;
	new->lock = 0;
	new->perfum = 0;
	new->tour = 0;	////////
	new->shortest = 0;	/////////////
	ft_2dstrdel(&room_info);
	if (set_info(new, spec, info) == -1)
		return (NULL);
	return (new);
}

int		add_room_back(t_room **first, t_room *elem)
{
	t_room *list;

	if (!*first || !elem)
		return (-1);
	list = *first;
	while (list->next)
		list = list->next;
	list->next = elem;
	return (1);
}

int		add_room(t_room **aroom, char *line, int *spec, t_info *info)
{
	t_room	*room;
	int		check;

	check = 0;
	if (line[0] == '#')
		return ((*spec != 0) ? -1 : 0);
	if ((check = check_error(ft_strsplit(line, ' '), *aroom)) == -1)
		return (-1);
	else if (check == 0)
		return (1);
	else if (check == 2)
		return (2);
	if (!*aroom)
	{
		if (!(*aroom = new_room(ft_strsplit(line, ' '), spec, info)))
			return (-1);
		(*aroom)->index = info->room_count;
	}
	else
	{
		if (!(room = new_room(ft_strsplit(line, ' '), spec, info)))
			return -1;
		else
			add_room_back(aroom, room);
		room->index = info->room_count;
	}
	info->room_count++;
	return (1);
}
