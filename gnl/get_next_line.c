/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:49:17 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/21 11:49:49 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_free(char **file)
{
	if (*file)
	{
		free(*file);
		*file = NULL;
	}
	return (NULL);
}

static char	*get_line(char **file, int fd)
{
	char	*aux;
	char	*line;
	int		i;

	if (!file[fd])
		return (NULL);
	aux = file[fd];
	i = ft_search(aux, '\n');
	if (i == -1)
	{
		if (ft_strlen(aux) <= 0)
			return (ft_free(file + fd));
		line = ft_strdup(aux);
		ft_free(&aux);
		file[fd] = NULL;
		return (line);
	}
	line = ft_substr(aux, 0, i + 1);
	file[fd] = ft_substr(aux, i + 1, (ft_strlen(aux) - i));
	ft_free(&aux);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*file[FD_SIZE];
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file[fd])
		file[fd] = ft_strdup("");
	ret = 1;
	while (ret > 0)
	{
		if (ft_search(file[fd], '\n') == -1)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret == -1)
				return (ft_free(file + fd));
			buf[ret] = '\0';
			file[fd] = ft_strjoin(file[fd], buf);
		}
		else
			return (get_line(file, fd));
	}
	return (get_line(file, fd));
}
