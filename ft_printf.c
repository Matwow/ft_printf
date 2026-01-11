/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:35:42 by maroard           #+#    #+#             */
/*   Updated: 2026/01/11 22:39:20 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	dispatcher(const char convert_type, va_list *arg_p)
{
	if (convert_type == 'c')
		return (ft_putchar(va_arg(*arg_p, int)), 1);
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
		return (ft_putchar('%'), 1);
	if (convert_type == 'f')
		return (print_double(va_arg(*arg_p, double)));
	return (0);
}

static int	pre_count_dispatcher(const char convert_type, va_list copy)
{
	if (!in_set(convert_type, "spdiuxX"))
		return (1);
	if (convert_type == 's')
		return (str_len(va_arg(copy, char *)));
	if (convert_type == 'p')
		return (ptr_len(va_arg(copy, void *)));
	if (convert_type == 'd' || convert_type == 'i')
		return (int_len(va_arg(copy, int)));
	if (convert_type == 'u')
		return (unsigned_int_len(va_arg(copy, unsigned int)));
	if (convert_type == 'x' || convert_type == 'X')
		return (hex_len(va_arg(copy, unsigned int)));
	return (0);
}

static int	flags_manager(va_list arg_p, const char *s)
{
	va_list	copy;
	t_flags	*f;
	char	convert_type;
	int		raw_len;
	int		extra_len;
	int		padding;

	va_copy(copy, arg_p);
	f = malloc(sizeof(t_flags));
	if (!f)
		return (0);
	init_flags(f);
	convert_type = parse_format_specifier(f, s);
	raw_len = pre_count_dispatcher(convert_type, copy);
	flags_priorities(f, convert_type);
	if ((convert_type == 'd' || convert_type == 'i') && raw_len >= 0 && f->plus)
		++extra_len;
	else if ((convert_type == 'd' || convert_type == 'i') && raw_len >= 0 && f->space)
		++extra_len;
	if ((convert_type == 'x' || convert_type == 'X') && raw_len != 0 && f->hash)
		extra_len += 2;
	va_end(copy);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_p;
	size_t	i;
	size_t	s_len;

	va_start(arg_p, s);
	i = 0;
	s_len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			s_len += dispatcher(s[++i], &arg_p);
			++i;
		}
		else
		{
			ft_putchar(s[i++]);
			++s_len;
		}
	}
	va_end(arg_p);
	return (s_len);
}
