/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:56:26 by jblache           #+#    #+#             */
/*   Updated: 2021/01/29 10:11:18 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned int	ft_strlen(char *str);
unsigned int	ft_strchr(const char *s, int searchchar);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_savecheck(char **line, char **save);
int				get_next_line(int fd, char **line);
int				ft_savecheck(char **line, char **save);
void			ft_gratteligne(char **line, char **buffer, char **save);
void			ft_joiner(char **begin, char **next, int f);

#endif
