/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:54:32 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/20 13:54:33 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putusnbr(unsigned int n)
{
	int		i;
	char	sequence[20];

	if (n > 0)
	{
		i = 0;
		while (n != 0)
		{
			sequence[i++] = n % 10 + '0';
			n = n / 10;
		}
		sequence[i--] = '\0';
		while (i >= 0)
			write(1, &sequence[i--], 1);
	}
	else
		return (ft_putchar_count('0'));
	return (ft_strlen(sequence));
}
