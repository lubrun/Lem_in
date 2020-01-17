/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 09:59:49 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 20:20:15 by qbarrier    ###    #+. /#+    ###.fr     */
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
	info.min_link = ft_min(SIZE_TAB, info.start->link_count);
	if (info.link_tab[info.start->index][info.end->index].state > NONE)
	{
		ft_oneshot(&info);
		return (0);
	}
	ft_pathfind(&info, info.start->index, info.min_link);
	if (info.path_count <= 0)
	{
		ft_free_all(&info);
		ft_putendl("NO PATH");
		return (0);
	}
	ft_algo(&info);
	ft_tri_group(&info);
	ft_write_ant(&info, info.group);
	return (0);
}
