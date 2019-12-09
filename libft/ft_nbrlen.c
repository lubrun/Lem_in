/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nbrlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 15:53:22 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:28:18 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long nbr, int base)
{
	int		len;

	len = 0;
	if (nbr < -9223372036854775807)
		return (20);
	if (nbr < 0)
		return (ft_nbrlen(nbr * -1, base));
	if (nbr == 0)
		return (1);
	while (nbr >= base)
	{
		len++;
		nbr /= base;
	}
	if (nbr > 0)
		len++;
	return (len);
}
