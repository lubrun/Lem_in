/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 16:39:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 17:29:17 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_test_path(t_path *path, t_group *group, t_info *info)
{
	int	index;

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

void	ft_turn_min(int ant, t_group *group)
{
	int	turn;

	turn = 0;
	turn = (((group->total_len + ant) / (float)group->nb_paths) + 0.99);
	group->turn_min = turn;
}
