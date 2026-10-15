/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:17:04 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/15 17:52:15 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		lens;
	int		i;
	char	*dis;

	i = 0;
	lens = ft_strlen(s);
	dis = malloc((lens + 1) * sizeof(char));
	if (dis == NULL)
		return (NULL);
	while (lens > i)
	{
		dis[i] = s[i];
		i++;
	}
	dis[i] = '\0';
	return (dis);
}

char	*if_there_is_value(char **file )
{
	char	*line;

	if (!*file)
		*file = ft_strdup("");
	if (*file)
	{
		if (ft_strchr(*file) >= 0)
		{
			line = copy(*file, ft_strchr(*file));
			*file = newfile(*file, ft_strchr(*file));
			return (line);
		}
	}
	return (NULL);
}

char	*cheak_numword(char **file, int x)
{
	if (x == -1)
	{
		free(temp);
		free(*file);
		return (*file = NULL);
	}
	return (x);
}

char	*read_va(char **file, int fd)
{
	char	*temp;
	char	*line;
	int		x;

	x = 1;
	while (ft_strchr(*file) == -1 && x > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
		{
			free (*file);
			return (*file = NULL);
		}
		x = read(fd, temp, BUFFER_SIZE);
		if (!(cheak_numword(*file, x)))
			return (NULL);
		temp[x] = '\0';
		if (ft_strchr(temp) >= 0)
		{
			*file = ft_strjoin(*file, temp);
			line = copy(*file, ft_strchr(*file));
			*file = newfile(*file, ft_strchr(*file));
			return (line);
		}
		else
			*file = ft_strjoin(*file, temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = if_there_is_value(&file);
	if (line && file)
		return (line);
	if (file && file[0])
	{
		line = ft_strdup(file);
		free(file);
		file = NULL;
		return (line);
	}
	free(file);
	file = NULL;
	return (NULL);
}
