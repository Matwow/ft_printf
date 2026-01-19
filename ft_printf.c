/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:35:42 by maroard           #+#    #+#             */
/*   Updated: 2026/01/19 19:15:56 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int	dispatcher(const char type, t_arg *arg, t_flags *f)
{
	if (type == 'c')
		return (ft_putchar(arg->c), 1);
	if (type == 's' && !f->dot)
		return (print_str(arg->s));
	if (type == 's')
		return (print_str_n(arg->s, f->precision));
	if (type == 'p')
		return (print_ptr(arg->p));
	if (type == 'd' || type == 'i')
		return (print_int(arg->i));
	if (type == 'u')
		return (print_unsigned_int(arg->u));
	if (type == 'x')
		return (print_hex(arg->u, FALSE));
	if (type == 'X')
		return (print_hex(arg->u, TRUE));
	if (type == '%')
		return (ft_putchar('%'), 1);
	if (type == 'f')
		return (print_double(arg->f));
	return (0);
}

static int	print_formatted(t_flags *f, t_len *len, const char type, t_arg *arg)
{
	int	total_len;

	total_len = 0;
	if (!f->minus && !f->zero)
		total_len += print_padding(len->padding, ' ');
	if ((type == 'd' || type == 'i') && arg->i < 0)
		total_len += print_sign('-');
	else if ((type == 'd' || type == 'i') && f->plus)
		total_len += print_sign('+');
	else if ((type == 'd' || type == 'i') && f->space)
		total_len += print_sign(' ');
	if ((type == 'p' && arg->p != NULL)
		|| ((type == 'x' || type == 'X') && f->hash && arg->u != 0))
		total_len += print_prefix(type);
	if (!f->minus && !f->dot && f->zero)
		total_len += print_padding(len->padding, '0');
	else if (f->dot && len->precision_zeros != 0)
		total_len += print_precision(len->precision_zeros);
	if (len->digits > 0)
		total_len += dispatcher(type, arg, f);
	if (f->minus)
		total_len += print_padding(len->padding, ' ');
	return (total_len);
}

static int	format_manager(t_flags **f, const char *s, va_list *arg_p)
{
	char	type;
	t_arg	*arg;
	t_len	*format_lengths;
	int		len;

	*f = malloc(sizeof(t_flags));
	if (!(*f))
		return (-1);
	init_flags((*f));
	type = parse_format((*f), s);
	flags_priorities((*f), type);
	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (-1);
	read_argument(type, arg, arg_p);
	format_lengths = malloc(sizeof(t_len));
	if (!format_lengths)
		return (free(arg), -1);
	compute_lengths((*f), arg, type, format_lengths);
	len = print_formatted((*f), format_lengths, type, arg);
	free(arg);
	free(format_lengths);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_p;
	int		i;
	int		s_len;
	t_flags	*f;

	va_start(arg_p, s);
	i = 0;
	s_len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			s_len += format_manager(&f, s + ++i, &arg_p);
			i += f->skip + 1;
			free(f);
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
