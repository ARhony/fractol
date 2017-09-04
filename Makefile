# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramon <aramon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 13:50:02 by aramon            #+#    #+#              #
#    Updated: 2017/05/05 20:52:25 by aramon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_LLDB = lldb

#COLORS
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m

LIBFT_DIR = ./libft/
NAMELIBFT = ./libft/libft.a

MINILIBX_DIR = minilibx/
NAMEMLX = minilibx/libmlx.a

LIB = $(LIBFT_DIR) $(NAMELIBFT)
MLX = $(MINILIBX_DIR) $(NAMEMLX)

SRC = srcs/main.c 		\
	  srcs/init.c 		\
	  srcs/hook.c 		\
	  srcs/draw.c 		\
	  srcs/image.c 		\
	  srcs/calcul.c		\
	  srcs/utilities.c

FLAGS = -Wextra -Werror -Wall -O3
FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDE = -I ./include

all : $(LIB) $(MLX) $(NAME)
	@echo "$(GREEN)Fract'ol built$(RESET)"

$(LIB):
	@$(MAKE) -C $(LIBFT_DIR) re

$(MLX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME):
	@gcc $(FLAGS) $(INCLUDE) -o $(NAME) $(SRC) $(NAMELIBFT) -I minilibx -L minilibx -lmlx $(FRAMEWORK)

clean :
	@echo "$(RED)removing .o files$(RESET)"
	@rm -f $(OBJECT)

fclean : clean
	@echo "$(RED)removing libft.a$(RESET)"
	@cd $(LIBFT_DIR) && make fclean
	@echo "$(RED)removing libmlx.a$(RESET)"
	@cd $(MINILIBX_DIR) && make clean
	@echo "$(RED)removing fractol$(RESET)"
	@rm -f $(NAME)

re : fclean all

