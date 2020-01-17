/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils5.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 18:53:59 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 19:03:04 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_groupcpy(t_group **tmp, t_group *group)
{
	int	index;

	index = 0;
	(*tmp)->turn_min = group->turn_min;
	(*tmp)->total_len = group->total_len;
	(*tmp)->nb_paths = group->nb_paths;
	while (group->paths[index])
	{
		(*tmp)->paths[index] = group->paths[index];
		index++;
	}
	return (group->turn_min);
}

int			ft_min(int a, int b)
{
	return (a < b ? a : b);
}
