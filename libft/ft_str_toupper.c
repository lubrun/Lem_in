/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_toupper.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 17:58:33 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:29:05 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_toupper(char **astr)
{
	char	*str;
	int		index;

	index = 0;
	if (*astr)
	{
		str = *astr;
		while (str[index])
		{
			if (ft_isalpha(str[index]) &&
				str[index] >= 'a' && str[index] <= 'z')
				str[index] -= 32;
			index++;
		}
	}
}
