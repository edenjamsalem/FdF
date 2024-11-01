# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 11:52:54 by eamsalem          #+#    #+#              #
#    Updated: 2024/06/12 16:17:56 by eamsalem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJDIR =./build

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		chrsetcmp.c \
		ft_putaddr.c \
		ft_putchar_count.c \
		ft_putnbr_base.c \
		ft_putnbr_count.c \
		ft_putstr_count.c \
		ft_putuslong_base.c \
		ft_putusnbr.c \
		ft_printf.c \
		intsetcmp.c \
		int_arrlcpy.c \
		int_arrtrunc.c \
		int_lst_to_arr.c \
		int_lstnew.c \
		int_lstadd_back.c \
		int_lstadd_front.c \
		int_lstdel_front.c \
		int_lstlast.c \
		int_lstsize.c \
		int_lstclear.c \
		ft_swap.c \
		bubble_sort.c \
		ft_issign.c \
		free_2darr.c \
		ft_2darr_len.c	\
		get_next_line.c \
		get_next_line_utils.c \
		ft_strtrunc_front.c \
		ft_atol.c \
		ft_atoi_base.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: $(OBJS) 
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re bonus
