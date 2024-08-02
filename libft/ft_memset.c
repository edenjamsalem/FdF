/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:18:23 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/14 17:58:27 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	int	j = 0;
	char	memset[10];

	ft_memset(memset, 'A', 6);

	while (j < 6)
		printf("%c ", memset[j++]);
}*/
