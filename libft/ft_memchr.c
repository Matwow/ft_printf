/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:22:01 by maroard           #+#    #+#             */
/*   Updated: 2025/11/10 16:37:47 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	*sptr;
	unsigned char	cch;

	sptr = (unsigned char *)ptr;
	cch = (unsigned char)ch;
	while (count--)
	{
		if (*sptr++ == cch)
			return (sptr - 1);
	}
	return (0);
}
