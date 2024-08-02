/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_lstdel_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:07:03 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/16 17:07:04 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_lstdel_front(t_int_lst **lst)
{
	t_int_lst	*tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		if (*lst)
			(*lst)->prev = NULL;
		else
			*lst = NULL;
	}
}
