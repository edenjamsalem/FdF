/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:45:22 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:56 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h> 
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int			ft_isalpha(char c);

int			ft_isdigit(char c);

int			ft_isalnum(char c);

int			ft_isprint(int c);

int			ft_issign(int c);

size_t		ft_strlcpy(char *dest, const char *src, size_t size);

size_t		ft_strlen(const char *str);

size_t		ft_strlcat(char *dest, const char *src, size_t size);

int			ft_toupper(int c);

int			ft_tolower(int c);

const char	*ft_strrchr(const char *s, int c);

const char	*ft_strchr(const char *s, int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		*ft_memcpy(void *dest, const void *src, size_t n);

const char	*ft_strnstr(const char *big, const char *little, size_t len);

int			ft_atoi(const char *str);

void		*ft_memset(void *s, int c, size_t n);

void		*ft_bzero(void *s, size_t n);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);

int			ft_isascii(int c);

char		*ft_strdup(const char *s);

void		*ft_memmove(void *dest, const void *src, size_t n);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s1, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);

void		ft_lstadd_front(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst);

void		ft_lstclear(t_list **lst);

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *));

int			chrsetcmp(char c, char *set);

int			intsetcmp(int c, int *set, int size);

int			ft_putaddr(void *ptr);

int			ft_putchar_count(char c);

int			ft_putnbr_base(unsigned int nbr, char *base);

int			ft_putnbr_count(int n);

int			ft_putstr_count(char *s);

int			ft_putuslong_base(unsigned long nbr, char *base);

int			ft_putusnbr(unsigned int n);

int			ft_printf(const char *format, ...);

int			*int_arrlcpy(int *dest, int *src, int size);

int			*int_arrtrunc(int *src, int size);

typedef struct t_int_lst
{
	int					content;
	struct t_int_lst	*next;
	struct t_int_lst	*prev;
}	t_int_lst;

t_int_lst	*int_lstnew(int content);

void		int_lstadd_front(t_int_lst **lst, t_int_lst *new);

int			int_lstsize(t_int_lst *lst);

t_int_lst	*int_lstlast(t_int_lst *lst);

void		int_lstadd_back(t_int_lst **lst, t_int_lst *new);

void		int_lstdelone(t_int_lst *lst);

void		int_lstdel_front(t_int_lst **lst);

void		int_lstclear(t_int_lst **lst);

int			*int_lst_to_arr(t_int_lst *lst, int size);

void		ft_swap(int *a, int *b);

void		bubble_sort_arr(int *arr, int size);

void		rev_bubble_sort_arr(int *arr, int size);

void		free_2darr(void **arr, int len);

int			ft_2darr_len(void **arr);

char		*get_next_line(int fd);

char		*ft_strtrunc_front(char *str, unsigned int chr_count);

long		ft_atol(const char *str);

int			ft_atoi_base(char *str, char *base);

#endif
