/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:35:42 by maroard           #+#    #+#             */
/*   Updated: 2025/11/26 16:08:25 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	dispatcher(char convert_type, va_list *arg_p)
{
	if (convert_type == 'c')
	{
		ft_putchar(va_arg(*arg_p, int));
		return (1);
	}
	if (convert_type == 's')
		return (print_str(va_arg(*arg_p, char *)));
	if (convert_type == 'p')
		return (print_ptr(va_arg(*arg_p, void *)));
	if (convert_type == 'd' || convert_type == 'i')
		return (print_int(va_arg(*arg_p, int)));
	if (convert_type == 'u')
		return (print_unsigned_int(va_arg(*arg_p, unsigned int)));
	if (convert_type == 'x')
		return (print_hex(va_arg(*arg_p, unsigned int), 0));
	if (convert_type == 'X')
		return (print_hex(va_arg(*arg_p, unsigned int), 1));
	if (convert_type == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	arg_p;
	int		s_len;

	i = 0;
	va_start(arg_p, s);
	s_len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			s_len += dispatcher(s[++i], &arg_p);
			i++;
		}
		else
		{
			ft_putchar(s[i++]);
			s_len++;
		}
	}
	va_end(arg_p);
	return (s_len);
}
