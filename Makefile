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
LIBMLX = $(LIBMLXDIR)/libmlx.a

SRCS = FdF.c

all: $(OBJDIR) $(NAME) $(LIBMLX)

$(OBJDIR)/%.o: %.c
	cc $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(LIBMLX) $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBMLX) -lXext -lX11 -lm -lz -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBMLX):
	make -C $(LIBMLXDIR) all

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re
