/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:07:40 by maroard           #+#    #+#             */
/*   Updated: 2025/11/18 12:35:00 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_isascii(int c);

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (ft_isascii(c) == 0)
		return ((char *)s);
	while (s[i] >= '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
