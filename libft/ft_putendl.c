/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:49:03 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 12:25:56 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *str)
{
	int		x;

	x = 0;
	if (str == NULL)
		return ;
	while (str[x])
	{
		if (ft_isascii(str[x]))
			write(1, &str[x], 1);
		x++;
	}
	write(1, "\n", 1);
}
