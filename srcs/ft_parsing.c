/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:59:41 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 09:05:58 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		read_comment(char *line)
{
	if (ft_strcmp(line, "##start"))
		return (1);
	else if (ft_strcmp(line, "##end"))
		return (2);
	return (0);
}

static int		get_ant_nb()
{
	char	*line;
	int		ant_nb;

	if (get_next_line(0, &line) <= 0 || ft_str_isdigit(line) == 0)
		return (-1);
	ant_nb = ft_atoi(line);
	ft_strdel(&line);
	return (ant_nb);
}

static t_room	*get_room_list()
{
	t_room	*room;
	char	*line;
	int		comment;
	int		spec;

	spec = 0;
	while (get_next_line(0, &line) > 0 && ft_index(line, '-') == -1)
	{
		printf("LINE[%s]\n", line);
		if ((comment = add_room(&room, line, &spec)) == -1)
			return (NULL);
		else if (comment == 0)
			read_comment(line, &spec);
		ft_strdel(&line);
	}
	while (room)
	{
		printf("|%s|{%d-%d}|\n", room->name, room->coord.x, room->coord.y);
		room = room->next;
	}
	//set_link(line);
	ft_strdel(&line);
	return (room);
}

int				ft_pars(t_room **aroom)
{
	int ant_nb;

	if ((ant_nb = get_ant_nb()) == -1 || !(*aroom = get_room_list()))
		return (-1);
	return (ant_nb);
}
