/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:53:01 by maroard           #+#    #+#             */
/*   Updated: 2025/11/13 15:58:47 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*sptr1;
	const unsigned char	*sptr2;
	unsigned char		a;
	unsigned char		b;

	sptr1 = (const unsigned char *)ptr1;
	sptr2 = (const unsigned char *)ptr2;
	while (n--)
	{
		a = *sptr1++;
		b = *sptr2++;
		if (a != b)
			return ((int)a - (int)b);
	}
	return (0);
}
