#include "../includes/lem_in.h"

t_group		*new_group(t_info *info)
{
	t_group *group;
	int		index;

	index = 0;
	if (!(group = ft_memalloc(sizeof(t_group))))
		return (NULL);
	group->nb_paths = 0;
	group->total_len = 0;
	if (!(group->tab = ft_memalloc(sizeof(int) * (info->start->link_count + 1))))
		return (NULL);
	while (index <= info->start->link_count)
		group->tab[index++] = -1;
	return (group);
}

t_path		*get_path_by_id(t_info *info, int id_path)
{
	int		id_start;
	t_path	*path;

	if (id_path < 0)
		return (NULL);
//	printf("GETpBID START SEEK [%d]\n", id_path);
	id_start = 0;
	while (id_start < info->start->link_count)
	{
		path = info->paths[id_start];
		if (path)
		{
//			printf("PATH ID == [%d]\n", path->id_path);
			if (!info->paths[id_start + 1] || info->paths[id_start + 1]->id_path > id_path)
				break;
		}
		id_start++;
	}
	while (path &&  path->id_path < id_path)
	{
//		printf("PATH ID_P[%d]\n", path->id_path);
		path = path->next;
	}
//	printf("ID SEEK [%d] RES [%d]\n", id_path, path->id_path);
	return (path);
}

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
