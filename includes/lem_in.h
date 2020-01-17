/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 10:51:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 16:10:10 by qbarrier    ###    #+. /#+    ###.fr     */
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
	int					link_count;
	int					heuristique;
	int					lock;
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
	int					save;
	int					ant;
	int					id_end;
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
	struct s_group		*group;
	struct s_room		*rooms;
	struct s_room		*start;
	struct s_room		*end;
	struct s_path		*paths[SIZE_TAB];
	struct s_link		**link_tab;
	int					res;
	int					*tab_id_end;
	int					**matrice;
	int					ant_count;
	int					ant;
	int					path_count;
	int					max_path_count;
	int					max_path_len;
	int					lock;
	int					room_count;
}						t_info;

/*
 ** PARSING
*/

t_info					ft_pars(void);

/*
 ** CHALEUR
*/

void					ft_prepare_set_id(t_info *info, t_link link,
		int *tab, int id);

/*
 ** PATHFINDING
*/

unsigned long long int	**ft_pathfind(t_info *info,
		int start, int max_id_size);

/*
 ** TRI PATH
*/

void					ft_swap_list_end(t_path *lst1, t_path *lst2,
		t_info *info);
void					ft_tri_paths(t_info *info);
void					ft_save_path(t_path **path, t_info *info);

/*
 ** MATRICE
*/

void					ft_paths_matrice(t_info *info);
int						**ft_malloc_matrice(t_info *info, int **matrice);

/*
 ** ALGO
*/

t_group					*ft_best_group(t_info *info, int id, t_group *group,
		t_group **tmp);
int						ft_groupcpy(t_group **tmp, t_group *group);
void					ft_algo(t_info *info);
int						ft_test_path(t_path *path, t_group *group,
		t_info *info);
void					ft_turn_min(int ant, t_group *group);
void					ft_tri_group(t_info *info);
void					ft_write_ant(t_info *info, t_group *group);
void					ft_oneshot(t_info *info);


/*
 ** UTILITAIRES
*/

t_path					*get_path_by_id(t_info *info, int id_path);
t_room					*get_room_by_name(char *name, t_room *list);
t_room					*get_room_by_index(int index, t_room *list);
t_room					*next_room(t_room *room, char *s_name);
t_path					*new_path(t_info *info, int id_from_start,
		int id_path, int size_room);
t_group					*new_group(t_info *info);
char					**get_rooms_name(t_room *room);
int						create_link_tab(t_info *info);
int						count_link(t_info *info, t_room *room);
int						*create_id(void);
void					sort_list(t_path **list);
void					insert_link(t_room *room1, t_room *room2);
int						link_exist(int from, int to, t_info *info);
int						add_link(char *last_line, t_info *info);
int						set_lastline_link(char *last_list, t_info *info);
int						set_room(t_room **afrom, t_room **ato,
						char **str_info, t_info *info);
int						set_info(t_room *room,
						int *spec, t_info *info);
int						add_room(t_room **aroom, char *line,
						int *spec, t_info *info);
int						get_room_count(t_room *room);
int						add_room_into_path(t_path *apath, t_room **aroom);

/*
 ** FREE
*/

t_path					*ft_free_paths(t_path *path, t_info *info);
t_group					*ft_free_group(t_group *group);
void					ft_free_info(t_info *info);
void					ft_free_all(t_info *info);

/*
 ** FREE
*/

void					ft_display_tmp(t_group *group);
void					ft_display_path(t_info *info);
void					ft_display_info(t_info *info);
void					ft_display_pat(t_info *info);
void					ft_display_tab_end(int *tab, t_info *info);

#endif
