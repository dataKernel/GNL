/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:27:22 by lancelot          #+#    #+#             */
/*   Updated: 2022/06/04 18:05:35 by lancelot         ###   ########.fr       */
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
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

//BUFFER def
#define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	char	*stash;
	char	buffer[BUFFER_SIZE];
	int		res_open;

	stash = malloc(sizeof(char) * count_size_stash(fd));
	read(fd, buffer, BUFFER_SIZE);
	//checking datas
	printf("checking...[FD_open] -> %i\n", res_open);
	printf("checking...[VAL_buffer] -> %s\n", buffer);
	
	return("lol");//returning shit __DATAS__(temp)
}

int		main(void)
{
	//TODO: some test??
	int		res_open;

	res_open = open("./test", O_RDONLY);
	get_next_line(res_open);//on donne le fd a GNL
	return(0);
}

