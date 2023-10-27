/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:08:50 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/27 15:13:20 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*abcdefghi;

	if (count == 0 || size == 0)
	{
		abcdefghi = malloc(1);
		if (abcdefghi == NULL)
			return (NULL);
		ft_bzero(abcdefghi, 1);
		return (abcdefghi);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	abcdefghi = malloc(count * size);
	if (abcdefghi == NULL)
		return (NULL);
	ft_bzero(abcdefghi, count * size);
	return (abcdefghi);
}

// int main()
// {
// 	char *p;
// 	char *q;
	
// 	p = ft_calloc(SIZE_MAX / 2 , 5);
// 	q = calloc(SIZE_MAX / 2 , 5);
// 	if(p == NULL)
// 		printf("p is NULL\n");
// 	else
// 		printf("p is not NULL\n");
// 	if(q == NULL)
// 		printf("q is NULL\n");
// 	else
// 		printf("q is not NULL\n");
// 	return (0);
// }