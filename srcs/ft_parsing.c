/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:59:41 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 11:21:33 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

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

	while (get_next_line(0, &line) > 0 && ft_index(line, '-') == -1)
	{
		add_room(room, line);
		ft_strdel(&line);
	}
	set_link(line);
	ft_strdel(&line);
}

int				ft_pars(t_room **aroom)
{
	int ant_nb;

	if ((ant_nb = get_ant_nb()) == -1 || !(*aroom = get_room_list()))
		return (-1);
	return (ant_nb);
}
