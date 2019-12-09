/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:17:55 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:45:17 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	int	i;
	int	a;
	int	return_length;

	a = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[a] != '\0')
		a++;
	return_length = (int)size < i ? a + (int)size : i + a;
	a = -1;
	while (src[++a] != '\0' && a + i < (int)size - 1)
		dest[i + a] = src[a];
	dest[i + a] = '\0';
	return (return_length);
}
