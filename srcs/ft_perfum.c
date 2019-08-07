/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_perfum.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 17:48:23 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 03:22:52 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				ft_perfum(t_room *room, char *s_name, char *e_name)
{
	int index;

	index = 0;
	room->perfum++;
	room->lock = 1;
	// on commence a Start
	// toutes les salles sont a parfum == 0
//	printf("BITE101\n");
	//printf("%s Perfum == %d, heat_min == %d, heat_max ==%d\n", room->name, room->perfum, room->heat_min, room->heat_max);
/*	
	while (room->link[index])
	{
		if (ft_strcmp(room->link[index]->name, s_name) != 0 &&
				ft_strcmp(room->link[index]->name, e_name) != 0 &&
				room->link[index]->lock == 0 &&
				(room->link[index]->heat_min <= room->heat_min))
		{
			ft_perfum(room->link[index], s_name, e_name);
		}
		index++;
	}
*/
	ft_putendl(room->name);
	while (room->link[index])
	{
		if (ft_strcmp(room->link[index]->name, s_name) != 0 &&
				ft_strcmp(room->link[index]->name, e_name) != 0 &&
				room->link[index]->lock == 0 &&
				(room->link[index]->heat_max >= room->heat_max))
		{
//			printf("TEST1\n");
			ft_perfum(room->link[index], s_name, e_name);
		}
//			printf("TEST2\n");

		index++;
	}
	ft_putendl("PERF end");

//	printf("TEST3\n");

	room->lock = 0;
	return (1);
}
