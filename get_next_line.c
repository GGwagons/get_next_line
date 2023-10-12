/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:13:08 by miturk            #+#    #+#             */
/*   Updated: 2023/10/12 14:52:56 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*cup_buffer;
	static int	count = 1;

	printf("malloc#[%d]----", count++);
	cup_buffer = malloc (BUFFER_SIZE + 1 * sizeof(char));
	if (!cup_buffer)
		return (NULL);
	byte_read = read (fd, cup_buffer, 5);
	if (byte_read <= 0)
		return (NULL);
	return (cup_buffer);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf ("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
