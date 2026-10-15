/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:17:20 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/15 16:40:25 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*copy(char *copy, int index)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc (index + 2);
	while (copy[i] != '\n' && copy[i])
	{
		str[i] = copy[i];
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens2;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*newfile(char *file, int index)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	index++;
	len = ft_strlen(file);
	str = malloc(len - index + 1);
	if (!str)
		return (NULL);
	while (file[index])
	{
		str[i] = file[index];
		i++;
		index++;
	}
	free(file);
	str[i] = '\0';
	return (str);
}
