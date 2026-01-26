/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:31:49 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 10:08:31 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && *big)
	{
		j = 0;
		k = i;
		while (k < len && *big && big[k] == little[j])
		{
			++k;
			++j;
			if (!little[j])
				return ((char *)big + i);
		}
		++i;
	}
	return (NULL);
}
