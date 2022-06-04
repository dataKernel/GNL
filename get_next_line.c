/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:27:22 by lancelot          #+#    #+#             */
/*   Updated: 2022/06/04 10:38:26 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO-> créer l'instance pour le buffer
//TODO-> créer var line pour stocker depuis buffer la ligne

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

//BUFFER def
#define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		res_open;
	int		res_read;
	
	res_open = open("./test", O_RDONLY);
	printf("checking...[FD_open] -> %i\n", res_open);
	res_read = read(res_open, buffer, 5);//test_case|5:5|buffer:nbyte|
	printf("checking...[B_read] -> %i\n", res_read);	
	//returning shit data, just ***TESTIN***
	return("lol");	
}

int		main(void)
{
	//TODO: some test??
	get_next_line(1);
	return(0);
}
