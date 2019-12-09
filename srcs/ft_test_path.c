/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 16:39:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:03:25 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_test_path(t_path *path, t_group *group, t_info *info)
{
	int index;

	index = 0;
	while (group->tab[index] > -1)
	{
		if (info->matrice[path->id_path][group->tab[index]] == 0)
		{
			return (0);
		}
		index++;
	}
	group->tab[index] = path->id_path;
		return (1);
}

void		ft_turn_min(int ant, t_group *group)
{
	int turn;
//	int ant2;

//	ant2 = 0;
	turn = 0;
//	printf("group [len][nbpath] == [%d][%d] && anttotal = [%d]\n", group->total_len, group->nb_paths, ant);
//
/*
	while (ant2 < ant)
	{
		turn++;
		ant2 = (group->nb_paths * turn) - group->total_len;
//		printf("ANT == [%d]\n",ant);
	}
*/

	turn = (group->total_len + ant) / group->nb_paths;

//	printf ("turn == %d\n", turn);
	group->turn_min = turn;
}
