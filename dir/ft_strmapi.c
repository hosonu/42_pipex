/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:11:59 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/26 22:58:27 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    size_t i;
    size_t len;

    if(s == NULL || f == NULL)
        return NULL;
    len = ft_strlen(s);
    if(len == SIZE_MAX)
        return NULL;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if(str == NULL)
        return NULL;
    i = 0;
    while(i < len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return str;
}
