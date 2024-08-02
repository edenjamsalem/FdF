/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:07:13 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/16 17:07:15 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_lstclear(t_int_lst **lst)
{
	t_int_lst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
