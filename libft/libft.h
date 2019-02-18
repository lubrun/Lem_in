/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:26:08 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 11:12:08 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 200

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_memdel(void **ap);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_strdel(char **as);
void				ft_2dstrdel(char ***as);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
void				ft_strclr(char *str);
void				ft_bzero(void *s, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_lstclr(t_list **alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_print_2dtab(char **tab, int len);
void				ft_str_toupper(char **astr);
int					get_next_line(const int fd, char **line);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t size);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_count_word(char const *s, char c);
int					ft_atoi(char const *str);
int					ft_tolower(int letter);
int					ft_toupper(int letter);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_str_isdigit(char *str);
int					ft_index(char const *s, int c);
int					ft_sqrt(int nb);
int					ft_pow(int n, int pow);
int					ft_nbrlen(long long nbr, int base);
int					ft_unbrlen(unsigned long long nbr, int base);
int					*ft_newint_tab(int size, int value);
int					**ft_newint_2dtab(int y, int x, int value);
unsigned long long	ft_atoull(char *str);
size_t				ft_strlen(char const *str);
size_t				ft_strlcat(char *dest, char const *src, size_t size);
size_t				ft_lstlen(t_list *lst);
size_t				ft_tablen(void **tab);
char				*ft_fillnewstr(size_t len, char c);
char				*ft_strdup(char const *src);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, unsigned int n);
char				*ft_strcat(char *dest, char const *src);
char				*ft_strncat(char *dest, char const *src, unsigned int n);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strstr(char const *str, char const *to_find);
char				*ft_strnstr(char const *str,
	char const *to_find, size_t size);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char *s1, char *s2, int ifree);
char				*ft_strfjoin(char const *s1, char const *s2);
char				*ft_buildstr(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_ulltoa_base(unsigned long long nb, int base);
char				*ft_lltoa_base(long long nb, int base);
char				**ft_strsplit(char const *s, char c);
char				**ft_create_2dtab(int width, int height, int c);
char				**ft_realloc_tab(char **tab, int addi, int addj, int c);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void	*s1, void const *s2, size_t n);
void				*ft_memccpy(void *s1, void const *s2, int c, size_t n);
void				*ft_memmove(void *s1, void const *s2, size_t n);
void				*ft_memchr(void const *str, int c, size_t n);
void				*ft_memalloc(size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_coord				ft_newcoord(int x, int y);

#endif
