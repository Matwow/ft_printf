/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:36:38 by maroard           #+#    #+#             */
/*   Updated: 2026/01/19 17:43:01 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_len_with_precision(t_bool dot_active, int precision, char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		if (dot_active && precision < (int)ft_strlen("(null)"))
			return (0);
		return (ft_strlen("(null)"));
	}
	if (precision == 0 || precision > (int)ft_strlen(str))
		return (ft_strlen(str));
	while (precision > 0 && *str)
	{
		--precision;
		++len;
		str++;
	}
	return (len);
}

int	int_len(int n)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
		nb = -nb;
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
		len = 1;
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
	return (hex_len((unsigned long)ptr));
}
