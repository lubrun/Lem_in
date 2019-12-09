/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:56:01 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 21:43:40 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < (int)n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&str[i]);
		else
			i++;
	}
	return (NULL);
}
