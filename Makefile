# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 14:04:43 by eamsalem          #+#    #+#              #
#    Updated: 2024/07/07 16:36:08 by eamsalem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FdF 

CFLAGS = -Wall -Werror -Wextra -g3

OBJDIR = ./build
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBMLXDIR = mlx_linux
LIBMLX = $(LIBMLXDIR)/libmlx_Linux.a

LIBFTDIR = ../libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS =	FdF.c \
		put_pixel.c \
		utils.c \
		events.c \
		draw_line.c \
		draw_grid.c \
		init_fns.c \
		translate_fns.c \
		zoom.c \
		rotate_fns.c \
		file_handling.c \
		free_mem.c

all: $(OBJDIR) $(NAME) $(LIBMLX) $(LIBFT)

$(OBJDIR)/%.o: %.c
	cc $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(LIBMLX) $(LIBFT) $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) -lXext -lX11 -lm -lz -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBMLX):
	make -C $(LIBMLXDIR) all

$(LIBFT):
	make -C $(LIBFTDIR) all

clean:
	make -C $(LIBFTDIR) clean
	rm -fr $(OBJDIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re
