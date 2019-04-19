/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ant_needed.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 16:06:27 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 16:57:14 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_ant_needed(int len_before, int nomber_path ,t_path **list)
{
	int min_len;
	int swap_index;
	int index;

	index = 0;
	swap_index = -1;
	min_len = 2147483647;
	while (list[index])	// cherche + petit chemin
	{
//		printf("BITE1\n");
		if (list[index]->length <= min_len && list[index]->ant_needed == -1)
		{
//			printf("BITE2\n");
			min_len = list[index]->length;
			swap_index = index;
		}
		index++;
	}
	if (swap_index != -1)
	{
		list[swap_index]->ant_needed =
			(list[swap_index]->length * nomber_path) - (len_before);	
		ft_ant_needed(len_before + list[swap_index]->length,
				nomber_path + 1, list);
	}
}
