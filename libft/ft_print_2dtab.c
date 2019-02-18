/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_2d_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 13:17:57 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 15:44:10 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_2dtab(char **tab, int len)
{
	int		compteur;

	compteur = 0;
	while (compteur < len)
		ft_putendl(tab[compteur++]);
}
