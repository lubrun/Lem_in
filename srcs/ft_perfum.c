/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_perfum.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 17:48:23 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 15:04:21 by qbarrier    ###    #+. /#+    ###.fr     */
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
	printf("%s Perfum == %d\n", room->name, room->perfum);
	
	while (room->link[index])
	{
		if (room->link[index]->heat <= room->heat &&
				ft_strcmp(room->link[index]->name, s_name) != 0 &&
				ft_strcmp(room->link[index]->name, e_name) != 0 &&
				room->link[index]->lock == 0)
		{
			ft_perfum(room->link[index], s_name, e_name);
		}
		index++;
	}
	room->lock = 0;
	return (1);
}
