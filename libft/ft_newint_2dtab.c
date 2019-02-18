/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newint_2dtab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 16:48:12 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:09:32 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	**ft_newint_2dtab(int x, int y, int value)
{
	int **tab;
	int index;

	if (!(tab = ft_memalloc(sizeof(int *) * y)))
		return (NULL);
	index = 0;
	while (index < y)
	{
		tab[index] = ft_newint_tab(x, value);
		index++;
	}
	return (tab);
}
