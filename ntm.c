/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ntm.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 15:42:39 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 16:10:17 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/lem_in.h"

int		main()
{
	t_room	**rooms;

	if (!(rooms = ft_memalloc(sizeof(t_room*)  * 3)))
		return (printf("MALLOC PLS\n"));
	rooms[0] = ft_memalloc(sizeof(t_room));
	rooms[1] = ft_memalloc(sizeof(t_room));
	rooms[0]->name = ft_strdup("1");
	rooms[1]->name = ft_strdup("2");
	rooms[2] = NULL;
	rooms = (t_room **)ft_2dinsert((void **)rooms, ft_memalloc(sizeof(t_room*)), sizeof(t_room*));
	rooms[2]->name = ft_strdup("3");
	ft_strdel(&rooms[0]->name);
	free(rooms[0]);
	ft_strdel(&rooms[1]->name);
	free(rooms[1]);
	ft_strdel(&rooms[2]->name);
	printf("{%s}\n", rooms[2]->name);
	free(rooms[2]);
	return (1);
}
