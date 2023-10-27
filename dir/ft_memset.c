/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:01:22 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/20 16:01:22 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *str;

    str = (unsigned char *)s; 
    while(n--)
        *str++ =(unsigned char )c;
    return s;
}
