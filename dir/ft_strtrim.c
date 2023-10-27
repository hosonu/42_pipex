/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:45:39 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/25 13:13:06 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_str(char *p, char const *s1, size_t i, size_t j)
{
	size_t	k;

	k = 0;
	while (i < j && s1[i] != '\0')
	{
		p[k] = s1[i];
		i++;
		k++;
	}
	p[k] = '\0';
	return (p);
}

static int	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t		start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	start = get_start(s1, set);
	while (s1[end - 1] != '\0')
	{
		if (ft_strchr(set, s1[end - 1]) == NULL)
			break ;
		end--;
	}
    if(start >= end)
	{
        return (ft_strdup(""));
	}
	p = (char *)malloc(sizeof(char) * (end - start + 1));
	if (p == NULL)
		return (NULL);
	p = get_str(p, s1, start, end);
	return (p);
}

