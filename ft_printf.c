/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:35:42 by maroard           #+#    #+#             */
/*   Updated: 2025/11/24 18:37:12 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
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
			ft_putchar(s[i]);
			i++;
			s_len++;
		}
	}
	va_end(arg_p);
	return (s_len);
}

// #include <stdio.h>

// int main(void)
// {
//     int     expected_output;
//     int     output;
//     int     i = 42;

//     printf("\n====== TESTS CLASSIQUES ======\n");

//     expected_output = printf("O: Hello\n");
//     output = ft_printf("M: Hello\n");
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %d\n", 42);
//     output = ft_printf("M: %d\n", 42);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %i\n", -42);
//     output = ft_printf("M: %i\n", -42);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %u\n", 4294967295u);
//     output = ft_printf("M: %u\n", 4294967295u);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %x\n", 255);
//     output = ft_printf("M: %x\n", 255);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %X\n", 255);
//     output = ft_printf("M: %X\n", 255);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %c\n", 'A');
//     output = ft_printf("M: %c\n", 'A');
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %s\n", "salut frero");
//     output = ft_printf("M: %s\n", "salut frero");
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %%\n");
//     output = ft_printf("M: %%\n");
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     printf("\n====== TESTS COMBINAISONS ======\n");

//     expected_output = printf("O: Salut %d frero %s!\n", 42, "Mathias");
//     output = ft_printf("M: Salut %d frero %s!\n", 42, "Mathias");
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %d%d%d%d\n", 1, 2, 3, 4);
//     output = ft_printf("M: %d%d%d%d\n", 1, 2, 3, 4);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: HeyBro! %s%c%s%c\n", "He", 'y', "Bro", '!');
//     output = ft_printf("M: HeyBro! %s%c%s%c\n", "He", 'y', "Bro", '!');
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     printf("\n====== TESTS LIMITES ======\n");

//     expected_output = printf("O: %d\n", -2147483648);
//     output = ft_printf("M: %d\n", -2147483648);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %d\n", 2147483647);
//     output = ft_printf("M: %d\n", 2147483647);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %u\n", 0u);
//     output = ft_printf("M: %u\n", 0u);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %u\n", 4294967295u);
//     output = ft_printf("M: %u\n", 4294967295u);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %x\n", 0);
//     output = ft_printf("M: %x\n", 0);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %x\n", 4294967295u);
//     output = ft_printf("M: %x\n", 4294967295u);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     printf("\n====== TESTS SUR %%p ======\n");

//     expected_output = printf("O: %p\n", &i);
//     output = ft_printf("M: %p\n", &i);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %p\n", NULL);
//     output = ft_printf("M: %p\n", NULL);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     printf("\n====== TESTS SUR %%s NULL ======\n");

//     expected_output = printf("O: %s\n", NULL);
//     output = ft_printf("M: %s\n", NULL);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     printf("\n====== TESTS DE PARSING BIZARRES ======\n");

//     expected_output = printf("O: %dsalut%d42\n", 10, 999);
//     output = ft_printf("M: %dsalut%d42\n", 10, 999);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %%d%s%d%%\n", "ok", 55);
//     output = ft_printf("M: %%d%s%d%%\n", "ok", 55);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %%%%c%%\n", 'X');
//     output = ft_printf("M: %%%%c%%\n", 'X');
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     expected_output = printf("O: %x%x%s%x\n", 1, 2, "yo", 3);
//     output = ft_printf("M: %x%x%s%x\n", 1, 2, "yo", 3);
//     printf("expected=%d | output=%d\n\n", expected_output, output);

//     return (0);
// }
