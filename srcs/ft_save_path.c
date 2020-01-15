/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 16:03:48 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:07:13 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 18:15:08 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 16:01:06 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_save_id_start(t_path **path, t_info *info, int diff)
{
	int		id;
	t_path *tmp;
	int		len_min;

	id = 0;
	while (id < info->start->link_count)
	{
		if (path[id])
		{
			tmp = path[id];
			if (path[id])
			{
				len_min = path[id]->length;
				while (tmp)
				{
					if (tmp->length <= (len_min + diff) || tmp->length <= (info->tab_id_end[tmp->id_end]) + diff)
						tmp->save = 1;
					tmp = tmp->next;
				}
			}
		}
		id++;
	}
}

t_path	*ft_check_save(t_path *path, t_info *info)
{
	t_path *tmp;
	static int idp;

	while (path)
	{
		path->id_path = idp++;
		tmp = path->next;
		if (tmp && tmp->save == 0)
		{
			idp--;
			path->next = tmp->next;
			ft_free_paths(tmp, info);
		//	tmp = NULL;
		}
		else
			path = path->next;

	}
	info->max_path_count = idp;
	return (path);
}

void	ft_del_path(t_path **path, t_info *info)
{
	int		id;
	t_path	*tmp;
	t_path *next;
	int		idp;

	idp = 0;
	next = NULL;
	id = 0;
	while (id < info->start->link_count)
	{
		if (path[id])
		{
			tmp = path[id];
			ft_check_save(tmp, info);
		}
		id++;
	}
}

void	ft_save_path(t_path **path, t_info *info)
{
	int diff;
	int index;

	index = 0;
	while (!path[index])
		index++;
	diff = ((info->max_path_len - path[index]->length) / 40) * 2;
	printf ("MIN MAX DIFF[%d][%d][%d]\n", path[index]->length, info->max_path_len, diff);
	ft_save_id_start(path, info, diff);
	ft_del_path(path, info);


}
