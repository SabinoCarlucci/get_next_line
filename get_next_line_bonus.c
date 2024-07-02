/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:38:56 by scarlucc          #+#    #+#             */
/*   Updated: 2024/02/25 20:00:29 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	size_t			count;
	unsigned char	*uchars;
	size_t			n;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	n = nmemb * size;
	p = (void *)malloc(n);
	if (p == NULL)
		return (NULL);
	uchars = (unsigned char *)p;
	count = 0;
	while (count < n)
	{
		uchars[count] = 0;
		count++;
	}
	return (p);
}

char	*get_output(char *output)
{
	size_t		i;
	char		*static_buffer;

	i = 0;
	while (output[i] != '\n' && output[i] != '\0')
		i++;
	if (output[i] == '\0' || output[i + 1] == '\0')
		return (0);
	static_buffer = ft_substr(output, i + 1, ft_strlen(output) - i);
	if (*static_buffer == '\0')
	{
		free(static_buffer);
		static_buffer = NULL;
	}
	output[i + 1] = '\0';
	return (static_buffer);
}

char	*read_line(int fd, char *new, char *static_buffer)
{
	char		*temp;
	int			byte_read;

	byte_read = 1;
	while (byte_read != '\0')
	{
		byte_read = read(fd, new, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		if (byte_read == 0)
			break ;
		new[byte_read] = '\0';
		if (!static_buffer)
			static_buffer = ft_strdup_mod("");
		temp = static_buffer;
		static_buffer = ft_strjoin(temp, new);
		free(temp);
		temp = NULL;
		if (ft_strchr(new, '\n'))
			break ;
	}
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*static_buffer[4096];
	char		*output;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	new = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!new)
		return (0);
	output = read_line(fd, new, static_buffer[fd]);
	free(new);
	new = NULL;
	if (!output)
		return (NULL);
	static_buffer[fd] = get_output(output);
	return (output);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	for (int i = 1; i < 7; ++i) {
		str = get_next_line(fd1);
		printf("riga numero %d: %s", i, str);
		free(str);
		str = get_next_line(fd2);
		printf("riga numero %d: %s", i, str);
		free(str);
		str = get_next_line(fd3);
		printf("riga numero %d: %s", i, str);
		free(str);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
