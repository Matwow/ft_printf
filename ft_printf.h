/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:36:09 by maroard           #+#    #+#             */
/*   Updated: 2026/01/19 18:56:18 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

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
	int		precision;
	int		width;
	int		padding;
	int		skip;
}			t_flags;

typedef union u_arg
{
	char			c;
	char			*s;
	void			*p;
	int				i;
	unsigned int	u;
	double			f;
}					t_arg;

typedef struct s_len
{
	int	sign;
	int	prefix;
	int	precision_zeros;
	int	digits;
	int	padding;
}		t_len;

int		print_str(char *str);
int		print_str_n(char *str, int n);
int		print_int(int n);
int		print_unsigned_int(unsigned int n);
int		print_hex(unsigned long n, t_bool uppercase);
int		print_ptr(void *ptr);
int		print_double(double n);

int		string_len_with_precision(t_bool dot_active, int precision, char *str);
int		int_len(int n);
int		unsigned_int_len(unsigned int n);
int		hex_len(unsigned long n);
int		ptr_len(void *ptr);

void	init_flags(t_flags *f);
void	update_flags(t_flags *f, const char type);
t_bool	is_flag(const char c);
char	parse_format(t_flags *f, const char *s);
void	flags_priorities(t_flags *f, const char type);
void	read_argument(char type, t_arg *arg, va_list *arg_p);
void	compute_lengths(t_flags *f, t_arg *arg, const char type, t_len *len);

int		print_padding(int padding_len, char padding_char);
int		print_sign(char sign);
int		print_prefix(char type);
int		print_precision(int precision_zeros);

int		ft_printf(const char *s, ...);

#endif