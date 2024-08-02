/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:15:11 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/16 15:54:42 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h" 

static int	get_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	get_pwr(int unit)
{
	int	pwr;

	pwr = 1;
	while (unit > 1)
	{
		pwr *= 10;
		unit--;
	}
	return (pwr);
}

static char	*get_str(int n, char *s, int len)
{
	int	i;
	int	unit;
	int	chr;

	i = 0;
	unit = len;
	if (n < 0)
	{
		s[i++] = '-';
		unit--;
	}
	else
		n = -n;
	while (i < len)
	{
		chr = (n / get_pwr(unit));
		s[i++] = -chr + '0';
		n -= (chr * get_pwr(unit--));
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = get_len(n);
	if (n < 0)
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s = get_str(n, s, len);
	return (s);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(0));
}*/
