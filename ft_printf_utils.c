/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:04:53 by maroard           #+#    #+#             */
/*   Updated: 2025/11/24 18:14:12 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int	print_int(int n)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len = 1;
	}
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

int	print_hex(unsigned long n, int uppercase)
{
	int	len;

	if (uppercase < 0)
		uppercase = 0;
	else if (uppercase > 1)
		uppercase = 1;
	len = 0;
	if (n >= 16)
	{
		len = print_hex(n / 16, uppercase);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else if (n >= 10 && n <= 15 && uppercase == 1)
		ft_putchar(n + 'A' - 10);
	else if (n >= 10 && n <= 15 && uppercase == 0)
		ft_putchar(n + 'a' - 10);
	return (len + 1);
}

int	print_ptr(void *ptr)
{
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	return (print_hex((unsigned long)ptr, 0) + 2);
}
