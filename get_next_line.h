/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:28:59 by lancelot          #+#    #+#             */
/*   Updated: 2022/07/09 15:02:30 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 5

void	search_line(char**, char**, char **);
size_t	ft_strlcpy(char*, const char*, size_t);
char	*get_next_line(int);
char	*ft_strjoin(const char*, const char*);
char	*ft_strchr(const char*, int);
char	*ft_cut_left(char *str);
char	*ft_cut_right(char *str);
int		count_size_stash(int);

#endif
