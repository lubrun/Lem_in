/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del_path.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 14:26:53 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 17:13:48 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"


int		ft_best_perfum_by_id(t_info *info, int id)
{
	t_path *path;
	int perfum;

	perfum = 0;
	path = info->paths[id];
	while (path)
	{
		path->perfum = path->rooms[0]->perfum[id];
		if (path->rooms[0]->perfum[id] > perfum)
			perfum = path->rooms[0]->perfum[id];
		path = path->next;
	}
	return (perfum);
}

t_path	*ft_mark_paths(int perfum, int perfum2, t_path *path)
{
		t_path	*tmp;

		tmp = NULL;
		if (!path)
			return (NULL);
//		printf("\tPERF [%d]\n", path->perfum);
		tmp = ft_mark_paths(perfum, perfum2, path->next);
		path->next = tmp;
		if (path && (path->perfum == perfum || path->perfum2 == perfum2))
			return (path);
		else
			return(tmp);
}

int		ft_moyenne(t_info *info, int id)
{
	int index;
	int perfum;
	int swap;
	t_path *path;

	swap = 0;
	path = info->paths[id];
	index = 0;
	perfum = path->rooms[index]->perfum[id];
	while (path)
	{
		while (path->rooms[index])
		{
			perfum += path->rooms[index]->perfum[id];
			index++;
		}
		index = 0;
		perfum = perfum / path->length;
		if (perfum > swap)
			swap = perfum;
		path->perfum2 = perfum;
		perfum = 0;
		path = path->next;
	}
	return (swap);
}

void	ft_del_path(t_info *info)
{
	int perfum;
	int id;
	int perfum2;


	id = 0;
	while (id < info->start->link_count)
	{
		if (info->paths[id])
		{
			perfum = ft_best_perfum_by_id(info, id);
			perfum2 = ft_moyenne(info, id);
//			printf("PERF [%d] ID[%d]\n", perfum, id);
			ft_mark_paths(perfum, perfum2, info->paths[id]);

		}
		id++;
	}


}
