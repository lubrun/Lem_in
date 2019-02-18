/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:51:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 11:17:17 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H

# define FT_LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_room
{
	t_room		*next;
	t_room		link[];
	char		*name;
	t_coor		coord;
}				t_room;

int				ft_pars(t_room **aroom);

#endif
