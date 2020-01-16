/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_write_ant.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 18:04:48 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 18:15:20 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_write_ant(t_info *info)
{
	int index;

	info->lock = info->group->paths[info->group->nb_paths - 1]->length;
	while (info->ant_count > 0 && info->ant_count > info->lock)
	{
		index = 0;
		while (info->group->paths[index] && index < info->group->nb_paths)
		{
			printf("ANT == [%d]\n", info->ant_count);
			if (info->group->paths[index]->length < info->ant_count)
			{
		//		ft_printf_ant(info, info->group->paths[index]);
				info->ant_count--;
			}
			index++;
		}

	}
			printf("\tANT == [%d]\n", info->ant_count);
}
