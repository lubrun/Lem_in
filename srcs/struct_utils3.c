/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils3.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/12 01:12:02 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 17:20:30 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	sort_list(t_path **list)
{
	t_path	*tmp;
	int		index;
	int		sort;

	sort = 0;
	while (sort == 0)
	{
		index = 0;
		sort = 1;
		tmp = NULL;
		while (list[index])
		{
			if (list[index + 1] &&
					list[index + 1]->length > list[index]->length)
			{
				tmp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = tmp;
				sort = 0;
			}
			index++;
		}
	}
}

t_path	*new_path(t_info info)
{
	t_path	*path;

	if (!(path = ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->rooms = NULL;
	path->id = info.path_count;
	path->length = 0;
	path->perfum = 0;
	path->ant_needed = -1;
	return (path);
}

int		add_room_into_path(t_path *apath, t_room **aroom)
{
	t_room	**rooms;
	int		index;

	if (!(rooms = ft_memalloc(sizeof(t_room*) * (apath->length + 2))))
		return (-1);
	index = 0;
	while (index < apath->length)
	{
		rooms[index] = apath->rooms[index];
		index++;
	}
	rooms[index++] = *aroom;
	rooms[index] = NULL;
	free(apath->rooms);
	apath->rooms = rooms;
	return (1);
}
