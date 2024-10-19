# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 12:45:26 by codespace         #+#    #+#              #
#    Updated: 2024/10/19 06:40:27 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	=		cub3D

# SRCS_FILES	=	get_map.c \
# 				get_map_utils.c \
# 				error.c \
# 				main.c

# INC_FILES	= cub3d.h

# SRCS	=	$(addprefix src/, $(SRCS_FILES))

# INCS	=	$(addprefix inc/, $(INC_FILES))

# CC		=	clang

# CFLAGS	=	-Wall -Wextra -Werror -I./inc -g3

# INCLUDES	= -I. -Imlx/.

# LIB		= -Lmlx -lmlx -lXext -lX11 -Llibft -lft -lm

# OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)

# OBJS	=		$(addprefix objs/, $(OBJS_FILES))

# DEP		=		$(OBJS:%.o=%.d)

# all		:		$(NAME)

# $(NAME)	:	$(OBJS)
# 	make -C libft
# 	make -C mlx
# 	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

# clean	:
# 	make -C libft fclean
# 	make -C mlx clean
# 	rm -rf $(OBJS) $(DEP)
# 	rm -rf objs/

# fclean	:	clean
# 	rm -rf $(NAME)

# re		:	fclean all

# objs/%.o	: src/%.c $(INCS)
# 	mkdir -p objs
# 	$(CC) $(CFLAGS) -MMD -o $@ -c $<

# .PHONY: all clean fclean re

NAME = cub3d

CC = cc
CFLAGS =  -Wall -Werror -Wextra -g3

RM = rm
RMFLAG = -f

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Imlx -Iinc
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
else ifeq ($(UNAME), Darwin)
	INCLUDES = -I/opt/X11/include -Imlx -Iinc
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -Llibft -lft

SRCS_FILES	=	display_2d.c \
				display_3d.c \
				error.c \
				get_map_utils.c \
				get_map.c \
				hooks.c \
				img.c \
				init.c \
				main.c \
				move.c \
				render.c \
				check_map.c \
				player.c \
				texture_floor.c \
				texture_walls.c \
				raycasting.c \
				texture_utils.c

INC_FILES	= cub3d.h

SRCS	=	$(addprefix src/, $(SRCS_FILES))
INCS	=	$(addprefix inc/, $(INC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)
	if [ -d "./mlx" ]; then make -C $(MLX_DIR) clean; fi
	if [ -d "./libft" ]; then make -C $(LIBFT_DIR) fclean; fi

re: fclean all

.PHONY: all clean run fclean re 