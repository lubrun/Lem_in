/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 12:28:04 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 13:54:29 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int nb)
{
	char	*ptr;

	if ((ptr = (char *)malloc(sizeof(*ptr) * 2)) == NULL)
		return (NULL);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb > 9)
		ptr = ft_strjoin(ft_itoa(nb / 10), ft_itoa(nb % 10), 0);
	else if (nb >= 0 && nb <= 9)
	{
		ptr[0] = (nb + 48);
		ptr[1] = '\0';
	}
	else if (nb < 0)
	{
		ptr[0] = '-';
		ptr[1] = '\0';
		ptr = ft_strjoin(ptr, ft_itoa(nb * -1), 0);
	}
	return (ptr);
}
