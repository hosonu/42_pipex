/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:11:07 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/08 10:43:32 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd, char *line)
{
	static char	*str[OPEN_MAX - _SC_OPEN_MAX];
	// char		*line;
	char		*buf;
	char		*tmp;
	ssize_t		i;

	if (fd < 0 || fd > (OPEN_MAX - _SC_OPEN_MAX) || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr_gnl(str[fd], '\n') && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (!err_free(i, str[fd], buf))
			return (NULL);
		tmp = ft_strjoin_gnl(str[fd], buf, i);
		free(str[fd]);
		str[fd] = tmp;
	}
	free(buf);
	line = get_line(str[fd]);
	str[fd] = left_str(str[fd]);
	return (line);
}
