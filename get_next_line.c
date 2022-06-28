/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:27:22 by lancelot          #+#    #+#             */
/*   Updated: 2022/06/27 20:40:01 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO-> créer l'ouverture du fichier (√)
//TODO-> créer la lecture du fichier sur le FD correspondant (√)
//TODO-> créer l'instance pour le buffer (√)
//TODO-> remplir le buffer via read (√)
//TODO-> remplir tout le contenu du fichier dans la stash (X)(test)

#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*line = NULL;
	char			*temp_line;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes_read;
	
	bytes_read = BUFFER_SIZE;
	if(fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return(NULL);
	while(bytes_read > 0)
	{
		bytes_read = read(fd, buffer, bytes_read);
		if(bytes_read == -1)
			return(NULL);
		buffer[bytes_read] = '\0';
		temp_line = line;
		line = ft_strjoin(temp_line, buffer);
		printf("line --> %s \n", line);
		free(temp_line);
		//if(ft_strchr(line, '\n'))
			//break;
	}
	return(line);//returning the line we got
}

int		main(void)
{
	int		res_open;
	char	*result;

	res_open = open("./test", O_RDONLY);
	result = get_next_line(res_open);//on donne le fd a GNL
	return(0);
}
