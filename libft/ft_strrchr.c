/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:51:27 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/26 22:18:27 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*tmp;

	str = (char *)s;
	tmp = NULL;
	while (*str)
	{
		if (*str == (char)c)
			tmp = str;
		str++;
	}
	if (*str == (char)c)
		tmp = str;
	return (tmp);
}
