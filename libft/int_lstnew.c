/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:07:52 by eamsalem          #+#    #+#             */
/*   Updated: 2024/06/16 17:07:53 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_lst	*int_lstnew(int content)
{
	t_int_lst	*lst;

	lst = (t_int_lst *)malloc(sizeof(t_int_lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
