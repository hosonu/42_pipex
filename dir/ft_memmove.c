/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hoyuki <hoyuki@student.42tokyo.jp>         +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/09/20 16:00:11 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/20 16:00:11 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *tmp;

	d = (unsigned char *)dest;
	tmp = (unsigned char *)src;
	if (!d && !tmp)
		return (NULL);
	if (dest <= src)
	{
		while (n--)
			*d++ = *tmp++;
	}
	else
	{
		d += n;
		tmp += n;

		while (n--)
			*--d = *--tmp;
	}
	return (dest);
}
