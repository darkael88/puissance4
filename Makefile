# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 02:01:24 by ysoto             #+#    #+#              #
#    Updated: 2014/03/09 23:09:54 by mdarty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= puissance4

SRC		=	src/ft_ai.c\
			src/main.c\
			src/ft_check_diagonal.c\
			src/ft_check_win.c\
			src/ft_check_number.c\
			src/ft_create_map.c\
			src/ft_error.c\
			src/ft_first_player.c\
			src/ft_place.c\
			src/ft_print_map.c\
			src/ft_read_ai.c\
			src/ft_ai_weight_left.c\
			src/ft_ai_weight_right.c\
			src/ft_check_place_ai.c\
			src/ft_ai_search_max_weight.c\
			src/ft_game_human.c\
			src/ft_check_human.c\
			src/ft_human_weight_left.c\
			src/ft_human_weight_right.c\
			src/ft_ai_max.c\
			src/ft_human_max.c\

OBJ		= $(SRCS:src/%.c=.obj/%.o)

LIB		= libft/

INCLUDE	= ./include/

CC		= gcc

CFLAG	= -Wall -Wextra -Werror -I$(INCLUDE)

LFLAG	= -L libft/ -lft

RM		= rm -rf


all: $(NAME)

$(NAME): $(OBJ)

	@echo  "\033[1;29m"
	@make -C $(LIB)
	$(CC) $(CFLAG) $(SRC) -o $(NAME) $(LFLAG)
	@echo "\033[1;31m"
	@echo "Compilation done..."

clean:

	@make -C $(LIB) clean
	@$(RM) $(OBJ)
	@echo  "\033[1;34m"
	@echo "Clean...\033[1;32m done √"


fclean:		clean

	@make -C $(LIB) fclean
	@$(RM) $(NAME)
	@echo  "\033[1;34m"
	@echo "fclean...\033[1;32m done √"

re:			fclean $(NAME)

.PHONY : fclean clean all
