/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:43:10 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/27 20:37:30 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct leftovers
{
	int fd;
	char *str;
}leftovers;

int	get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE];
	int i;
	int j;
	static char *leftover_buffer;


	if (fd == -1)
		return (0);

	i = 0;
	j = 0;
	*line = 0;
	*line = malloc(sizeof(char *));
	read(fd, buffer, BUFF_SIZE);
	while (buffer[j] != '\n')
	{
		if (j == BUFF_SIZE)
		{
			j = 0;
			read(fd, buffer, BUFF_SIZE);
			continue;
		}
		(*line)[i] = (char)malloc(sizeof(char));
		(*line)[i] = buffer[j];
		i++;
		j++;
	}
	(*line)[i] = '\0';
	printf("%s", *line);
	if(buffer[j] == '\n')
		printf("\n");

	printf("\n\nleft over:");
	i = 0;
	if (buffer[j] != '\0')
	{
		leftover_buffer = (char *)malloc(sizeof(char *));
		while (buffer[j] != '\0')
		{
			leftover_buffer[i] = (char)malloc(sizeof(char));
			leftover_buffer[i] = buffer[j];
			j++;
			i++;
		}
		printf("%s", leftover_buffer);
	}
	printf("\n\n\n");
	return (1);
}

int main()
{
	int fd = open("test", O_RDONLY);

	char *line;
//	int i = 0;


	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
}
