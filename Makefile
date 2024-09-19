# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 19:04:25 by kmoshker          #+#    #+#              #
#    Updated: 2024/06/01 19:04:28 by kmoshker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=src/*.c
INCLUDES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

push:
	git add .
	git status
	git commit -m fdf
	git push
