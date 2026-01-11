/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:36:09 by maroard           #+#    #+#             */
/*   Updated: 2026/01/11 22:31:47 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_flags
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	hash;
	t_bool	space;
	t_bool	plus;
	int		width;
}			t_flags;


int		print_str(char *str);
int		print_int(int n);
int		print_unsigned_int(unsigned int n);
int		print_hex(unsigned long n, int uppercase);
int		print_ptr(void *ptr);
int		print_double(double n);

void    init_flags(t_flags *f);
t_bool	in_set(const char c, const char *set);
char	parse_format_specifier(t_flags *f, const char *s);
void	flags_priorities(t_flags *f, char convert_type);

int	ft_printf(const char *s, ...);

#endif