/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:43:21 by fde-los-          #+#    #+#             */
/*   Updated: 2016/11/05 22:38:45 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
#include <fcntl.h>
#include "libft/libft.h"

int	get_next_line(const int fd, char **line);

typedef struct s_node
{
	int fd;
	char *str;
	struct s_node *next;
}t_node;

#endif

