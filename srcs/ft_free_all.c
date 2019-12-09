/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_all.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 16:56:10 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:57:28 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_group		*ft_free_group(t_group *group)
{
	printf("FREE GROUP\n");
	if (group)
	{
		if (group->tab)
		{
			free(group->tab);
			group->tab = NULL;
		}
		free(group);
	}
	return (NULL);
}

t_path		*ft_free_paths(t_path *path, t_info *info)
{
	int index;

	printf("path IDS-P[%d][%d]\n", path->id_from_start, path->id_path);
	printf("FREE PATH\n");
	index = 0;
	printf("B0\n");
	if (!path)
		return (NULL);
	printf("B1\n");
	if (path->tab_index_room)
		free(path->tab_index_room);
	printf("B2\n");
	if (path->tab_bin_room)
		free(path->tab_bin_room);
	printf("B3\n");
	if (path->rooms)
		free(path->rooms);
	printf("B4\n");
	if (path->tab_path_index)
	{
		while (index < info->start->link_count)
		{
			free(path->tab_path_index[index]);
				index++;
		}
			free(path->tab_path_index);
	}
	printf("B6\n");
	free(path);
	return (NULL);
}

void		ft_parcour_paths(t_info *info, t_path *path, int id)
{
	if (path->next)
	{
		ft_parcour_paths(info, path->next, id);
		ft_free_paths(path, info);
	}
	else if (info->paths[id + 1])
	{
		ft_parcour_paths(info, info->paths[id + 1], id + 1);
		ft_free_paths(path, info);
	}
}

void		ft_free_matrice(t_info *info)
{
	int index;

	printf("FREE MATRICE\n");
	index = 0;
	while (info->matrice[index])
	{
		free(info->matrice[index]);
		index++;
	}
	free(info->matrice);
}

void		ft_free_all(t_info *info)
{
	printf("FREE ALL\n");
	ft_free_group(info->group);
	ft_parcour_paths(info, info->paths[0], 0);
	ft_free_matrice(info);


}
