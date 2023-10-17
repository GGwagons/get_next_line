/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:13:08 by miturk            #+#    #+#             */
/*   Updated: 2023/10/17 17:37:28 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_from_buffer_newline(char line_buffer)
{
	int		total_len;
	char	*ab_new;
	char	*new_string;
	char	*temp_buffer;

	new_string = read_from_file_to_buffer(new_string);
	temp_buffer = read_from_file_to_buffer(temp_buffer);

	total_len = ft_strlen (temp_buffer) + ft_strlen (new_string);
	ab_new = malloc (total_len * sizeof(char));
	if (!ab_new)
		return (NULL);
	ab_new = ft_strcpy(ab_new, temp_buffer);
	ab_new = ft_strcpy (ab_new, new_string);
	return (ab_new);
}

char	*ft_clean_buffer(char line_buffer)
{
	int		i;
	int		start;
	char	rest;

	rest = malloc (sizeof(char) * (ft_strlen(ft_strchr(line_buffer, '\n'))));
	i = 0;
	start = ft_strlen(ft_strchar(line_buffer, '\n'));
	while (line_buffer != '\0')
	{
		rest = line_buffer[start + i];
		i++;
	}
	rest[i] = '\0';
	free(line_buffer);
	return (rest);
}

static char	*read_from_file_to_buffer(int fd)
{
	char	*temp_buffer;
	char	*new_string;
	int		byte;

	byte = 0;
	while (ft_strchr(temp_buffer, '\n') == NULL)
	{
		new_string = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!new_string)
			return (NULL);
		byte = read (fd, new_string, BUFFER_SIZE);
		if (byte == -1)
			return (NULL);
		temp_buffer = ft_strjoin (temp_buffer, new_string);
	}
	free (new_string);
	temp_buffer[byte] = '\0';
	return (temp_buffer);
}

char	*get_next_line(int fd)
{
	static char	*line_buffer;
	char		*newline;
	int			byte;

	line_buffer = ft_clean_buffer(line_buffer);
	line_buffer = (char *)mallo((char *ft_clean_buffer(rest)) * sizeof(char));
	if (!line_buffer)
		return (NULL);

	line_buffer = read_from_file_to_buffer (fd);
	newline = ft_read_from_buffer_newline(line_buffer);
	line_buffer = ft_clean_buffer(line_buffer);
	return (newline);
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
