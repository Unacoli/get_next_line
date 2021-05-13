/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:06:35 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/13 14:01:56 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	static char	*garbage = NULL;
	
	*line = malloc(1);
	if (garbage == NULL)
		garbage = malloc(1);
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup(garbage);
	while (((ret = read(fd, &buffer, BUFFER_SIZE)) > 0) && (ft_strchr(buffer, '\n') == NULL))
	{
		buffer[ret] = '\0';
		*line = ft_strjoin_free(*line, buffer);
	}
	printf("ret: %d\n", ret);
	buffer[ret] = '\0';
	printf("%s -> %d\n", buffer, ft_strichr(buffer, '\n')); 
	*line = ft_strnjoin_free(*line, buffer, ft_strichr(buffer, '\n'));
	if (ret != BUFFER_SIZE)
		return (0);
	printf("garbaj: %s\n", garbage);
	printf("strcherche: %s\n", ft_strchr(buffer, '\n') + 1);
	garbage = ft_strjoin_free(garbage, ft_strchr(buffer, '\n') + 1);
	return (1);
}
