/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:10:23 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 10:06:05 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	t_bool	is_word;

	i = 0;
	count = 0;
	is_word = FALSE;
	while (s[i] != '\0')
	{
		if (s[i] != c && !is_word)
		{
			is_word = TRUE;
			++count;
		}
		else if (s[i] == c)
			is_word = FALSE;
		++i;
	}
	return (count);
}

static char	*create_string(char const *s, char c)
{
	size_t	len;
	char	*string;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		++len;
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (*s && s[i] != c)
	{
		string[i] = s[i];
		++i;
	}
	string[i] = '\0';
	return (string);
}

static void	*free_split(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			tab[i++] = create_string(s, c);
			if (!tab[i - 1])
				return (free_split(tab, i - 1));
		}
		while (*s && *s != c)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
