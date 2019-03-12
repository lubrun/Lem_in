/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:59:41 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 14:17:05 by lubrun      ###    #+. /#+    ###.fr     */
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

	if (get_next_line(0, &line) <= 0 || ft_str_isdigit(line) == 0 || ft_is_empty_line(line) == 1)
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

	room = NULL;
	while (get_next_line(0, &line) > 0 && ft_is_empty_line(line) == 0)
	{
		if ((comment = add_room(&room, line, &spec)) == -1)
			return (NULL);
		else if (comment == 0)
			read_comment(line, &spec);
		else if (comment == 2)
			break;
		ft_putendl(line);
		ft_strdel(&line);
	}
	if (ft_is_empty_line(line) == 1)
		return (NULL);
	if (comment == 2)
		printf("GO PARSE\n");
		//parse_link(line);
	ft_strdel(&line);
	return (room);
}

int				ft_pars(t_room **aroom)
{
	int ant_nb;

	if ((ant_nb = get_ant_nb()) == -1 || !(*aroom = get_room_list()))
	{
		ft_putendl("ERROR");
		return (-1);
	}
	return (ant_nb);
}
