/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:07:04 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 18:49:19 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtn;
	int		n;

	if (s == NULL)
		return (NULL);
	if (!(rtn = ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		rtn[n] = (*f)(s[n]);
		n++;
	}
	return (rtn);
}
