/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:04:15 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/27 17:56:33 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	separator(char s, char sep)
{
	if (s == sep)
		return (1);
	if (s == '\0')
		return (1);
	return (0);
}

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (separator(s[i], c) == 0 && separator(s[i + 1], c) == 1)
			words++;
		i++;
	}
	return (words);
}

static size_t	strlen_c(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (separator(s[len], c) == 0)
		len++;
	return (len);
}

static char	**get_arr(char const *s, char c, size_t words, char **arr)
{
	size_t	i;

	i = 0;
	while (words--)
	{
		while (separator(*s, c) == 1)
			s++;
		arr[i] = ft_substr(s, 0, strlen_c(s, c));
		if (arr[i] == NULL)
		{
			while (--i)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i++;
		s += strlen_c(s, c);
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	if (words == SIZE_MAX)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	arr[words] = 0;
	arr = get_arr(s, c, words, arr);
	return (arr);
}
