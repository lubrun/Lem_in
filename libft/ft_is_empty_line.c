/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_empty_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 13:42:05 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:47:27 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_empty_line(char *line)
{
	if (line)
		if (*line == '\0')
			return (1);
		else
			return (0);
	else
		return (-1);
}
