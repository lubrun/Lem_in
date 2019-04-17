/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:44:36 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 14:41:42 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_info	info;
	if (!(info = ft_pars()).rooms)
		return (0);
	if (!(info.paths = ft_pathfind(&info)))
		return (0);
	int x = 0;
	int y = 0;

	while (x < info.path_count)
	{
		y = 0;
		printf("PATH %d\n", x);
		while (y < info.paths[x]->length)
		{
			printf("ROOM{%d} = %s\n", y, info.paths[x]->rooms[y]->name);
			y++;
		}
		x++;
	}
	return (1);
}
