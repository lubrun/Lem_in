/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 22:06:39 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:55:48 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t size)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && i < (int)size)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < (int)size)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	if (to_find[0] == '\0')
		return ((char *)str);
	return (NULL);
}
