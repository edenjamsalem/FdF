# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 14:04:43 by eamsalem          #+#    #+#              #
#    Updated: 2024/09/25 19:08:58 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FdF 

CFLAGS = -Wall -Werror -Wextra -g3 -arch arm64

SRCDIR = ./srcs
SRCS =	$(SRCDIR)/FdF.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/events.c \
		$(SRCDIR)/draw_line.c \
		$(SRCDIR)/draw_model.c \
		$(SRCDIR)/init_fns.c \
		$(SRCDIR)/rotation.c \
		$(SRCDIR)/zoom_shift.c \
		$(SRCDIR)/file_handling.c \
		$(SRCDIR)/free_fns.c \
		$(SRCDIR)/img_fns.c \
		$(SRCDIR)/colours.c \

OBJDIR = ./build
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

MLXDIR = mlx_mac
MLXLIB = $(MLXDIR)/libmlx.a

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(OBJDIR) $(NAME) $(MLXLIB) $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	cc $(CFLAGS) -I/usr/include -I$(MLXDIR) -I$(SRCDIR) -c $< -o $@

$(NAME): $(MLXLIB) $(LIBFT) $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(MLXLIB) $(LIBFT) -framework OpenGL -framework AppKit -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(MLXLIB):
	make -C $(MLXDIR) all

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
