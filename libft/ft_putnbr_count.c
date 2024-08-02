/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:50:11 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/15 15:13:16 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_digits_count(int n)
{
	int		i;
	char	sequence[12];

	i = 0;
	while (n != 0)
	{
		sequence[i] = -(n % 10) + '0';
		n = n / 10;
		i++;
	}
	sequence[i--] = '\0';
	while (i >= 0)
		write(1, &sequence[i--], 1);
	return (ft_strlen(sequence));
}

int	ft_putnbr_count(int n)
{
	int	count;

	count = 0;
	if (n > 0)
	{
		n = n * (-1);
		count = print_digits_count(n);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		count = (print_digits_count(n) + 1);
	}
	else
		return (ft_putchar_count('0'));
	return (count);
}
