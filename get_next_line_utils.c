/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:29:15 by nargouse          #+#    #+#             */
/*   Updated: 2021/05/12 18:02:01 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		total_length;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(result = (char *)malloc(sizeof(char *) * (total_length + 1))))
		return (NULL);
	while (i < total_length)
	{
		while (s1[j])
		{
			result[i] = s1[j];
			i++;
			j++;
		}
		j = 0;
		while (s2[j])
		{
			result[i] = s2[j];
			i++;
			j++;
		}
	}	
	result[i] = '\0';
	return (result);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*result;
	int		total_length;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(result = (char *)malloc(sizeof(char *) * (total_length + 1))))
		return (NULL);
	while (i < total_length)
	{
		while (s1[j])
		{
			result[i] = s1[j];
			i++;
			j++;
		}
		j = 0;
		while (s2[j] && j < n)
		{
			result[i] = s2[j];
			i++;
			j++;
		}
	}	
	result[i] = '\0';
	return (result);
}
