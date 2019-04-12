/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:44:36 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 03:54:13 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_info	info;
	int		j = 0;
	int		i = 0;

	if (!(info = ft_pars()).rooms)
		return (0);
	if (!(info.path = ft_pathfind(&info)))
		return (0);
	printf("%d | %d\n", info.max_path_count, info.max_path_len);
	while (j < info.max_path_count)
	{
		i = 0;
		while (i < info.path[0].length)
		{
			printf("PATH{%d|%s[%d]}\n", i, info.path[0].rooms[i]->name, info.path[0].rooms[i]->heat);
			i++;
		}
		j++;
	}
	while (info.rooms)
	{
		printf("%s|%d\n", info.rooms->name, info.rooms->heat);
		info.rooms = info.rooms->next;
	}
	return (0);
}
