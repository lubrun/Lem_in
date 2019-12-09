/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 16:24:18 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:27:43 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL && list)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	else if (list)
	{
		if (!(list->content = (void *)malloc(ft_strlen((char *)content) + 1)))
			return (NULL);
		list->content = ft_strdup((void *)content);
		list->content_size = content_size;
		list->next = NULL;
	}
	return (list);
}
