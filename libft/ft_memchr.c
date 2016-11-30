/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:00:49 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 06:16:34 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_conv;
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	c_conv = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == c_conv)
			return (&p[i]);
		i++;
	}
	return (0);
}
