/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:07:13 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/13 20:24:43 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# ifdef BUFFER_SIZE
#  define BUFSIZE BUFFER_SIZE
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_strnjoin_free(char const *s1, char const *s2, size_t n);
char	*ft_strchr(char const *str, int c);
int		ft_strichr(char const *str, int c);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, size_t n);

#endif
