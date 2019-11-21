# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 15:44:31 by lubrun       #+#   ##    ##    #+#        #
#    Updated: 2019/11/21 14:20:44 by lubrun      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem_in

SRCS_FOLDER = srcs/

SRCS_FILES = ft_lem_in.c \
			ft_parser.c \
			ft_parser_utils.c \
			ft_struct_utils.c \
			ft_struct_utils2.c \
			ft_struct_utils3.c \
			ft_pathfinding.c \
				

SRCS = $(addprefix $(SRCS_FOLDER), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

HEADER_FOLDER = includes/

HEADER_FILES = ft_lem_in.h

INCLUDE = $(addprefix $(HEADER_FOLDER), $(HEADER))

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra -Iincludes -g

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(LIBFT) $^ -o $@

%.o : %.c $(INCLUDE)
	gcc $(FLAGS) -c $< -o $@

$(LIBFT): 
	make -C libft/

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re:	fclean all

norm:
	norminette $(SRCS) $(INCLUDES) libft/*.c libft/*.h

.PHONY: all clean fclean re norm
