/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 11:53:58 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 03:47:46 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		set_heat(t_room *room, int heat)
{
	int		index;
	int		childs;

	index = 0;
	childs = 0;
	while (index < room->link_count)
	{
		if (room->link[index]->heat == -1)
		{
			room->link[index]->heat = heat;
			childs++;
		}
		else if (room->link[index]->heat < heat &&
				room->heat < room->link[index]->heat)
			childs += set_heat(room->link[index], heat);
		index++;
	}
	return (childs);
}
