/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_paths_matrice.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 18:20:23 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 17:36:08 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"



int			**ft_malloc_matrice(t_info *info, int **matrice)
{
	int count;
	int index;

	index = 0;
	count = 0;
	if (!(matrice = ft_memalloc(sizeof(int*) * (info->max_path_count + 1))))
		return (NULL);
	while (info->max_path_count > count)
	{
		if (!(matrice[count] = ft_memalloc(sizeof(int) * (info->max_path_count + 1))))
			return (NULL);
		while (index <= info->max_path_count)
		{
			matrice[count][index] = 0;
			index++;
		}
		index = 0;
		count++;
	}
	matrice[count] = NULL;
	return (matrice);
}

int			ft_compare_path(t_path *path_a, t_path *path_o)
{
	int index;

	index = 0;		
//	printf("COMP 0\n");
	while (path_a->tab_index_room[index])
	{
//		printf("COMP 1\n");
		if (path_o->tab_bin_room[path_a->tab_index_room[index]] == 1)
		{
//			printf("COMP 2\n");
			return (0);
		}
//		printf("COMP 3\n");
		index++;
	}	
//printf("COMP 4 out\n");
	return (1);
}

int		*ft_malloc_tab_path_index(t_info *info, t_path *path, int id)
{
	int index;

//	printf("Malloc pathindexpath ENTER for ID[%d]\n", id);
	index = 0;
	if (!(path->tab_path_index[id] = ft_memalloc(sizeof(int) * (info->max_path_count + 1))))
		return (NULL);
	while (index < info->max_path_count)
		path->tab_path_index[id][index++] = -1;
//	path->tab_path_index[id][index] = 0;
//	printf("Malloc pathindexpath RETURN ID[%d][%d]\n", id, path->tab_path_index[id][0]);
	return (path->tab_path_index[id]);
}

int			**ft_parcour_path(t_info *info, t_path *path_a, t_path *path_o, int **matrice)
{
	t_path	*tmp;
	int res;
	int index;

	tmp = path_o;
	while (path_a)
	{
		info->lock = path_a->id_from_start;
		if (!path_a->tab_path_index[info->lock])
			path_a->tab_path_index[info->lock] = ft_malloc_tab_path_index(info, path_a, path_a->id_from_start);
//				printf("PAR 0\n");
		while (path_o)
		{
			info->lock = path_o->id_from_start;		
			if (!path_a->tab_path_index[info->lock])
				path_a->tab_path_index[info->lock] = ft_malloc_tab_path_index(info, path_a, path_o->id_from_start);
			index = 0;
//			printf("PAR 1\n");
			if (path_a->length < path_o->length)
				res = ft_compare_path(path_a, path_o);
			else
				res = ft_compare_path(path_o, path_a);	
//			printf("PAR 2\n");
//			printf("ID A [%d] O [%d]\n", path_a->id_path, path_o->id_path);
			matrice[path_a->id_path][path_o->id_path] = res;
//			printf("PAR 3\n");
			matrice[path_o->id_path][path_a->id_path] = res;
//			printf("PAR 4\n");
			if (res == 1)
			{
				while (path_a->tab_path_index[info->lock][index] != -1)
					index++;
				path_a->tab_path_index[info->lock][index] = path_o->id_path;
			}
			path_o = path_o->next;
//			printf("PAR 5\n");
		}
//		printf("PAR 6\n");
		path_o = tmp;
		path_a = path_a->next;
	}
//	printf("PAR 7\n");
	return (matrice);
}

void		ft_display_matrice(t_info *info, int **matrice)
{
	int index_abs;
	int index_ord;

	index_abs = 0;
	index_ord = 0;
	while (index_abs < info->max_path_count)
	{
		while (index_ord < info->max_path_count)
		{
			printf("[%d]", matrice[index_abs][index_ord]);
			index_ord++;
		}
		index_ord = 0;
		printf("\n");
		index_abs++;
	}
}

void	ft_display_index_paths(t_info *info)
{
	int index;
	int id;
	int index_path;
	t_path *path;

	id = 0;
	index = 0;
	while (index < info->max_path_count)
	{
		index_path = 0;
		path = get_path_by_id(info, index);
		if (path)
		{
			
//			printf("index = [%d]\n", index);
			while (path->tab_path_index[id])
			{
				while (path->tab_path_index[id][index_path])
				{
					printf("ID index pathID [%d][%d][%d]\n",id, index_path, path->tab_path_index[id][index_path]);
					index_path++;
				}
				index_path = 0;
				id++;
			}
			printf("\n");
			id = 0;
		}
		else
			printf("WTF\n");


		index++;
	}

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
//	printf("MAT 0\n");	
	printf("\t-------MATRICE START\n");
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
//	info->lock = 0;
	info->matrice = matrice;
	printf("\t-------MATRICE OK\n");
//	ft_display_index_paths(info);
//	ft_display_matrice(info, matrice);
}
