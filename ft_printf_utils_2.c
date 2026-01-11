/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:57:47 by maroard           #+#    #+#             */
/*   Updated: 2026/01/11 18:15:35 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_double(double n)
{
	int	int_part;
	int	decimal;
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len += print_str("-");
	}
	int_part = (int)n;
	decimal = (int)((n - int_part) * 100);
	len += print_int(int_part);
	if (decimal < 10)
		len += print_str(".0");
	else
		len += print_str(".");
	len += print_int(decimal);
	return (len);
}
