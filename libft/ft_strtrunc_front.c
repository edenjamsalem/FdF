/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:41:43 by eamsalem          #+#    #+#             */
/*   Updated: 2024/07/07 15:44:23 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrunc_front(char *str, unsigned int chr_count)
{
	char			*trunc_str;
	unsigned int	i;
	unsigned int	j;

	if (chr_count > ft_strlen(str) || chr_count == 0 || !str)
		return (NULL);
	trunc_str = malloc(sizeof(char) * (ft_strlen(str) - chr_count + 1));
	i = chr_count;
	j = 0;
	while (str[i])
		trunc_str[j++] = str[i++];
	trunc_str[j] = '\0';
	free (str);
	return (trunc_str);
}
