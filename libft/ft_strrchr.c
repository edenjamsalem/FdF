/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:39:36 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/15 11:35:09 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

const char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return (&s[i]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%p\n", ft_strrchr("hello", 'l'));
	printf("%p\n", ft_strrchr("hello", 'b'));
	printf("%p\n", ft_strrchr("hello", '\0'));
}*/
