/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:21:25 by jblache           #+#    #+#             */
/*   Updated: 2021/01/21 15:55:23 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:59:29 by jblache           #+#    #+#             */
/*   Updated: 2021/01/21 14:59:29 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strchr(const char *s, int searchchar)
{
	unsigned int	i;
	char			*str;
	char			c;

	c = (char)searchchar;
	str = (char *)s;
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (c == str[i] || (str[i] == '\0' && c == '\0'))
		return (i + 1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(str = malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	else if (ft_strlen((char *)s) <= start)
		len = 0;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	unsigned int	i;

	*line = "";
	if (save)
	{
		if (ft_strchr(save, '\n'))
		{
			*line = ft_strjoin(*line, ft_substr(save, 0, ft_strchr(save, '\n') - 1));
			if (ft_strlen(save) > ft_strchr(save, '\n'))
				save = ft_substr(save, ft_strchr(save, '\n'), BUFFER_SIZE);
			else save = NULL;
			return (1);
		}
		*line = ft_strjoin(*line, save);
		save = NULL;
	}
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	while ((i = read(fd, buff, BUFFER_SIZE)))
	{
		buff[i] = '\0';
		if (ft_strchr(buff, '\n') || buff[i - 1] == '\0')
			break;
		*line = ft_strjoin(*line, buff);
	}
	if (i == 0)
		return (0);
	if (ft_strchr(buff, '\n'))
	{
		*line = ft_strjoin(*line, ft_substr(buff, 0, ft_strchr(buff, '\n') - 1));
		save = ft_substr(buff, ft_strchr(buff, '\n'), BUFFER_SIZE);
		return (1);
	}
	*line = ft_strjoin(*line, buff);
	free (buff);
	return (0);
}

int main()
{
	int fd;
	char *line;

	fd = open ("lol", O_RDONLY);
	while(ft_get_next_line(fd, &line))
	{
		printf("%s\n", "APPEL");
		printf("%s\n", line);
		free (line);
	}
	return (0);
}
