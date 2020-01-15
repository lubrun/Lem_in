/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_info.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 17:21:41 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 18:14:49 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_free_links(t_info *info)
{
	int index_from;
	int index_to;

	index_from = 0;
	while (info->link_tab[index_from])
	{
		index_to = 0;
		while (index_to < info->room_count)
		{
			if (info->link_tab[index_from][index_to].id)
			{
				free(info->link_tab[index_from][index_to].id);
				info->link_tab[index_from][index_to].id = NULL;
			}
			info->link_tab[index_from][index_to].to = NULL;
			info->link_tab[index_from][index_to].from = NULL;
			index_to++;
		}
		free(info->link_tab[index_from]);
		info->link_tab[index_from] = NULL;
//		info->link_tab[index_from][index_to] = NULL;
		index_from++;
	}
//	free(link);
//	link = NULL;
}

void		ft_free_rooms(t_room *rooms)
{
	if (rooms->next)
	{
		ft_free_rooms(rooms->next);
		rooms->next = NULL;
	}
	if (rooms)
	{
		free(rooms->name);
		rooms->name = NULL;
		free(rooms);
		rooms = NULL;
	}
}

void		ft_free_info(t_info *info)
{

	ft_free_links(info);
	ft_free_rooms(info->rooms);
	free(info->tab_id_end);
	info->tab_id_end = NULL;
}
