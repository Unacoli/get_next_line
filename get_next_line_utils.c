/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:29:15 by nargouse          #+#    #+#             */
/*   Updated: 2021/02/26 16:15:20 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	if (dst > src)
	{
		while (n > 0)
		{
			((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_length;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);	
	total_length = size_s1 + size_s2;
	if (!(result = (char *)malloc(sizeof(char *) * (total_length + 1))))
		return (NULL);
	ft_memmove(result, s1, size_s1);
	ft_memmove(result + size_s1, s2, size_s2);
	result[total_length - 1] = '\0';
	free((char *)s1);
	return (result);
}
