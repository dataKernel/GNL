/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:06:20 by lancelot          #+#    #+#             */
/*   Updated: 2022/07/07 13:22:20 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t		counter;

	counter = 0;
	if(!s)
		return(0);
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if(!dst || !src)
		return(0);
	while (src[count] != '\0')
	{
		count++;
	}
	if (dstsize >= 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			size_str_malloc;
	size_t			size_s1;
	size_t			size_s2;
	char			*str;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size_str_malloc = size_s1 + size_s2 + 1;
	str = (char *)malloc(size_str_malloc * sizeof (char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size_s1 + 1);
	ft_strlcpy(str + size_s1, s2, size_s2 + 1);
	return (str);
}

char	*ft_cut_left(char *str)
{
	int		i;
	int		size_str_malloc;
	char	*new_str;
	
	i = 0;
	while(str[i] != '\n')
		i++;
	size_str_malloc = i + 2;
	new_str = (char *)malloc(size_str_malloc * sizeof (char));
	ft_strlcpy(new_str, str, size_str_malloc);
	new_str[i] = '\0';

	return(new_str);
}

char	*ft_cut_right(char *str)
{
	int		i;
	int		size_str_malloc;
	int		indice;
	bool	check;
	char	*new_str;

	size_str_malloc = 0;
	check = false;
	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
		{
			check = true;
			i++;
			indice = i;
		}
		if(check == true)
			size_str_malloc++;
		i++;
	}
	size_str_malloc++;
	new_str = (char *)malloc(size_str_malloc * sizeof (char));
	ft_strlcpy(new_str, str + indice, size_str_malloc);
	new_str[i] = '\0';
	
	printf("%s", new_str);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	
	if(!s)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (ptr + i);
		i++;
	}
	if (s[i] == (char)c)
		return (ptr + i);
	return (NULL);
}
