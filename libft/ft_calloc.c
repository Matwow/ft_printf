/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:15:34 by maroard           #+#    #+#             */
/*   Updated: 2025/11/13 16:02:35 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_zone;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	mem_zone = malloc(nmemb * size);
	if (!mem_zone)
		return (NULL);
	ft_bzero(mem_zone, nmemb * size);
	return (mem_zone);
}
