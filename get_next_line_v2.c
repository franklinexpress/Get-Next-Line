/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:22:24 by fde-los-          #+#    #+#             */
/*   Updated: 2016/11/06 01:37:57 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*
 ** CREATE THE NEXT NODE TO ADD TO THE LINKEDLIST.
 **
 */
t_node *create_node(char buffer[], int fd)
{
	int i;
	t_node *new;

	i = 0;
	while (*buffer != '\n')
		buffer++;
	++buffer;
	new = malloc(sizeof(t_node));
	new->fd = fd;
	new->next = NULL;
	new->str = malloc(sizeof(char *));
	while ( buffer[i] != '\0')
	{
		new->str[i] = (char)malloc(sizeof(char));
		new->str[i] = buffer[i];
		i++;
	}
	return (new);
}

/*
 ** SEARCH THE LIST FOR FD AND GET THE OVERFLAP STRING FROM
 ** LAST READ.
 */
char *get_overlap(t_node **root, int fd)
{
	t_node *conductor;

	if (*root == NULL)
		return (NULL);

	conductor = *root;
	while (conductor->fd != fd && conductor != 0)
		conductor = conductor->next;
	if (conductor == NULL)
		return (NULL);
		return (conductor->str);
}

/*
 ** CALL THE CREATE NODE FUNCTION AND ADD IT TO THE  LINKEDLIST.
 **
 */
void save_overlap(char buffer[], t_node **root, int fd)
{
	t_node **conductor;
	t_node *new;

	new = create_node(buffer, fd);
	if (*root == NULL)
		*root = new;
	else
	{
		conductor = root;
		while ((*conductor)->fd != fd && conductor != NULL)
			*conductor = (*conductor)->next;
		if (*conductor == NULL)
			return;
		else
			*conductor = new;
	}
}

/*
 ** PREPEND THE PREVIOUS OVERLAP IN BUFFER TO LINE STRING.
 **
 */
void prepend_overlap(char *str, char ***line, int *i)
{
	while (str[*i] != '\0')
	{
		(**line)[*i] = (char)malloc(sizeof(char));
		(**line)[*i] = str[*i];
		(*i)++;
	}

}

/*
 ** GET A SINGLE LINE AT A TIME FROM A FILE
 ** WHILE ALSO KEEPING TRACK OF THE FD.
 */
int get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE];
	int i;
	int j;
	char *overlap_str;
	static t_node *root;

	i = 0;
	j = 0;
	overlap_str = get_overlap(&root, fd);
		if(overlap_str != NULL)
		prepend_overlap(overlap_str, &line, &i);
	read(fd, buffer, BUFF_SIZE);
	while (buffer[j] != '\n')
	{
		if (j == BUFF_SIZE)
		{
			(*line)[i] = (char)malloc(sizeof(char));
			(*line)[i] = buffer[j];
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
	printf("%s\n", *line);
	save_overlap(buffer, &root, fd);
	return (0);
}

int main()
{
	int fd = open("test", O_RDONLY);
	//int fdt = open("test2", O_RDONLY);
	char *line;

	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
}
