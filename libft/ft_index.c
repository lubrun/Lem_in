/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_index.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 17:09:00 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:15:03 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((int)s[i] == c)
			return (i);
		i++;
	}
	if ((int)s[i] == c)
		return (i);
	return (-1);
}
