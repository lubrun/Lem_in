/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 09:59:49 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 18:50:46 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			main(void)
{
	t_info	info;

	if (!(info = ft_pars()).rooms || !info.end)
	{
		ft_free_all(&info);
		ft_putendl("ERROR PARSING");
		return (0);
	}
	if (info.link_tab[info.start->index][info.end->index].state > NONE)
	{
		ft_oneshot(&info);
		return (0);
	}
	ft_pathfind(&info, info.start->index, MIN(SIZE_TAB,
				info.start->link_count));
	if (info.path_count <= 0)
	{
		ft_putendl("NO PATH");
		return (0);
	}
	ft_algo(&info);
	ft_tri_group(&info);
	ft_write_ant(&info, info.group);
	ft_free_all(&info);
	return (0);
}
