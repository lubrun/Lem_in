/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:17:58 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:24:35 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*rtn;

	if (!(rtn = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(rtn, ptr, size);
	free(ptr);
	ptr = NULL;
	return (rtn);
}
