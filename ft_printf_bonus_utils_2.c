/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:15:25 by maroard           #+#    #+#             */
/*   Updated: 2026/01/19 19:17:36 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *f)
{
	f->minus = FALSE;
	f->zero = FALSE;
	f->dot = FALSE;
	f->hash = FALSE;
	f->space = FALSE;
	f->plus = FALSE;
	f->precision = 0;
	f->width = 0;
	f->padding = 0;
	f->skip = 0;
}

void	update_flags(t_flags *f, const char type)
{
	if (type == '-')
		f->minus = TRUE;
	else if (type == '0')
		f->zero = TRUE;
	else if (type == '.')
		f->dot = TRUE;
	else if (type == '#')
		f->hash = TRUE;
	else if (type == ' ')
		f->space = TRUE;
	else if (type == '+')
		f->plus = TRUE;
}

void	flags_priorities(t_flags *f, char type)
{
	if (type != 'd' && type != 'i')
	{
		f->plus = FALSE;
		f->space = FALSE;
	}
	if (type != 'x' && type != 'X')
		f->hash = FALSE;
	if (type != 'd' && type != 'i' && type != 'u'
		&& type != 'x' && type != 'X' && type != 's')
		f->dot = FALSE;
	if (f->minus || f->dot
		|| (type != 'd' && type != 'i'
			&& type != 'u' && type != 'x' && type != 'X'))
		f->zero = FALSE;
	if (f->plus)
		f->space = FALSE;
}

t_bool	is_flag(const char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (TRUE);
	return (FALSE);
}
