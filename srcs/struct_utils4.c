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
	if (!(group->tab = ft_memalloc(sizeof(int) * info->room_count + 1)))
		return (NULL);
	while (index < info->room_count)
		group->tab[index++] = 0;
	return (group);
}
