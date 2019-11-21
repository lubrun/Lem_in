/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:51:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 16:52:37 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>
# define MIN(x, y) ((x < y ? x : y))
# define SIZE_TAB  64

enum					e_linkstate
{
	NONE, NOT_USED, USED, TAB_END = -1
};

typedef struct			s_path_info
{
	int					index;
	int					turn;
}						t_path_info;

typedef struct          s_room
{
    struct s_room       *next;
	int					*turn;
    char                *name;
    struct s_point_2    coord;
    int                 index;
    int                 lock;
    int                 link_count;
	int					spec;
}                       t_room;

typedef struct			s_group
{
	struct s_path		*paths[SIZE_TAB];
	int					turn_min;
	int					total_len;
	int					nb_paths;
	int					*tab;
}						t_group;

typedef struct          s_info
{
	int			       	**link_tab;
	struct s_room		**room_tab;
    struct s_room       *rooms;
    struct s_room       *start;
    struct s_room       *end;
    int                 ant_count;
    int                 room_count;
    int                 path_count;
    int                 error;
}                       t_info;

//INPUT
t_info		            parse_info();

//STRUCT
int						*create_turn_tab(t_info *info);
int						create_link_tab(t_info *info);
int     				create_room_tab(t_info *info);
int						set_lastline_link(char *last_list, t_info *info);
int						set_room(t_room **afrom, t_room **ato,
						char **str_info, t_info *info);
int						add_link(char *last_line, t_info *info);
int						add_room(t_room **aroom, char *line,
						int *spec, t_info *info);

t_room					*get_room_by_name(char *name, t_room *list);
int						set_info(t_room *room,
						int *spec, t_info *info);
#endif
