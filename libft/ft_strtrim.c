/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:05:14 by maroard           #+#    #+#             */
/*   Updated: 2025/11/26 13:58:05 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

static char	*empty_str()
{
	char	*str;

	str = malloc(1);
	str[0] = '\0';
	return (str);
}

static int	in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (in_set(s1[i], set))
		i++;
	while (in_set(s1[j], set) && j > 0)
		j--;
	if (i < j)
		str = ft_substr(s1, i, j - i + 1);
	else if (i == j)
	{
		str = malloc(2);
		str[0] = s1[i];
		str[1] = '\0';
		return (str);
	}
	else
		return (empty_str());
	return (str);
}
