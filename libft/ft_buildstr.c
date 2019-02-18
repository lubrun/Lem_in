/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buildstr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 23:50:10 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 23:57:26 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_buildstr(char const *s)
{
	char	*ptr;

	if (!(ptr = (char *)ft_strnew((size_t)ft_strlen((char *)s))))
		return (NULL);
	return (ptr = ft_strdup((char *)s));
}
