/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 14:31:40 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 14:06:06 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int	link_valid(t_room *from, t_room *to, t_info *info)
{
	int i;

	if (from->index == to->index)
		return (0);
	if (from->link_count > 0)
	{
		i = 0;
		while (i < info->room_count)
		{
			if (info->link_tab[from->index][to->index] ||
			info->link_tab[to->index][from->index])
				return (0);
			i++;
		}
	}
	return (1);
}

int			set_room(t_room **afrom, t_room **ato,
	char **str_info, t_info *info)
{
	t_room	*from;
	t_room	*to;

	from = get_room_by_name(str_info[0], info->rooms);
	to = get_room_by_name(str_info[1], info->rooms);
	if (!from || !to)
	{
		ft_2dstrdel(&str_info);
		return (0);
	}
	if (!link_valid(from, to, info))
	{
		ft_2dstrdel(&str_info);
		return (0);
	}
	ft_2dstrdel(&str_info);
	*afrom = from;
	*ato = to;
	return (1);
}

t_room		*get_room_by_name(char *name, t_room *list)
{
	while (list)
	{
		if (ft_strcmp(name, list->name) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int			create_link_tab(t_info *info)
{
	int i;
	int j;

	if (!(info->link_tab = ft_memalloc(sizeof(unsigned char **) *
					(info->room_count + 1))))
		return (-1);
	i = 0;
	while (i < info->room_count)
	{
		if (!(info->link_tab[i] = ft_memalloc(sizeof(unsigned char *) *
						(info->room_count + 1))))
			return (-1);
		j = 0;
		while (j < info->room_count)
		{
			info->link_tab[i][j] = NULL;
			j++;
		}
		info->link_tab[i][j] = NULL;
		i++;
	}
	info->link_tab[i] = NULL;
	return (1);
}

t_room		*new_room(char **room_info, int *spec, t_info *info)
{
	t_room	*new;

	if (!(new = ft_memalloc(sizeof(t_room))) || !room_info ||
			!room_info[0] || !room_info[1] || !room_info[2])
		return (NULL);
	new->next = NULL;
	new->path_id = 0;
	new->name = ft_strdup(room_info[0]);
	new->coord = ft_newpoint_2(ft_atoi(room_info[1]), ft_atoi(room_info[2]));
	new->index = info->room_count;
	new->link_count = 0;
	new->spec = *spec;
	ft_2dstrdel(&room_info);
	if (set_info(new, spec, info) == -1)
		return (NULL);
	return (new);
}
