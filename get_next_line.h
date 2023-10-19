/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:14:01 by miturk            #+#    #+#             */
/*   Updated: 2023/10/19 15:46:07 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <stddef.h>


char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);
char	*ft_read_from_file_to_buffer(int fd, char **line_buffer);
char	*ft_clean_buffer(char **line_buffer);
char	*ft_read_from_buffer_newline(char **line_buffer);
char	*ft_strdup(char *s);

#endif