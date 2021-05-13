/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:06:35 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/13 16:48:58 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*garbage = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	
	if (garbage == NULL)
	{
		garbage = malloc(1);
		*garbage = '\0';
	}
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	//*line = ft_strdup(garbage);
	printf("garbage: [%s] ichr: [%d]\n", garbage, ft_strichr(garbage, '\n'));
	*line = ft_strndup(garbage, ft_strichr(garbage, '\n'));
	if (ft_strchr(garbage, '\n') != NULL)
	{
		garbage = ft_strdup(ft_strchr(garbage, '\n') + 1);
		return (1);
	}
	while (((ret = read(fd, &buffer, BUFFER_SIZE)) > 0) && (ft_strchr(buffer, '\n') == NULL))
	{
		buffer[ret] = '\0';
		*line = ft_strjoin_free(*line, buffer);
	}
	buffer[ret] = '\0';
	*line = ft_strnjoin_free(*line, buffer, ft_strichr(buffer, '\n'));
	if (ret != BUFFER_SIZE && ft_strchr(buffer, '\n') == NULL)
	{
		free(garbage);
		garbage = NULL;
		return (0);
	}
	garbage = ft_strdup(ft_strchr(buffer, '\n') + 1);
	return (1);
}
