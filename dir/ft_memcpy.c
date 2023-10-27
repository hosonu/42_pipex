/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: hoyuki <hoyuki@student.42tokyo.jp>         +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/20 15:56:41 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/20 15:56:41 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;

	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}
