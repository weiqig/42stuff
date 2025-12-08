/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:43:05 by wgan              #+#    #+#             */
/*   Updated: 2025/11/04 20:44:32 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t		idx;
	char		*str;

	idx = 0;
	str = (char *)s;
	while (*s && idx < ft_strlen(s) + 1)
	{
		if (str[idx] == (char)c)
			return (&str[idx]);
		idx++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

static char	*ft_fill_buffer(int fd, char *stash, char *buffer)
{
	int		isread;
	char	*temp;

	isread = 1;
	while (isread > 0)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (isread == 0)
			break ;
		buffer[isread] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*ft_get_line(char *line_buf)
{
	int		idx;
	char	*str;

	idx = 0;
	str = NULL;
	while (line_buf[idx] != '\n' && line_buf[idx] != '\0')
		idx++;
	if (!line_buf[idx])
		return (NULL);
	str = ft_substr(line_buf, idx + 1, ft_strlen(line_buf) - (idx + 1));
	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		str = NULL;
	}
	line_buf[idx + 1] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*read_buf;

	read_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		free(read_buf);
		stash = NULL;
		read_buf = NULL;
		return (NULL);
	}
	if (!read_buf)
		return (NULL);
	line = ft_fill_buffer(fd, stash, read_buf);
	free(read_buf);
	read_buf = NULL;
	if (!line)
		return (NULL);
	stash = ft_get_line(line);
	return (line);
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	int		fd;
	int		count;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		fd = open("test.txt", O_RDONLY);
		count = atoi(argv[1]);
		while (count-- > 0)
		{
			line = get_next_line(fd);
			if (!line)
			{
				free(line);
				break ;
			}
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
}*/
