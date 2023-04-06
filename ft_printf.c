/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:22:59 by thclarac          #+#    #+#             */
/*   Updated: 2023/04/06 14:23:02 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_countchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_option(va_list args, char c)
{
	unsigned long long	k;

	if (c == 'c')
		return (ft_put_countchar(va_arg(args, int)));
	if (c == 's')
		return (ft_put_countstr(va_arg(args, char *)));
	if (c == 'p')
	{
		k = va_arg(args, unsigned long long);
		if (k == 0)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		return (ft_ptr(k) + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_put_countnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_put_count_unbr(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		printed_char;
	va_list	args;

	i = 0;
	printed_char = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed_char = ft_option(args, str[i + 1]) + printed_char;
			i++;
		}
		else
			printed_char = ft_put_countchar(str[i]) + printed_char;
		i++;
	}
	va_end(args);
	return (printed_char);
}
