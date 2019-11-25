/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 14:29:05 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 15:35:22 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int  add_room_back(t_room **first, t_room *elem)
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

static int	check_error(char **info, t_room *room)
{
    t_room  *tested;
	int		tab_len;
	
	if ((tested = get_room_by_name(info[0], room)))
	{
		tested->coord = ft_newpoint_2(ft_atoi(info[1]), ft_atoi(info[2]));
		ft_2dstrdel(&info);
		return (0);
	}
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

int		    add_room(t_room **aroom, char *line, int *spec, t_info *info)
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
