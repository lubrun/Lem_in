/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:53:58 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 13:32:42 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int ft_checkerror_heat_max(t_room *room, int heat)
{
	if (room->link_count == 1 && heat != 1)//cul de sac
	{
		room->heat_max = -2;
		room->heat_min = -2;
		return (-2);
	}
	if (room->heat_max == -2)
		return (0);
	room->lock = 1;
	return (1);
}

int ft_putheat_max(t_room *room, int heat, int h_min)
{
	int index;
	int count;

	index = h_min;
	index = 0;
	count = 0;
	while (room->link[index])
	{
		if (room->link[index]->heat_max != -2 &&
			room->link[index]->lock == 0)
			count++;
		index++;
		
	}
	if (count > 1 || heat == 0)
		heat++;
	if (room->heat_max == -1 || room->heat_max > heat)
		room->heat_max = heat;
	if (room->heat_min == -1 || room->heat_min > h_min)
		room->heat_min = h_min;

	if (count > 1)
		heat++;
	return (heat);
}


int		ft_heat_countable(t_room *room, int heat, char *s_name, char *e_name)
{
	if ((room->heat_max <= heat || room->heat_max == -2) &&
			ft_strcmp(room->name, s_name) != 0 && room->lock == 1 &&
			ft_strcmp(room->name, e_name) != 0)
		return (1);
	else
		return (0);
}

int		ft_putcount_heatmax(t_room *room, int heat, char *s_name, char *e_name, int h_min)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (room->link[index])
	{
		if ((room->link[index]->heat_max != -2 &&
			room->link[index]->lock == 0) &&
			ft_strcmp(room->link[index]->name, s_name) != 0)
		{
			if (set_heat_max(room->link[index], heat, s_name, e_name, h_min + 1) == -2)
			{
				if (set_heat_max(room, heat, s_name, e_name, h_min) == -2)
					return (-2);
				break;
			}
		}
		else if (ft_heat_countable(room->link[index], heat, s_name, e_name) == 1)
			count++;
		index++;
	}
	return (count);
}


int		set_heat_max(t_room *room, int heat, char *s_name, char *e_name, int h_min)
{
	int index;
	int count;


	if ((count = ft_checkerror_heat_max(room, heat)) <= 0)
		return (count);
	heat = ft_putheat_max(room, heat, h_min);
	index = 0;
	count = 0;
	if ((count = ft_putcount_heatmax(room, heat, s_name, e_name, h_min)) < 0)
		return (count);
	if (count >= room->link_count)
	{
		room->heat_max = -2;
		room->heat_min = -2;
		return (-2);
	}
//	fprintf(stderr, "name = %s heat_min = %d\n", room->name, room->heat_min);
	room->lock = 0;
	return (1);
}




int		set_heat(t_room *room, int heat, char *s_name, char *e_name)
{
	int		index;
	int count;

	count = 0;
	index = 0;

	room->lock = 1;
	if (room->link_count == 1 && heat != 1)//cul de sac
	{
		room->heat_min = -2;
		return (-2);
	}
	while (index < room->link_count)
	{
		if ((room->link[index]->heat_min == -1 ||
				room->link[index]->heat_min > heat) &&
				ft_strcmp(room->link[index]->name, s_name) != 0)
		{
			room->link[index]->heat_min = heat;
			if (set_heat(room->link[index], heat + 1, s_name, e_name) == -2)
			{
				if (set_heat(room, heat, s_name, e_name) == -2)
				{
					return (-2);
				}
				else
					break;
			}
		}
		else if ((room->link[index]->heat_min <= heat ||
				room->link[index]->heat_min == -2) &&
				ft_strcmp(room->link[index]->name, s_name) != 0 &&
				room->link[index]->lock == 1 &&
				ft_strcmp(room->link[index]->name, e_name) != 0)
			count++;
		if (ft_strcmp(room->link[index]->name, s_name) == 0 &&
				(room->link[index]->heat_min == -1 ||
				 room->link[index]->heat_min > heat))
			room->link[index]->heat_min = heat;
		index++;
	}
	if (count >= room->link_count)
	{
		room->heat_min = -2;
		return (-2);
	}
	room->lock = 0;
	return (1);
}
