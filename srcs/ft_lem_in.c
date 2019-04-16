/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:44:36 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 10:29:13 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_info	info;
	if (!(info = ft_pars()).rooms)
		return (0);
	if (!(info.paths = ft_pathfind(&info)))
		return (0);
	printf("%d|%d\n", info.paths[0]->length, info.paths[1]->length);
	return (1);
}
