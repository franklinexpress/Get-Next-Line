/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:43:10 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/27 18:09:41 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE];
	int i;

	if (fd == -1)
		return (0);
	i = 0;
	int j = 0;
	*line = 0;
	*line = malloc(sizeof(char *) );
	read(fd, buffer, BUFF_SIZE);
	while (buffer[j] != '\0')
	{

		if (j == BUFF_SIZE - 1)
		{
			j = 0;
			read(fd, buffer, BUFF_SIZE);
			printf("reading again");
			continue;
		}

		if (buffer[j] == '\n')
		{
			printf("\nbackslash n\n");
			break;
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
	return (1);
}

int main()
{
	int fd = open("test", O_RDONLY);

	char *line;
//	int i = 0;


	get_next_line(fd, &line);
}
