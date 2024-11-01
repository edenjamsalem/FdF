/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:26:12 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/16 15:29:16 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_digits(int n, int fd)
{
	int		i;
	char	sequence[12];

	i = 0;
	while (n != 0)
	{
		sequence[i] = -(n % 10) + '0';
		n = n / 10;
		if (n < 0)
			i++;
	}
	while (i >= 0)
		write(fd, &sequence[i--], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
	{
		n = n * (-1);
		print_digits(n, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		print_digits(n, fd);
	}
	else
		write(fd, "0", 1);
}
