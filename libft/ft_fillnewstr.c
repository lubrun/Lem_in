/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fillnewstr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 21:13:35 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:23:47 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillnewstr(size_t len, char c)
{
	char *str;

	str = ft_strnew(len);
	ft_memset(str, c, len);
	return (str);
}
