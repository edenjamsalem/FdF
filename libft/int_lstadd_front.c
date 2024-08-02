/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:06:51 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/16 17:06:52 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_lstadd_front(t_int_lst **lst, t_int_lst *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
}
