/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:47:37 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/26 22:57:35 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	if(len == SIZE_MAX)
		return NULL;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, (char *)s1);
	return (dst);
}
