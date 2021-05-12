/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:06:35 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/12 21:22:56 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	static char	*garbage = "";
	
	*line = "";
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	printf("bite1\n");
	while (((ret = read(fd, &buffer, BUFFER_SIZE)) >= 0) && (ft_strchr(buffer, '\n') == NULL))
	{
		printf("bite2\n");
		buffer[ret] = '\0';
		printf("bite3\n");
		*line = ft_strjoin(*line, buffer);
		printf("bite4\n");
	}
	printf("ret: %d\n", ret);
	buffer[ret] = '\0';
	printf("bite5\n");
	printf("%s -> %d\n", buffer, (int)(ft_strchr(buffer, '\n') - buffer + 1)); 
	*line = ft_strnjoin(*line, buffer, (int)(ft_strchr(buffer, '\n') - buffer + 1));
	printf("bite6\n");
	garbage = ft_strjoin(garbage, ft_strchr(buffer, '\n'));
	printf("bite7\n");
	if (ret != BUFFER_SIZE)
		return (0);
	else
		return (1);
}
