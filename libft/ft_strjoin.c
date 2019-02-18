/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:00:04 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 11:07:03 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2, int ifree)
{
	int		len;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	ft_strcpy(ptr, (char *)s1);
	ft_strcat(ptr, (char *)s2);
	if (ifree == 1)
		ft_strdel(&s1);
	else if (ifree == 2)
		ft_strdel(&s2);
	else if (ifree == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ptr);
}
