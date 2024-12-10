/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:32:01 by ykhindou          #+#    #+#             */
/*   Updated: 2024/12/10 00:31:16 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

static char	*get_line(char **cont)
{
	int			newline_index;
	char		*tmp;
	char		*line;

	if (!cont || !*cont || !**cont)
		return (NULL);
	newline_index = check_next_line(*cont);
	if (newline_index > 0)
	{
		line = strcut(*cont, newline_index);
		tmp = dostrdup(*cont + newline_index);
		free(*cont);
		*cont = tmp;
		return (line);
	}
	else if (**cont)
	{
		line = dostrdup(*cont);
		free(*cont);
		*cont = NULL;
		return (line);
	}
	return (NULL);
}

int	read_next(int fd, char *buffer, char **str)
{
	int		r;
	char	*tmp;

	r = -1;
	r = read(fd, buffer, BUFFER_SIZE);
	if (r > 0)
	{
		buffer[r] = '\0';
		tmp = strjoin(*str, buffer);
		free(*str);
		*str = tmp;
	}
	return (r);
}

static char	*cleanup(char **cont, char *buffer, char *line, ssize_t r)
{
	free(buffer);
	if (!line && r == 0)
	{
		free(*cont);
		*cont = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cont;
	char		*buffer;
	char		*line;
	ssize_t		r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!cont)
		cont = dostrdup("");
	r = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	line = get_line(&cont);
	while (!line && r > 0)
	{
		r = read_next(fd, buffer, &cont);
		if (r < 0)
			break ;
		line = get_line(&cont);
	}
	return (cleanup(&cont, buffer, line, r));
}
