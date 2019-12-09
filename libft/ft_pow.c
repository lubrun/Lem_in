/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 12:40:06 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 11:46:09 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int pow)
{
	int		x;
	int		res;
	int		sign;

	if (pow == 0)
		return (1);
	else if (pow < 0)
	{
		pow *= -1;
		sign = 1;
	}
	x = 0;
	res = 1;
	while (x < pow)
	{
		if (sign == 0)
			res *= n;
		else
			res *= n / pow;
		x++;
	}
	return (res);
}
