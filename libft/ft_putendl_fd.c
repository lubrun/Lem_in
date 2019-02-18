/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 12:13:05 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 12:13:44 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int		x;

	x = 0;
	if (str == NULL)
		return ;
	while (str[x])
		ft_putchar_fd(str[x++], fd);
	ft_putchar_fd('\n', fd);
}
