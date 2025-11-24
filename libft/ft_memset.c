/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:57:07 by maroard           #+#    #+#             */
/*   Updated: 2025/11/10 16:37:58 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*p;
	unsigned char	c;

	c = (unsigned char)value;
	p = (unsigned char *)pointer;
	while (count--)
		*p++ = c;
	return (pointer);
}
