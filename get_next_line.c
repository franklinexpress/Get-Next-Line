/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:22:24 by fde-los-          #+#    #+#             */
/*   Updated: 2016/11/30 02:37:57 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

t_node	*create_node(const int fd)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->next = NULL;
	return (new);
}

void	add_node(t_node *node, t_node *new_node)
{
	while (node)
	{
		if (node->next == NULL)
		{
			node->next = new_node;
			new_node->next = NULL;
		}
		node = node->next;
	}
}

char	*get_line(t_node *node, char **line)
{
	char	*temp;
	char	*str;
	int		i;

	temp = NULL;
	i = 0;
	str = node->str;
	while (str[i])
	{
		if (str[i] == NL)
		{
			*line = ft_strsub(str, 0, i);
			temp = str;
			str = ft_strdup(str + (i + 1));
			free(temp);
			return (str);
		}
		i++;
	}
	*line = ft_strdup(str);
	ft_strclr(str);
	ft_strclr(node->str);
	return (str);
}

int		read_file(int fd, t_node *node)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*temp;

	temp = NULL;
	ret = -3;
	while (!ft_strchr(node->str, NL))
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buffer[ret] = 0;
			temp = node->str;
			if (!(node->str = ft_strjoin(node->str, buffer)))
				return (-1);
			free(temp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_node	*head;
	t_node			*temp;
	int				ret;

	if (!head)
		head = create_node(fd);
	temp = head;
	if (fd < 0 || !line)
		return (-1);
	while (temp)
	{
		if (temp->fd == fd)
			break ;
		if (temp->next == NULL)
			add_node(temp, create_node(fd));
		temp = temp->next;
	}
	if ((ret = read_file(fd, temp)) == -1)
		return (-1);
	temp->str = get_line(temp, line);
	if (!ft_strlen(temp->str) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
