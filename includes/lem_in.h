/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:51:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 16:48:40 by qbarrier    ###    #+. /#+    ###.fr     */
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


typedef struct			s_room
{
	struct s_room		**link;
	struct s_room		*next;
	char				*name;
	t_coord				coord;
	int					index;
	int					ant_id;
	int					spec;
	int					link_count;
	int					heat_max;
	int					heat_min;
	int					lock;
	int					tour;
	int					shortest;
	int					*perfum;
}						t_room;

typedef struct			s_group
{
	struct s_path		*paths[SIZE_TAB];
	int					turn_min;
	int					total_len;
	int					nb_paths;
	int					*tab;
}						t_group;

typedef struct			s_path
{
	struct s_room		**rooms;
	int					length;
	int					id_path;
	int					id_from_start;
	int					*tab_index_room;
	int					*tab_bin_room;
	int					**tab_path_index;
//	int					perfum;
//	int					perfum2;
	struct s_path		*next;
}						t_path;

typedef struct			s_link
{
	struct s_path_info	*list;
	struct s_room		*from;
	struct s_room		*to;
	int					state;
	int					*id;
	int					turn;
}						t_link;

typedef struct			s_info
{
	struct s_room		*rooms;
	struct s_room		*start;
	struct s_room		*end;
	struct s_path		*paths[SIZE_TAB];
	struct s_path		*shortest_path;
//	int					*perf_max;
	struct s_link		**link_tab;
	int					**matrice;
	int					*best_matrice;
	int					ant_count;
	int					ant;
	int					path_count;
	int					max_path_count;
	int					max_path_len;
	int					lock;
	int					room_count;
}						t_info;

void					ft_prepare_set_id(t_info *info, t_link link, int *tab, int id);
int						**ft_malloc_matrice(t_info *info, int **matrice);
t_group					*ft_best_group(t_info *info, int id, t_group *group, t_group **tmp);
void					ft_turn_min(int ant, t_group *group);
void					ft_del_path(t_info *info);
void					ft_opti_matrice(t_info *info);
t_path					*get_path_by_id(t_info *info, int id_path);
void					ft_paths_matrice(t_info *info);
void					ft_tri_paths(t_info *info);
int						ft_test_path(t_path *path, t_group *group, t_info *info);
int						*create_id(t_info *info);
void					ft_algo(t_info *info);
void					sort_list(t_path **list);
void					insert_link(t_room *room1, t_room *room2);
int						count_link(t_info *info, t_room *room);
int						link_exist(int from, int to, t_info *info);
int						create_link_tab(t_info *info);
int						ft_ant_needed(int len_before, int nomber_path,
						t_path **list, int min_ant);
int						set_heat_max(t_room *room, int heat,
						char *s_name, char *e_name, int h_min);
int						ft_perfum(t_room *room, char *s_name, char *e_name);
int						add_link(char *last_line, t_info *info);
int						set_lastline_link(char *last_list, t_info *info);
int						set_room(t_room **afrom, t_room **ato,
						char **str_info, t_info *info);
int						set_info(t_room *room,
						int *spec, t_info *info);
int						add_room(t_room **aroom, char *line,
						int *spec, t_info *info);
int						get_room_count(t_room *room);
int						set_heat(t_room *room, int heat,
						char *s_name, char *e_name);
int						add_room_into_path(t_path *apath, t_room **aroom);
char					**get_rooms_name(t_room *room);
unsigned long long int	**ft_pathfind(t_info *info, int start, int max_id_size);
t_room					*get_room_by_name(char *name, t_room *list);
t_room					*get_room_by_index(int index, t_room *list);
t_room					*next_room(t_room *room, char *s_name);
t_path					*new_path(t_info *info, int id_from_start, int id_path, int size_room);
t_group					*new_group(t_info *info);
t_path					*get_shortest_path(t_room *start, char *end_str);
t_info					ft_pars();

#endif
