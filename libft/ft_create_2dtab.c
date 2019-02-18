/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_2dtab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 17:04:45 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 21:24:59 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_create_2dtab(int width, int height, int c)
{
	char	**map;
	int		i;

	if (!(map = (char**)ft_memalloc(sizeof(char*) * (height + 1))))
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = ft_strnew(width);
		map[i] = (char*)ft_memset(map[i], c, width);
		i++;
	}
	map[i] = NULL;
	return (map);
}
