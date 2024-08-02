/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:10:56 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/15 15:23:02 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	int		concat_len;
	int		i;
	int		j;

	concat_len = ft_strlen(s1) + ft_strlen(s2);
	concat_str = malloc(sizeof(char) * (concat_len + 1));
	if (!concat_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		concat_str[i++] = s2[j++];
	concat_str[i] = '\0';
	return (concat_str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strjoin("hello", "goodbye"));
}*/
