/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils5.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 18:53:59 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 16:16:09 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_malloc_pathfind(t_info *info, int **tab)
{
	int index;

	index = 0;
	if (!(info->tab_id_end = (malloc(sizeof(int) * (info->room_count + 1)))))
		return (0);
	if (!(*tab = (malloc(sizeof(int) * 2))))
		return (0);
	while (index++ < info->room_count)
		info->tab_id_end[index] = -1;
	return (1);
}

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
