# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 15:44:31 by lubrun       #+#   ##    ##    #+#        #
#    Updated: 2019/04/12 03:24:12 by lubrun      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_isprint.c \
	  ft_isascii.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_buildstr.c \
	  ft_count_word.c \
	  ft_pow.c \
	  ft_itoa.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstaddback.c \
	  ft_realloc.c \
	  ft_index.c \
	  get_next_line.c \
	  ft_print_2dtab.c \
	  ft_2dstrdel.c \
	  ft_tablen.c \
	  ft_tablenstr.c \
	  ft_create_2dtab.c \
	  ft_sqrt.c \
	  ft_realloc_tab.c \
	  ft_nbrlen.c \
	  ft_unbrlen.c \
	  ft_ulltoa_base.c \
	  ft_lltoa_base.c \
	  ft_str_toupper.c \
	  ft_atoull.c \
	  ft_fillnewstr.c \
	  ft_newint_tab.c \
	  ft_newcoord.c \
	  ft_newint_2dtab.c \
	  ft_str_isdigit.c \
	  ft_2dcontains.c \
	  ft_is_empty_line.c \
	  ft_get_max.c \
	  ft_get_min.c \
	  ft_2dinsert.c 

OBJS = $(SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c
	gcc -Wall -Wextra -Werror -g -c -I./ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
