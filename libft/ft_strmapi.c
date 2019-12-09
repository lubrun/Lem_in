/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:17:06 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 18:50:03 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rtn;
	unsigned int	n;

	if (s == NULL)
		return (NULL);
	if (!(rtn = ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		rtn[n] = (*f)(n, s[n]);
		n++;
	}
	return (rtn);
}
