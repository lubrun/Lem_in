/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 20:03:40 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 12:44:44 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_display_tab_id_end(int *tab, t_info *info)
{
	int index;

	index = 0;
	printf("\nTAB END \n");
	while (index < info->room_count)
	{
		if (tab[index] > -1)
			printf("\t[%d] == [%d]\n", index, tab[index]);
		index++;
	}
}

void		ft_display_info(t_info *info)
{
	int		index;
	int		index2;
	t_link	link;

	index = 0;
	while (index < info->room_count)
	{
		index2 = 0;
		while (index2 < info->room_count)
		{
			link = info->link_tab[index][index2];
			index2++;
		}
		index++;
	}
}

void		ft_display_pat(t_info *info)
{
	int		index_path;
	t_path	*path;
	int		index;

	index_path = 0;
	index = 0;
	while (index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		path = info->paths[index_path];
		printf("----------FOR ID [%d]-----------\n-\n", index_path);
		while (path)
		{
			while (path->rooms[index])
			{
				printf("PATH == IDP[%d] IDS[%d] NAME[%s] LEN{%d}\n", path->id_path, path->id_from_start, path->rooms[index]->name, path->length);
				index++;
			}
			index = 0;
			printf("-\n");
			path = path->next;
		}
		index_path++;
	}
}

void		ft_display_path(t_info *info)
{
	int	index_path = 0;
	t_path *path;
	int index = 0;
	while(index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		path = info->paths[index_path];
		printf("----------TEST FOR ID [%d]-----------\n-\n", index_path);
		while (path)
		{
			while (path->rooms[index])
			{
				printf("PATH == IDP[%d]IDE[%d] IDS[%d] NAME[%s] LEN{%d} SAVED[%d]\n", path->id_path, path->id_end,  path->id_from_start, path->rooms[index]->name, path->length, path->save);
				index++;
			}
			printf("TEST LastRoom[%s][%d]\n", path->rooms[path->length]->name, path->rooms[path->length]->index);

			index = 0;
			printf("-\n");
			path = path->next;
		}
		index_path++;
	}
	index_path = 0;
	while (index_path < MIN(SIZE_TAB, info->start->link_count))
	{
		path = info->paths[index_path];
		if (path)
		{
			printf("----------TEST FOR IDS/P[%d]/[%d] LEN MIN == [%d]", index_path, path->id_path, path->length);
			while (path->next != NULL)
			{
				path = path->next;
			}
			printf("LEN MAX[%d]IDP[%d]-----------\n-\n", path->length, path->id_path);
		}
		index_path++;
	}
	printf("\t\t-----LINK COUNT S[%d] E[%d]-------", info->start->link_count, info->end->link_count);
}

void		ft_display_tmp(t_group *group)
{
	int		index;
	int		index_room;
	t_path	*path;

	index_room = 0;
	index = 0;
	printf("\t\t---------BEST WAY------------\n\n");
	printf("groupe len = [%d] nbpath[%d] turn_min [%d]\n",
			group->total_len, group->nb_paths, group->turn_min);
	while (index < group->nb_paths)
	{
		path = group->paths[index];
		printf("\nPATH IDP[%d] IDS[%d] LEN [%d]\n-\n",
				path->id_path, path->id_from_start, path->length);
		index_room = 0;
		index++;
	}
}

