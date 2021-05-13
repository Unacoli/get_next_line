/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:07:13 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/13 22:45:57 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# define BUFSIZE BUFFER_SIZE

size_t	ft_strlen(const char *str);
int		ft_free(void **ptr);
int		ft_if(char **left, char **tmp);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_strnjoin_free(char const *s1, char const *s2, size_t n);
char	*ft_strchr(char const *str, int c);
int		ft_strichr(char const *str, int c);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, size_t n);

#endif
