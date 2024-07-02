/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:39:10 by scarlucc          #+#    #+#             */
/*   Updated: 2024/01/31 18:51:15 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup_mod(const char *s)
{
	size_t	len;
	char	*d;
	size_t	count;
	size_t	size;

	len = ft_strlen((char *)s);
	size = len + 1;
	d = (char *)malloc(size * sizeof(*s));
	if (!d)
		return (NULL);
	count = 0;
	while (s[count] != '\0' && (count + 1) < size)
	{
		d[count] = s[count];
		count++;
	}
	if (size > 0)
		d[count] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		out[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		out[i] = s2[i - lens1];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)(s + count));
		count++;
	}
	if (s[count] == (char)c)
		return ((char *)(s + count));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;

	if (ft_strlen(s) < start)
		return (ft_strdup_mod(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s[start] && i < len && (size_t)start < ft_strlen(s))
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}
