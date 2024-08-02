/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:06:42 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/16 17:06:45 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_lstadd_back(t_int_lst **lst, t_int_lst *new)
{
	if (*lst)
	{
		int_lstlast(*lst)->next = new;
		new->prev = int_lstlast(*lst);
	}
	else
		*lst = new;
}
