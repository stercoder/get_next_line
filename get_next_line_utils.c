/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:26:52 by ykhindou          #+#    #+#             */
/*   Updated: 2024/12/10 00:31:22 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	dostrlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*dostrdup(char *origin)
{
	char	*dup;
	int		len;
	int		i;

	if (!origin)
		return (NULL);
	len = dostrlen(origin);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = origin[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*strjoin(char *old, char *first)
{
	char	*last;
	size_t	first_len;
	size_t	old_len;
	size_t	i;

	if (!first || !old)
		return (NULL);
	first_len = dostrlen(first);
	old_len = dostrlen(old);
	last = (char *)malloc((first_len + old_len) * sizeof(char) + 1);
	if (!last)
		return (NULL);
	i = 0;
	while (i < old_len)
	{
		last[i] = old[i];
		i++;
	}
	while (i < first_len + old_len)
	{
		last[i] = first[i - old_len];
		i++;
	}
	last[i] = '\0';
	return (last);
}

char	*strcut(char *str, int len)
{
	char	*linee;
	int		i;

	linee = malloc(len + 1);
	if (!linee)
		return (NULL);
	i = 0;
	while (i < len)
	{
		linee[i] = str[i];
		i++;
	}
	linee[i] = '\0';
	return (linee);
}
