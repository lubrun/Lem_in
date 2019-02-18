/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:18:37 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 23:00:25 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *rtnlst;

	if (lst)
	{
		rtnlst = f(lst);
		rtnlst->next = ft_lstmap(lst->next, f);
		return (rtnlst);
	}
	return (NULL);
}
