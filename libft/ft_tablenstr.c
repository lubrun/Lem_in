/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tablenstr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 19:02:17 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 19:03:17 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tablenstr(char **tab)
{
	size_t len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}
