/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:27:22 by lancelot          #+#    #+#             */
/*   Updated: 2022/07/11 18:12:30 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"

char	*ft_cut_left(char *str)
{
	int		i;
	int		size_str_malloc;
	char	*new_str;
	
	i = 0;
	while(str[i] != '\n' && str[i])
		i++;
	if(i == 0)
		return(NULL);
	size_str_malloc = i + 2;
	new_str = (char *)malloc(size_str_malloc * sizeof (char));
	ft_strlcpy(new_str, str, size_str_malloc);
	
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
	if(!check)
		return(NULL);
	size_str_malloc++;
	new_str = (char *)malloc(size_str_malloc * sizeof (char));
	ft_strlcpy(new_str, str + indice, size_str_malloc);
	
	return (new_str);
}

void	search_line(char **line, char **res, char **temp_line)
{
	if(*line == NULL)
	{
		*res = NULL;
		return ;
	}
	*res = ft_cut_left(*line);
	*temp_line = *line;
	*line = ft_cut_right(*line);
	free(*temp_line);
}

char	*get_next_line(int fd)
{
	static char		*line = NULL;
	char			*temp_line;
	char			*res;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes_read;
	
	bytes_read = BUFFER_SIZE;
	if(fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return(NULL);
	while(bytes_read > 0 && !ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == -1)
			return(NULL);
		buffer[bytes_read] = '\0';
		temp_line = line;
		if(bytes_read != 0)
			line = ft_strjoin(temp_line, buffer);
		free(temp_line);
	}
	search_line(&line, &res, &temp_line);
	return(res);
}

int		main(void)
{
	int		fd;
	char	*str;

	fd = open("./gnlTester/files/nl", O_RDWR);
	str = get_next_line(fd);
	printf("%p\n", str);
	str = get_next_line(fd);
	printf("%p\n", str);
	//................
	return(0);
}

