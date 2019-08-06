/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:53:58 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 01:49:24 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		set_heat_max(t_room *room, int heat, char *s_name)
{
	int index;
	int count;

	count = 0;
	index = 0;
	//printf ("roomNAME == %s heat == %d HMax == %d\n", room->name, heat, room->heat_max);
//	ft_putendl("HEAT0");
	if (room->heat_min == -2)
		return (0);
	room->lock = 1;
	while (room->link[index])
	{
		if (room->link[index]->heat_min != -2 &&
			room->link[index]->lock != 1)
			count++;
		index++;
	}	
	if (count > 1 || heat == 0)
		heat++;
	if (room->heat_max == -1 || room->heat_max > heat)
		room->heat_max = heat;
	if (count > 1)
		heat++;
	index = 0;
	while (room->link[index])
	{
		if ((room->link[index]->heat_min != -2 &&
			room->link[index]->lock == 0) &&
			ft_strcmp(room->link[index]->name, s_name) != 0)
			set_heat_max(room->link[index], heat, s_name);
		index++;
	}
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
//	printf("link_count == %d\n",room->link_count);
	if (room->link_count == 1 && heat != 1)
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
					return (-2);
				else
					break;
			}
		}
		else if ((room->link[index]->heat_min <= heat ||
				room->link[index]->heat_min == -2) &&
				ft_strcmp(room->link[index]->name, s_name) != 0 &&
				room->link[index]->lock == 1 &&
				ft_strcmp(room->link[index]->name, e_name) != 0)
			count++;;
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







	/*
	while (index < room->link_count)
	{
//		if (room->link[index]->heat_max < heat)
//			room->link[index]->heat_max = heat;
		if (room->link[index]->heat_min == -1)
		{
			room->link[index]->heat_min = heat;
			childs++;
		}
		else if (room->link[index]->heat_min < heat &&
				room->heat_min < room->link[index]->heat_min)
			childs += set_heat(room->link[index], heat);
		index++;
	}
//	printf("CHILD = %d\n\n", childs);
	return (childs);
	*/

