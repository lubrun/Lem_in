/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct_utils2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 14:29:29 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 12:00:51 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lem_in.h"

unsigned char	*create_turn_tab(void)
{
	unsigned char	*turn_tab;
	int				index;

	if (!(turn_tab = malloc(sizeof(unsigned char) * (SIZE_TAB + 1))))
		return (NULL);
	index = 0;
	while (index < SIZE_TAB)
		turn_tab[index++] = -1;
	turn_tab[index] = 0;
	return (turn_tab);
}

int				set_lastline_link(char *last_line, t_info *info)
{
	t_room	*from;
	t_room	*to;

	from = NULL;
	to = NULL;
	if (set_room(&from, &to, ft_strsplit(last_line, '-'), info) == 0)
		return (0);
	ft_putendl(last_line);
	if (!(info->link_tab[from->index][to->index] = create_turn_tab()) ||
			!(info->link_tab[to->index][from->index] = create_turn_tab()))
		return (-1);
	from->link_count++;
	to->link_count++;
	ft_strdel(&last_line);
	return (1);
}

int				create_room_tab(t_info *info)
{
	t_room	*elem;
	int		index;

	if (!(info->room_tab = ft_memalloc(sizeof(t_room *) *
					(info->room_count + 1))))
		return (0);
	elem = info->rooms;
	index = 0;
	while (index < info->room_count)
	{
		info->room_tab[index] = elem;
		elem = elem->next;
		index++;
	}
	info->room_tab[index] = NULL;
	return (1);
}

int				set_info(t_room *room, int *spec, t_info *info)
{
	if (*spec == 1)
	{
		if (!info->start)
			info->start = room;
		else
		{
			*spec = 0;
			return (-1);
		}
	}
	else if (*spec == 2)
	{
		if (!info->end)
			info->end = room;
		else
		{
			*spec = 0;
			return (-1);
		}
	}
	*spec = 0;
	return (1);
}
