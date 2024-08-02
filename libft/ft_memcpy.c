/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:52:09 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/15 11:02:40 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	char dest[10];
	char	src[10] = "hello";

	ft_memcpy(dest, src, 6);
	i = 0;
	while (i < 6)
		printf("%c ", dest[i++]);
}*/
