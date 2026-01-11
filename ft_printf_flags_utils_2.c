/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:36:38 by maroard           #+#    #+#             */
/*   Updated: 2026/01/11 22:23:42 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_len(const char *str)
{
	if (!str)
		return (ft_strlen("(null)"));
	return (ft_strlen(str));
}

int	int_len(int n)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len = 1;
	}
	if (nb >= 10)
	{
		len += int_len((int)(nb / 10));
		nb = nb % 10;
	}
	return (len + 1);
}

int	unsigned_int_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

int	hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len = hex_len(n / 16);
	return (len + 1);
}

int	ptr_len(void *ptr)
{
	if (!ptr)
		return (ft_strlen("(nil)"));
	return (hex_len((unsigned long)ptr) + 2);
}
