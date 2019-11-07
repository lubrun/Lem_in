/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 16:39:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 17:27:15 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_test_path(t_path *path, t_group *group)
{
	int index_group;
	int index_path;
	int index_gp_room;
	
	index_group = 0;
//	printf("TEST P 0\n");
	while (group->paths[index_group])
	{
		index_gp_room = 1;
		while (group->paths[index_group]->rooms[index_gp_room + 1])
		{




			index_path = 1;
			while (path->rooms[index_path + 1])
			{
//				printf ("test GPROOM [%s] ET PROOM [%s}\n",group->paths[index_group]->rooms[index_gp_room]->name, path->rooms[index_path]->name);
				if (group->paths[index_group]->rooms[index_gp_room]->index == path->rooms[index_path]->index)
				{
//					printf("SAME ROOM\n");
					return(0);
				}
					index_path++;
			}









			index_gp_room++;
		}
		index_group++;
	}
//	printf("TEST OK\n");
	return (1);
}
