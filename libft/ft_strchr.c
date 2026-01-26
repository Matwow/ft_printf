/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:07:40 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 09:52:56 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		if (!s[i])
			break ;
		++i;
	}
	return (NULL);
}
