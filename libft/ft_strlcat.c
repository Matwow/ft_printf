/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:58:31 by maroard           #+#    #+#             */
/*   Updated: 2025/11/24 11:18:49 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_init_len;
	size_t	i;
	size_t	j;

	dst_init_len = ft_strlen(dst);
	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (j < size - 1 && size > ft_strlen(dst))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	return (dst_init_len + ft_strlen(src));
}
