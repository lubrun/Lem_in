/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:27:56 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:34:16 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char		*s;
	int					i;

	i = 0;
	s = (unsigned char *)str;
	while (i < (int)n)
		s[i++] = (unsigned char)c;
	return (str);
}
