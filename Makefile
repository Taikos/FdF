# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguerin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 20:00:07 by arguerin          #+#    #+#              #
#    Updated: 2018/03/13 20:52:05 by arguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = fdf.c \
		bug.c \
		screen.c \
		draw.c \
		key_action.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C minilibx_macos/ clean
	@make -C libft/ && make -C minilibx_macos/
	@gcc -Wall -Wextra -Werror -I libft -I minilibx_macos/ -c $(SRCS)
	@gcc -o $(NAME) $(OBJ) -framework OpenGL -framework AppKit libft/libft.a minilibx_macos/libmlx.a

clean :
	@rm -f $(OBJ)
	@make -C libft/ fclean && make -C minilibx_macos/ clean

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re
