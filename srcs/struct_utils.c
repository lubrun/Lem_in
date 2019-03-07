/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struc_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 18:21:52 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/05 14:48:09 by lubrun      ###    #+. /#+    ###.fr     */
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
	
	rooms = get_rooms_name(room);
	if (ft_2dcontains(rooms, info[0]))
	{
		get_room_by_name(info[0], room)->coord = ft_newcoord(ft_atoi(info[1]), ft_atoi(info[2]));
		ft_2dstrdel(&info);
		return (0);
	}
	printf("|%zu|\n", ft_tablenstr(info));
	if (ft_tablenstr(info) != 3)
		return (-1);
	printf("ERF\n");
	return (1);
}

t_room	*new_room(char **info, int *spec)
{
	t_room	*new;

	if (!(new = ft_memalloc(sizeof(t_room))) || !info ||
		!info[0] || !info[1] || !info[2])
		return (NULL);
	new->next = NULL;
	new->link = NULL;
	new->name = ft_strdup(info[0]);
	new->coord = ft_newcoord(ft_atoi(info[1]), ft_atoi(info[2]));
	new->spec = *spec;
	*spec = 0;
	ft_2dstrdel(&info);
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

int		add_room(t_room **aroom, char *line, int *spec)
{
	int check;

	check = 0;
	if (line[0] == '#')
		return (0);
	if ((check = check_error(ft_strsplit(line, ' '), *aroom)) == -1)
		return (-1);
	else if (check == 0)
		return (1);
	if (!*aroom)
		*aroom = new_room(ft_strsplit(line, ' '), spec);
	else
		add_room_back(aroom, new_room(ft_strsplit(line, ' '), spec));
	return (1);
}
