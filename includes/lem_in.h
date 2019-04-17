/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:51:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 13:57:56 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_room
{
	struct s_room		**link;
	struct s_room		*next;
	char				*name;
	t_coord				coord;
	int					spec;
	int					link_count;
	int					heat;
	int					lock;
	int					perfum;
}						t_room;

typedef struct			s_path
{
	struct s_room		**rooms;
	int					length;
	int					id;
}						t_path;

typedef struct			s_info
{
	struct s_room		*rooms;
	struct s_room		*start;
	struct s_room		*end;
	struct s_path		**paths;
	int					ant_count;
	int					path_count;
	int					max_path_count;
	int					max_path_len;
	int					lock;
}						t_info;

int				ft_perfum(t_room *room, char *s_name, char *e_name);
void			insert_link(t_room *room1, t_room *room2);
int				add_link(char *last_line, t_room *room);
int				set_lastline_link(char *last_list, t_room *room);
int				set_room(t_room **afrom, t_room **ato, t_room *room, char **info);
int				set_info(t_room *room, int *spec, t_info *info);
int				add_room(t_room **aroom, char *line, int *spec, t_info *info);
int				get_room_count(t_room *room);
int				set_heat(t_room *room, int heat);
int				add_room_into_path(t_path *apath, t_room **aroom);
char			**get_rooms_name(t_room *room);
t_room			*get_room_by_name(char *name, t_room *list);
t_room			*get_room_link_by_name(char *name, t_room *room);
t_path			*new_path(t_info info);
t_path			**ft_pathfind(t_info *info);
t_info			ft_pars();

#endif
