/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_write_ant.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 18:04:48 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 20:52:26 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_print_ant(t_info *info, t_room *room)
{
	int	a_virer;

	a_virer = info->lock;
	if (room->ant_id > 0)
	{
		ft_putstr("L");
		ft_putnbr(room->ant_id);
		ft_putstr("-");
		ft_putstr(room->name);
		ft_putstr(" ");
	}
}

void		ft_parcour_res(t_info *info, t_path *path, int id_ant)
{
	int	index;
	int	swap_id;

	index = path->length;
	while (index > 0 && path->rooms[index]->ant_id == -1)
		index--;
	while (index > 0)
	{
		swap_id = path->rooms[index]->ant_id;
		if ((index + 1) > path->length)
		{
			info->end->ant_id = swap_id;
			ft_print_ant(info, info->end);
			info->ant_count--;
		}
		else
		{
			path->rooms[index + 1]->ant_id = swap_id;
			ft_print_ant(info, path->rooms[index + 1]);
		}
		index--;
	}
	path->rooms[1]->ant_id = id_ant;
	ft_print_ant(info, path->rooms[1]);
}

void		ft_dispatch(t_info *info, t_group *group)
{
	int	id_ant;
	int	index;
	int	count;

	count = 0;
	id_ant = 1;
	while (info->ant_count > 0)
	{
		index = 0;
		while (group->paths[index])
		{
			if (group->paths[index]->ant > 0)
			{
				ft_parcour_res(info, group->paths[index], id_ant++);
				group->paths[index]->ant--;
			}
			else
				ft_parcour_res(info, group->paths[index], -1);
			index++;
		}
		count++;
		ft_putchar('\n');
	}
	info->lock = count;
}

void		ft_write_ant(t_info *info, t_group *group)
{
	int	index;
	int	total;
	int	diff;

	total = 0;
	index = -1;
	while (group->paths[++index] && index < group->nb_paths)
	{
		group->paths[index]->ant = group->turn_min -
			group->paths[index]->length;
		total += group->paths[index]->ant;
	}
	diff = total - info->ant_count;
	group->paths[0]->ant -= diff;
	ft_dispatch(info, group);
	ft_putstr("\nTour attendu : ");
	ft_putnbr(info->res);
	ft_putstr("\nTour total : ");
	ft_putnbr(info->lock);
	if (info->res > 0)
		ft_putstr("\nDiff : + ");
	if (info->res > 0)
		ft_putnbr(info->res - info->lock);
	ft_putchar('\n');
	ft_free_all(info);
}

void		ft_oneshot(t_info *info)
{
	int	id_ant;

	id_ant = 1;
	while (info->ant_count > 0)
	{
		ft_putstr("L");
		ft_putnbr(id_ant);
		ft_putstr("-");
		ft_putstr(info->end->name);
		ft_putstr(" ");
		id_ant++;
		info->ant_count--;
	}
	ft_putchar('\n');
	ft_free_all(info);
}
