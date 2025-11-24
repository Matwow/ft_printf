/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:53:14 by maroard           #+#    #+#             */
/*   Updated: 2025/11/24 11:07:51 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	char	*empty;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		empty = malloc(1);
		if (!empty)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	i = 0;
	substring = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (len > 0)
	{
		substring[i++] = s[start++];
		len--;
	}
	return (substring);
}
