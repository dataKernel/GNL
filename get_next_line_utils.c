/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:06:20 by lancelot          #+#    #+#             */
/*   Updated: 2022/06/27 20:39:49 by lancelot         ###   ########.fr       */
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

	if (!s1 || !s2)
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

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

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

int	count_size_stash(fd)
{
	char	buffer[BUFFER_SIZE];
	bool	check;
	int		count;
	int		i;

	check = false;
	count = 0;
	do
	{
	read(fd, buffer, BUFFER_SIZE);
	//check
	i = 0;
	while(buffer[i])
		{
			i++;			
			if(buffer[i] != '\n')
				count++;
			else
			{
				check = true;
				break;
			}
		}
	}while(!check);
	return(count);
}
