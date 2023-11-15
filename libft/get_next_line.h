/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:45:38 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/15 16:49:24 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// get_next_line.c
char			*get_next_line(int fd);
// static int		err_free(ssize_t i, char *str, char *buf);

// get_next_line_utils.c
// static size_t	gnl_strlen(const char *str);
char			*gnl_strchr(char *s, int c);
char			*gnl_strjoin(char *s1, char *s2, size_t j);
char			*get_line(char *str);
char			*left_str(char *str);

#endif
