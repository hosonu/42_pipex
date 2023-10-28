/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:51:58 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/28 08:27:24 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    if(ft_strlen(s1) > SIZE_MAX - ft_strlen(s2))
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    p = (char *)malloc(sizeof(char) * (len + 1));
    if (p == NULL)
        return (NULL);
    ft_strlcpy(p, s1, ft_strlen(s1) + 1);
    ft_strlcat(p, s2, len + 1);
    return (p);
}
