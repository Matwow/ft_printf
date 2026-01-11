/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:15:25 by maroard           #+#    #+#             */
/*   Updated: 2026/01/11 22:06:57 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	init_flags(t_flags *f)
{
	f->minus = FALSE;
	f->zero = FALSE;
	f->dot = FALSE;
	f->hash = FALSE;
	f->space = FALSE;
	f->plus = FALSE;
	f->width = 0;
}

static void	flags_updater(t_flags *f, const char flag_char)
{
	if (flag_char == '-')
		f->minus = TRUE;
	else if (flag_char == '0')
		f->zero = TRUE;
	else if (flag_char == '.')
		f->dot = TRUE;
	else if (flag_char == '#')
		f->hash = TRUE;
	else if (flag_char == ' ')
		f->space = TRUE;
	else if (flag_char == '+')
		f->plus = TRUE;
}

t_bool	in_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (TRUE);
	}
	return (FALSE);
}

char	parse_format_specifier(t_flags *f, const char *s)
{
	size_t		i;
	t_bool		width_started;
	long long	width;

	i = 0;
	width_started = FALSE;
	width = 0;
	while (1)
	{
		if ((s[i] == '0' && !width_started)
			|| (in_set(s[i], "-0.# +") && s[i] != '0'))
			flags_updater(f, s[i]);
		else if (ft_isdigit(s[i]))
		{
			width_started = TRUE;
			width = width * 10 + s[i] - '0';
		}
		else
			break ;
		if (width > INT_MAX)
			width = INT_MAX;
		++i;
	}
	f->width = (int)width;
	return (s[i]);
}

void	flags_priorities(t_flags *f, const char convert_type)
{
	if (f->minus && f->zero)
		f->zero = FALSE;
	if (f->plus && f->space)
		f->space = FALSE;
	if (convert_type != 'd' && convert_type != 'i')
	{
		f->plus = FALSE;
		f->space = FALSE;
	}
	if (convert_type != 'x' && convert_type != 'X')
		f->hash = FALSE;
}
