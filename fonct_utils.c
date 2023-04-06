/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:22:30 by thclarac          #+#    #+#             */
/*   Updated: 2023/04/06 14:22:35 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_count_unbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i = i + ft_put_count_unbr(nbr / 10);
		i = i + ft_put_count_unbr(nbr % 10);
	}
	else
		i = i + ft_put_countchar(nbr + 48);
	return (i);
}

int	ft_put_countstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr > 15)
	{
		i += ft_ptr(ptr / 16);
		i += ft_ptr(ptr % 16);
	}
	else
	{
		if (ptr >= 10)
			i = i + ft_put_countchar('a' + ptr - 10);
		else
			i = i + ft_put_countchar('0' + ptr);
	}
	return (i);
}

int	ft_put_countnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		i = i + ft_put_countstr("-2147483648");
	else
	{
		if (nbr < 0)
		{
			i = i + write(1, "-", 1);
			nbr *= -1;
		}
		if (nbr > 9)
		{
			i = i + ft_put_countnbr(nbr / 10);
			i = i + ft_put_countnbr(nbr % 10);
		}
		else
			i = i + ft_put_countchar(nbr + 48);
	}
	return (i);
}

int	ft_hex(unsigned int nbr, char c)
{
	int	option;
	int	i;

	option = 0;
	i = 0;
	if (c == 'X')
		option = 32;
	if (nbr == 0)
		i = i + write(1, "0", 1);
	else
	{
		if (nbr > 15)
		{
			i = i + ft_hex(nbr / 16, c);
			i = i + ft_hex(nbr % 16, c);
		}
		else
		{
			if (nbr >= 10)
				i = i + ft_put_countchar('a' + nbr - 10 - option);
			else
				i = i + ft_put_countchar('0' + nbr);
		}
	}
	return (i);
}
