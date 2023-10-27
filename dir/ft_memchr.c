/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: hoyuki <hoyuki@student.42tokyo.jp>         +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/20 15:56:32 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/20 15:56:32 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
