/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 14:28:24 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 10:29:52 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		get_ant_nb(void)
{
	char	*line;
	int		ant_nb;

	if (get_next_line(0, &line) <= 0 ||
			ft_str_isdigit(line) == 0 ||
			ft_is_empty_line(line) == 1)
		return (0);
	ant_nb = ft_atoi(line);
	ft_strdel(&line);
	return (ant_nb);
}

static void		read_comment(char *line, int *spec)
{
	if (ft_strcmp(line, "##start") == 0)
		*spec = 1;
	else if (ft_strcmp(line, "##end") == 0)
		*spec = 2;
	else
		*spec = 0;
}

static int		get_room_list(char **last_line, t_info *info)
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
			return (0);
		else if (comment == 0)
			read_comment(line, &spec);
		else if (comment == 2)
			break ;
		ft_putendl(line);
		ft_strdel(&line);
	}
	if (comment == 2)
	{
		*last_line = ft_strdup(line);
		ft_strdel(&line);
		info->rooms = room;
	}
	return (1);
}

static int		add_link(char *last_line, t_info *info)
{
	char	*line;
	t_room	*from;
	t_room	*to;

	if (!create_link_tab(info) ||
			set_lastline_link(last_line, info) == 0)
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] != '#')
		{
			if (set_room(&from, &to, ft_strsplit(line, '-'), info) == 0)
				return (-1);
			if (!(info->link_tab[from->index][to->index] =
			create_turn_tab()) || !(info->link_tab[to->index][from->index] =
			create_turn_tab()))
				return (-1);
			from->link_count++;
			to->link_count++;
			ft_putendl(line);
			ft_strdel(&line);
		}
	}
	return (1);
}

t_info			parse_info(void)
{
	t_room	*room;
	t_info	info;
	char	*last_line;

	room = NULL;
	info = (t_info){.link_tab= NULL, .room_tab = NULL, .room_name_tab = NULL,
	.rooms = NULL, .start = NULL, .end = NULL, .ant_count = 0,
		.room_count = 0, .path_count = 0, .error = 0};
	if (!(info.ant_count = get_ant_nb()) ||
			!get_room_list(&last_line, &info) ||
			(!info.start || !info.end) ||
			!create_room_tab(&info) ||
			!add_link(last_line, &info))
	{
		ft_putendl("ERROR");
		free(room);
		info.rooms = NULL;
		return (info);
	}
	return (info);
}
