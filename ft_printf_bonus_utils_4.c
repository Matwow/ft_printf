/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:37:03 by maroard           #+#    #+#             */
/*   Updated: 2026/01/19 19:16:11 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(int padding_len, char padding_char)
{
	int	len;

	len = padding_len;
	while (padding_len > 0)
	{
		ft_putchar(padding_char);
		--padding_len;
	}
	return (len);
}

int	print_sign(char sign)
{
	ft_putchar(sign);
	return (1);
}

int	print_prefix(char type)
{
	if (type == 'X')
		ft_putstr("0X");
	else
		ft_putstr("0x");
	return (2);
}

int	print_precision(int precision_zeros)
{
	int	len;

	len = precision_zeros;
	while (precision_zeros > 0)
	{
		ft_putchar('0');
		--precision_zeros;
	}
	return (len);
}
