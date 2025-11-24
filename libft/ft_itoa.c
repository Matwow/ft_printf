/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:55:18 by maroard           #+#    #+#             */
/*   Updated: 2025/11/13 16:16:10 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

static char	*special_cases(int n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc((1 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "0\0", 2);
		return (str);
	}
	if (n == -2147483648)
	{
		str = malloc((11 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (NULL);
}

static size_t	count_digits(int n)
{
	size_t	nb_digits;

	nb_digits = 0;
	while (n >= 1)
	{
		n /= 10;
		nb_digits += 1;
	}
	return (nb_digits);
}

static char	*convert(char *str, int n, int i, int is_negative)
{
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = (n - (n % 10)) / 10;
		i--;
	}
	if (is_negative == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				i;
	int				is_negative;
	unsigned int	nb_digits;

	if (n == 0 || n == -2147483648)
		return (special_cases(n));
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	nb_digits = count_digits(n);
	result = malloc((is_negative + nb_digits + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = is_negative + nb_digits - 1;
	convert(result, n, i, is_negative);
	return (result);
}
