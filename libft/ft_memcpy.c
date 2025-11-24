/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:57:58 by maroard           #+#    #+#             */
/*   Updated: 2025/11/10 16:37:51 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;

	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	while (count--)
		*sdest++ = *ssrc++;
	return (dest);
}
