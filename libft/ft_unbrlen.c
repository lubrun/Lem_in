/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unbrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 14:29:28 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:29:44 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_unbrlen(unsigned long long nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr >= (unsigned int)base)
	{
		len++;
		nbr /= base;
	}
	if (nbr > 0)
		len++;
	return (len);
}
