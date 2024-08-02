/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:30:11 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/14 11:31:31 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum('\n'));
}*/
