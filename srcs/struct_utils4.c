#include "../includes/lem_in.h"

t_group		*new_group(void)
{
	t_group *group;

	if (!(group = ft_memalloc(sizeof(t_group))))
		return (NULL);
	group->nb_paths = 0;
	group->total_len = 0;
	return (group);
}
