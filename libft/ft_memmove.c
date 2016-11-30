/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:28:11 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 07:10:27 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_movemem(unsigned char *dest, unsigned char *src, size_t len)
{
	size_t		i;

	i = 0;
	if (src > dest)
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > 0)
		{
			dest[i] = src[i];
			i--;
		}
		dest[i] = src[i];
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest_p;
	unsigned char		*src_p;

	i = 0;
	dest_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (src_p != dest_p && len > 0)
		ft_movemem(dest_p, src_p, len);
	return ((void *)dst);
}
