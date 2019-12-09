/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulltoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 14:30:59 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:40:58 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(unsigned long long nb, int base)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char			*ft_ulltoa_base(unsigned long long nb, int base)
{
	char	*str;
	int		len;

	len = get_len(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb > 0)
	{
		if (nb % base >= 10)
			str[len] = ('a' - 10) + (nb % base);
		else
			str[len] = '0' + (nb % base);
		nb /= base;
		len--;
	}
	return (str);
}
