/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:46:50 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/29 17:09:05 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	err_free(ssize_t i, char *str, char *buf)
{
	if (i < 0)
	{
		free(str);
		free(buf);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	char		*buf;
	char		*tmp;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (!gnl_strchr(str, '\n') && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (!err_free(i, str, buf))
			return (NULL);
		tmp = gnl_strjoin(str, buf, i);
		free(str);
		str = tmp;
	}
	free(buf);
	line = get_line(str);
	str = left_str(str);
	return (line);
}
