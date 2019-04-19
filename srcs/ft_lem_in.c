/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:44:36 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 11:46:47 by lubrun      ###    #+. /#+    ###.fr     */
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
		printf("PATH %d - LEN %d\n", x, info.paths[x]->length);
		while (y < info.paths[x]->length)
		{
			printf("ROOM{%d} = %s\n", y, info.paths[x]->rooms[y]->name);
			y++;
		}
		x++;
	}
	x = 0;
	printf("SHORTEST - LEN %d\n", info.shortest_path->length);
	while (x < info.shortest_path->length)
	{
		printf("ROOM{%d} = %s\n", x, info.shortest_path->rooms[x]->name);
		x++;
	}
	return (1);
}
