/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:05:14 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 10:50:13 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_bool	in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (TRUE);
	}
	return (FALSE);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (in_set(s1[i], set))
		++i;
	j = ft_strlen(s1) - 1;
	while (in_set(s1[j], set) && j > 0)
		--j;
	if (i < j)
		str = ft_substr(s1, i, j - i + 1);
	else if (i == j)
		return (str = malloc(2), str[0] = s1[i], str[1] = '\0', str);
	else
		return (str = malloc(1), str[0] = '\0', str);
	return (str);
}
