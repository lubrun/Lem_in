/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newint_tab.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 14:51:40 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 14:51:42 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_newint_tab(int size, int value)
{
	int		*tab;
	int		index;

	if (!(tab = ft_memalloc(sizeof(int) * size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		tab[index] = value;
		index++;
	}
	return (tab);
}
