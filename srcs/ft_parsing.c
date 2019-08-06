/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:59:41 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 01:26:45 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		read_comment(char *line, int *spec)
{
	if (ft_strcmp(line, "##start") == 0)
		*spec = 1;
	else if (ft_strcmp(line, "##end") == 0)
		*spec = 2;
	else
		*spec = 0;
}

static int		get_ant_nb()
{
	char	*line;
	int		ant_nb;

	if (get_next_line(0, &line) <= 0 ||
		ft_str_isdigit(line) == 0 ||
		ft_is_empty_line(line) == 1)
		return (-1);
	ant_nb = ft_atoi(line);
	ft_strdel(&line);
	return (ant_nb);
}

static t_room	*get_room_list(char **last_line, t_info *info)
{
	t_room	*room;
	char	*line;
	int		comment;
	int		spec;

	room = NULL;
	spec = 0;
	while (get_next_line(0, &line) > 0 && ft_is_empty_line(line) == 0)
	{
		if ((comment = add_room(&room, line, &spec, info)) == -1)
			return (NULL);
		else if (comment == 0)
			read_comment(line, &spec);
		else if (comment == 2)
			break;
		ft_putendl(line);
		ft_strdel(&line);
	}
	if (comment == 2)
	{
		*last_line = ft_strdup(line);
		ft_strdel(&line);
		return (room);
	}
	return (NULL);
}

t_info		ft_pars()
{
	t_room	*room;
	t_info	info;
	char	*last_line;

	room = NULL;
	info = (t_info){.rooms = NULL, .start = NULL, .end = NULL, .paths = NULL, .ant_count = 0,
	.path_count = 0, .max_path_count = 0, .max_path_len = 0, .lock = 0, .ant = 0};



	if ((info.ant_count = get_ant_nb()) == -1 ||
		!(room = get_room_list(&last_line, &info)) ||
		(!info.start || !info.end) ||
		add_link(last_line, room) == -1 ||
		info.end->link == NULL)
	{
		ft_putendl("ERROR");
		free(room);
		info.rooms = NULL;
		return (info);
	}
	printf("\n");
	info.rooms = room;
	info.lock = 1;
	return (info);
}
