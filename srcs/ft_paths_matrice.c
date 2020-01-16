/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_paths_matrice.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 18:20:23 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 17:20:20 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_compare_path(t_path *path_a, t_path *path_o)
{
	int index;

	index = 0;
	while (path_a->tab_index_room[index])
	{
		if (path_o->tab_bin_room[path_a->tab_index_room[index]] == 1)
			return (0);
		index++;
	}
	return (1);
}

int			*ft_malloc_tab_path_index(t_info *info, t_path *path, int id)
{
	int index;

	index = 0;
	if (!(path->tab_path_index[id] = ft_memalloc(sizeof(int) *
					(info->max_path_count + 1))))
		return (NULL);
	while (index < info->max_path_count)
		path->tab_path_index[id][index++] = -1;
	return (path->tab_path_index[id]);
}

void		ft_build_matrice(t_info *info, t_path *path_a, t_path *path_o,
		int ***matrice)
{
	int index;
	int res;

	index = 0;
	info->lock = path_o->id_from_start;
	if (!path_a->tab_path_index[info->lock])
		path_a->tab_path_index[info->lock] =
			ft_malloc_tab_path_index(info, path_a, path_o->id_from_start);
	if (path_a->length < path_o->length)
		res = ft_compare_path(path_a, path_o);
	else
		res = ft_compare_path(path_o, path_a);
	(*matrice)[path_a->id_path][path_o->id_path] = res;
	(*matrice)[path_o->id_path][path_a->id_path] = res;
	if (res == 1)
	{
		while (path_a->tab_path_index[info->lock][index] != -1)
			index++;
		path_a->tab_path_index[info->lock][index] = path_o->id_path;
	}
}

int			**ft_parcour_path(t_info *info, t_path *path_a, t_path *path_o,
		int **matrice)
{
	t_path	*tmp;

	tmp = path_o;
	while (path_a)
	{
		info->lock = path_a->id_from_start;
		if (!path_a->tab_path_index[info->lock])
			path_a->tab_path_index[info->lock] =
				ft_malloc_tab_path_index(info, path_a, path_a->id_from_start);
		while (path_o)
		{
			ft_build_matrice(info, path_a, path_o, &matrice);
			path_o = path_o->next;
		}
		path_o = tmp;
		path_a = path_a->next;
	}
	return (matrice);
}

void		ft_paths_matrice(t_info *info)
{
	int		**matrice;
	int		index_abs;
	int		index_ord;
	t_path	*path_a;
	t_path	*path_o;

	index_abs = 0;
	index_ord = 0;
	matrice = NULL;
	matrice = ft_malloc_matrice(info, matrice);
	path_a = info->paths[index_abs];
	while (index_abs < info->start->link_count)
	{
		index_ord = index_abs + 1;
		path_o = info->paths[index_ord];
		while (index_ord < info->start->link_count)
		{
			matrice = ft_parcour_path(info, path_a, path_o, matrice);
			path_o = info->paths[++index_ord];
		}
		path_a = info->paths[++index_abs];
	}
	info->matrice = matrice;
}
