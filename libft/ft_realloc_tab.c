/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 20:33:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 21:02:27 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_tab(char **tab, int addi, int addj, int c)
{
	char	**tap;
	int		i;
	int		j;
	int		ilen;
	int		jlen;

	ilen = ft_tablen((void*)tab) + addi;
	jlen = ft_strlen(tab[0]) + addj;
	tap = ft_create_2dtab(ilen, jlen, c);
	i = 0;
	while (i < ilen)
	{
		j = 0;
		while (j < jlen)
		{
			tap[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	free(tab);
	return (tap);
}
