/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:51:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 09:15:46 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_room
{
	struct s_room		*next;
	struct s_room		**link;
	char				*name;
	t_coord				coord;
	int					spec;
}						t_room;

typedef struct			s_map
{
	
}

int				ft_pars(t_room **aroom);
int				add_room(t_room **aroom, char *line);
int				get_room_count(t_room *room);
char			**get_rooms_name(t_room *room);
t_room			*get_room_by_name(char *name, t_room *list);

#endif
