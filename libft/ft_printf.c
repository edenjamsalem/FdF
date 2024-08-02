/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:13:46 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/20 14:53:22 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h" 

static int	print_arg(char format_specifier, va_list args)
{
	if (format_specifier == 'c')
		return (ft_putchar_count((char)va_arg(args, int)));
	else if (format_specifier == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	else if (format_specifier == 'p')
		return (ft_putaddr(va_arg(args, void *)));
	else if (format_specifier == 'd' || format_specifier == 'i')
		return (ft_putnbr_count(va_arg(args, int)));
	else if (format_specifier == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format_specifier == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format_specifier == 'u')
		return (ft_putusnbr(va_arg(args, unsigned int)));
	else if (format_specifier == '%')
		return (ft_putchar_count('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*specifiers_set;
	int		i;
	int		count;

	specifiers_set = "cspdiuxX%";
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (chrsetcmp(format[i], "%"))
		{
			if (chrsetcmp(format[i + 1], specifiers_set))
				count += print_arg(format[i++ + 1], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	n1 = 1234;
	int	n2 = 5678;
	char *name = "Eden";
	char chr = 'E';

	printf("%d\n", ft_printf("number 1 = %p\n", &n1));
	printf("%d\n", ft_printf("number 1 = %d, number 2 = %i\n", n1, n2));
	printf("%d\n", ft_printf("str = %s\n", name));
	printf("%d\n", ft_printf("chr 1 = %c\n", chr));
	printf("%d\n", ft_printf("number 1 = %u\n", n1));
	printf("%d\n", ft_printf("number 1 = %x\n", n1));
	printf("%d\n", ft_printf("%X\n", n1));
	printf("length = %d\n", ft_printf("%%\n"));
	printf("%d\n", ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 "));
	printf("%d\n", printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 "));
}*/
