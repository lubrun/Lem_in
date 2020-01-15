/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_all.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 16:56:10 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:25:31 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_group		*ft_free_group(t_group *group)
{
	if (group)
	{
		if (group->tab)
		{
			free(group->tab);
			group->tab = NULL;
		}
		free(group);
		group = NULL;
	}
	return (NULL);
}

t_path		*ft_free_paths(t_path *path, t_info *info)
{
	int index;

	index = 0;
	if (!path)
		return (NULL);
	if (path->tab_index_room)
	{
		free(path->tab_index_room);
		path->tab_index_room = NULL;
	}
	if (path->tab_bin_room)
	{
		free(path->tab_bin_room);
		path->tab_bin_room = NULL;
	}
	if (path->rooms)
	{
		free(path->rooms);
		path->rooms = NULL;
	}
	if (path->tab_path_index)
	{
		while (index < info->start->link_count)
		{
			free(path->tab_path_index[index]);
			path->tab_path_index[index] = NULL;
				index++;
		}
			free(path->tab_path_index);
			path->tab_path_index = NULL;
	}
	free(path);
	path = NULL;
	return (NULL);
}

void		ft_parcour_paths(t_info *info, t_path *path, int id)
{
	if (path->next)
	{
//		printf("FREE NEXT\n");
		ft_parcour_paths(info, path->next, id);
		ft_free_paths(path, info);
	}
	else if (info->paths[id + 1])
	{
//		printf("FREE ID\n");
		ft_parcour_paths(info, info->paths[id + 1], id + 1);
		ft_free_paths(path, info);
	}
	else
	{
		ft_free_paths(path, info);
	}

}

void		ft_free_matrice(t_info *info)
{
	int index;

	index = 0;
	while (info->matrice[index])
	{
		free(info->matrice[index]);
		info->matrice[index] = NULL;
		index++;
	}
	free(info->matrice);
	info->matrice = NULL;
}



void		ft_free_all(t_info *info)
{
	int index;

	index = 0;
	printf("ENTER FREE\n");
	ft_free_group(info->group);
	while (!info->paths[index] && index < info->start->link_count)
	{
		free(info->paths[index]);
		index++;
	}
	if (info->paths[index])
		ft_parcour_paths(info, info->paths[index], index);
	ft_free_matrice(info);
	ft_free_info(info);

}
