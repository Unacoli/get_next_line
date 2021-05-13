/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:29:15 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/13 22:29:40 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ptr == 0)
		return (NULL);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ptr == 0)
		return (NULL);
	while (src[i] && i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

int		ft_strichr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return (i);
	}
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
