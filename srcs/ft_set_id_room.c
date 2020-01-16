/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_id_room.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 15:38:43 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 16:24:38 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*ft_malloc_next_tab(t_info *info, int *next_tab, int *tab)
{
	int index;
	int nb_link;

	nb_link = 1;
	index = 0;
	while (tab[index] > -1)
	{
		nb_link += get_room_by_index(tab[index], info->rooms)->link_count - 1;
		index++;
	}
	if (!(next_tab = ft_memalloc(sizeof(int) * nb_link)))
		return (NULL);
	return (next_tab);
}

int		ft_test_new_room(t_info *info, int turn, int id, t_link new)
{
	if ((new.id[id] == -1) && new.to != info->start)
	{
		info->link_tab[new.to->index][new.from->index].id[id] = turn;
		new.id[id] = turn;
		return (1);
	}
	return (0);
}

int		ft_parcour_s_i_r(t_info *info, int *tab, int turn, int *next_tab)
{
	t_link	new;
	int		index;
	int		index_tab;
	int		index_next_tab;
	int		id;

	id = info->lock;
	index_next_tab = 0;
	index_tab = 0;
	while (tab[index_tab] > -1)
	{
		index = 0;
		while (index < info->room_count)
		{
			new = info->link_tab[tab[index_tab]][index];
			if (new.state > NONE && ft_test_new_room(info, turn, id, new)
					&& new.to != info->end)
				next_tab[index_next_tab++] = new.to->index;
			index++;
		}
		++index_tab;
	}
	return (index_next_tab);
}

int		set_id_room(t_info *info, int *tab, int turn, int id)
{
	int		index_next_tab;
	int		*next_tab;

	next_tab = NULL;
	info->lock = id;
	if (!(next_tab = ft_malloc_next_tab(info, next_tab, tab)))
		return (-1);
	index_next_tab = ft_parcour_s_i_r(info, tab, turn, next_tab);
	next_tab[index_next_tab] = -1;
	if (index_next_tab > 0)
		set_id_room(info, next_tab, turn + 1, id);
	free(next_tab);
	return (0);
}

void	ft_prepare_set_id(t_info *info, t_link link, int *tab, int id)
{
	link.state = USED;
	link.id[id] = 1;
	tab[0] = link.to->index;
	tab[1] = -1;
	set_id_room(info, tab, 2, id);
}
