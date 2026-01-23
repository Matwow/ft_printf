/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:04:53 by maroard           #+#    #+#             */
/*   Updated: 2026/01/19 19:18:06 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar(*str++);
		++len;
	}
	return (len);
}

int	print_str_n(char *str, int n)
{
	int		len;

	len = 0;
	if (!str)
	{
		if (n < (int)ft_strlen("(null)"))
			return (0);
		return (print_str("(null)"));
	}
	while (*str && n > 0)
	{
		ft_putchar(*str++);
		--n;
		++len;
	}
	return (len);
}

int	print_int(int n)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		len += print_int((int)(nb / 10));
		nb = nb % 10;
	}
	ft_putchar(nb + '0');
	return (len + 1);
}

int	print_unsigned_int(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = print_unsigned_int(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
	return (len + 1);
}

int	print_hex(unsigned long n, t_bool uppercase)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len = print_hex(n / 16, uppercase);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else if (n >= 10 && n <= 15 && uppercase)
		ft_putchar(n + 'A' - 10);
	else if (n >= 10 && n <= 15 && !uppercase)
		ft_putchar(n + 'a' - 10);
	return (len + 1);
}
