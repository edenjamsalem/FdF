/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:34:13 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/03 17:52:42 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int			check_node_for_nl(t_list *line_buff);

int			get_line_len(t_list *line_buff);

void		ft_lstclear_butlast(t_list **lst);

t_list		*ft_lstnew_buf(void);

#endif
