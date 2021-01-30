/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:46:41 by jblache           #+#    #+#             */
/*   Updated: 2021/01/30 09:28:17 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strjoiner(char **begin, char **next, int f)
{
	char	*str;

	str = ft_strjoin(*begin, *next);
	free(*begin);
	if (f == 1)
		free (*next);
	*begin = str;
	return ;
}

void	ft_gratteligne(char **line, char **buffer, char **save)
{
	char	*temp;

	temp = ft_substr(*buffer, 0, ft_strchr(*buffer, '\n') - 1);
	ft_strjoiner(line, &temp, 1);
	if (ft_strlen(*buffer) > ft_strchr(*buffer, '\n'))
		*save = ft_substr(*buffer, ft_strchr(*buffer, '\n'), BUFFER_SIZE);
	return ;
}

int		ft_savecheck(char **line, char **save)
{
	char	*temp;

	if (*save)
	{
		if (ft_strchr(*save, '\n'))
		{
			temp = ft_substr(*save, 0, ft_strchr(*save, '\n') - 1);
			ft_strjoiner(line, &temp, 1);
			if (ft_strlen(*save) > ft_strchr(*save, '\n'))
			{
				temp = ft_substr(*save, ft_strchr(*save, '\n'), BUFFER_SIZE);
				free (*save);
				*save = temp;
			}
			else free (*save);
			return (1);
		}
		else ft_strjoiner(line, save, 1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*save;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || !(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	if (ft_savecheck(line, &save) == 1)
		return (1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) && i > 0)
	{
		buffer[i] = '\0';
		if (ft_strchr(buffer, '\n'))
			break;
		ft_strjoiner(line, &buffer, 0);
	}
	if (i < 0)
	{
		free (buffer);
		return (-1);
	}
	if (ft_strchr(buffer, '\n'))
		ft_gratteligne(line, &buffer, &save);
	free (buffer);
	if (i == 0 || (i < BUFFER_SIZE && !(save)))
		return (0);
	return (1);
}
