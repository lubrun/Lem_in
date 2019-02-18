/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 11:51:28 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:17:20 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	n;

	if (str == NULL || f == NULL)
		return ;
	n = 0;
	while (str[n] != '\0')
	{
		(*f)(n, &str[n]);
		n++;
	}
}
