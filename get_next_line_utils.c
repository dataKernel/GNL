/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:06:20 by lancelot          #+#    #+#             */
/*   Updated: 2022/06/08 17:39:27 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

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
