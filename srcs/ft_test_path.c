/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 16:39:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 21:34:36 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_test_path(t_path *path, t_group *group, t_info *info)
{
//	printf("-------\n");
	int index;

	index = 0;
//	printf("FOR ID P [%d]\n", path->id_path);

	while (group->tab[index] > -1)
	{
//		printf("TEST ID P [%d]", group->tab[index]);
		if (info->matrice[path->id_path][group->tab[index]] == 0)
		{
//			printf("\nOUT\n");
			return (0);
		}
		index++;
	}
//	printf("\nOK\n");
	group->tab[index] = path->id_path;
//		printf("TEST OK\n");
		return (1);
}
