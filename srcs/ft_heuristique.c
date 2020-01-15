/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_heuristique.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 17:39:02 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 19:48:36 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			*ft_malloc_next_tab_h(t_info *info, int *next_tab, int *tab)
{
	int	index;
	int	nb_link;

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

int			ft_test_new_room_h(t_info *info, int turn, int id, t_link new)		
{
	if (new.state > NONE)
	{
		if (new.to != info->end)
		{
//			printf("\n\tnew.heuristique == [%d][%d][%d]\n", new.heuristique, new.from->heuristique, new.to->heuristique);
			if (new.to->heuristique == -1 || new.to->heuristique > (turn + new.id[id]))
			{
//			printf("FROM[%s]TO[%s] Turn[%d] heat[%d]", new.from->name, new.to->name, turn, new.id[id]);
				new.to->heuristique = (new.id[id] + turn);
//				printf("Heuristique [%d]\n", new.to->heuristique);
				return (1);
			}
		}
	}
	return (0);
}

int				ft_parcour_heuristique(t_info *info, int *tab, int turn, int *next_tab)
{
	t_link	new;	
	int		index;
	int		index_tab;
	int		index_next_tab;
	int		id;

//	printf("FT_PARCOUR_HEURISTIQUE\n");
	id = info->lock;
	index_next_tab = 0;
	index_tab = 0;
	while (tab[index_tab] > -1)
	{
		index = 0;
		while (index < info->room_count)
		{
			new = info->link_tab[tab[index_tab]][index];
			if (ft_test_new_room_h(info, turn, id, new) && new.to != info->start)
				next_tab[index_next_tab++] = new.to->index;
			index++;
		}
		++index_tab;
	}
	return (index_next_tab);
}

int			set_heuristique(t_info *info, int *tab, int turn, int id)
{
	int	index_next_tab;
	int	*next_tab;

//	printf("SET_HEURISTIQUE\n");
	next_tab = NULL;
	info->lock = id;
	if (!(next_tab = ft_malloc_next_tab_h(info, next_tab, tab)))
		return (-1);
	index_next_tab = ft_parcour_heuristique(info, tab, turn, next_tab);
	next_tab[index_next_tab] = -1;
	if (index_next_tab > 0)
		set_heuristique(info, next_tab, turn + 1, id);
	free(next_tab);
	return (0);
}

void		ft_prepare_heuristique(t_info *info, t_link link, int *tab, int id)
{
//	printf("FT_PREPARE_HEURISTIQUE\n");
	tab[0] = link.to->index;
	tab[1] = -1;
	set_heuristique(info, tab, 2, id);
}

int			ft_heuristique(t_info *info, int start, int max_id_size)
{
	t_link	link;
	int		*tab;
	int		index;
	int		id;

	printf("FT_HEURISTIQUE\n");
	index = 0;
	if (!(tab = ft_memalloc(sizeof(int) * 2)))
		return (0);
	while (index < info->room_count)
	{
		id = 0;
		link = info->link_tab[start][index];
		if (link.state > NONE && count_link(info, link.to) > 1)
		{	
			while (id < max_id_size)
			{
				if (link.id[id] >= 1)
					ft_prepare_heuristique(info, link, tab, id);
				id++;
			}
		}
		index++;
	}
	free(tab);
	return (1);
}
