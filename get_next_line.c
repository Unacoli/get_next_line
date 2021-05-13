/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:06:35 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/13 17:58:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*garbage = "";
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	printf("garbage: [%s] ichr: [%d]\n", garbage, ft_strichr(garbage, '\n'));
	*line = ft_strndup(garbage, ft_strichr(garbage, '\n'));
	if (ft_strchr(garbage, '\n') != NULL)
	{
		tmp = garbage;
		garbage = ft_strdup(ft_strchr(garbage, '\n') + 1);
		free(tmp);
		return (1);
	}
	while (((ret = read(fd, &buffer, BUFFER_SIZE)) > 0) 
			&& (ft_strchr(buffer, '\n') == NULL))
	{
		buffer[ret] = '\0';
		*line = ft_strjoin_free(*line, buffer);
	}
	buffer[ret] = '\0';
	*line = ft_strnjoin_free(*line, buffer, ft_strichr(buffer, '\n'));
	if (ret != BUFFER_SIZE && ft_strchr(buffer, '\n') == NULL)
		return (ft_free((void **) &garbage));
	garbage = ft_strdup(ft_strchr(buffer, '\n') + 1);
	return (1);
}
