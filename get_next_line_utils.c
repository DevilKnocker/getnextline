/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:55:28 by jblache           #+#    #+#             */
/*   Updated: 2021/01/29 10:09:59 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char    *ft_strjoin(const char *s1, const char *s2)
{
        unsigned int    i;
        unsigned int    j;
        char                    *str;

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
