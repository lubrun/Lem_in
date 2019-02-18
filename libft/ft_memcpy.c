/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:56:45 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:45:37 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, void const *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr2 = (unsigned char *)s2;
	ptr1 = (unsigned char *)s1;
	while (n-- > 0)
		*ptr1++ = *ptr2++;
	return ((unsigned char *)s1);
}
