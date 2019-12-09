/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_opti_matrice.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:53:40 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 15:36:13 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_compare_opti_matrice(int *matrice, int *swap_matrice, int index)
{
	while (index >= 0)
	{
		if (swap_matrice[index] == 1 && matrice[index] == 0)
			return (0);
		index--;
	}
	return (1);
}

int		ft_count_match(int *matrice, int stop)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (index <= stop)
	{
		if (matrice[index] == 1)
			count++;
		index++;
	}
	return (count);
}
void	ft_display(t_info *info, int *matrice)
{
	int index;

	index = 0;
	while (index < info->max_path_count)
	{
		printf("[%d]", matrice[index]);
		index++;
	}
	printf("\n");

}


void	ft_copy_tmp(t_info *info, int *swap, int *tmp, int stop)
{
	int index;

	index = 0;
	while (index < info->max_path_count)
	{
		if (index <= stop)
			tmp[index] = swap[index];
		else
			tmp[index] = 0;
		index++;
	}
}

int		*ft_make_matrice_great_again(t_info *info, int *matrice, int *swap_matrice, int **tmp)
{
	int	index;
	static int	count_match;
	int swap_count;

	index = info->lock;
	while (index < info->max_path_count)
	{
		if (matrice[index] == 1)
		{
			if (ft_compare_opti_matrice(info->matrice[index], swap_matrice, index - 1))
			{
				swap_matrice[index] = 1;
				if (count_match < (swap_count = ft_count_match(swap_matrice, index)))
				{

//					printf("SWAP\n");
//					ft_display(info, swap_matrice);
					count_match = swap_count;
					ft_copy_tmp(info, swap_matrice, *tmp, index);
//					printf("TMP count == [%d]\n", count_match);
//					ft_display(info, *tmp);
				}
				info->lock = index + 1;
				*tmp = ft_make_matrice_great_again(info, matrice, swap_matrice, tmp);
				swap_matrice[index] = 0;
			}
			else
				swap_matrice[index] = 0;
		}
		index++;
	}
	return (*tmp);
}



void	ft_opti_matrice(t_info *info)
{
	int		index;
	int		*tmp;
	int		*swap;

	swap = ft_memalloc(sizeof(int) * (info->max_path_count + 1));
	tmp = ft_memalloc(sizeof(int) * (info->max_path_count + 1));
	index = 0;
	while (index < info->max_path_count)
	{
		info->lock = 0;
		printf("FOR I [%d]\n", index);
//		ft_display(info, info->matrice[index]);
		info->matrice[index] = ft_make_matrice_great_again(info, info->matrice[index], swap, &tmp);
		ft_display(info, info->matrice[index]);
		index++;
		
	}

}
