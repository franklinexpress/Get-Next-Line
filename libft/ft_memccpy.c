/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:42:31 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/21 15:28:43 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*pdst;
	unsigned char	*psrc;
	unsigned char	x;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*pdst++ = *psrc++) == x)
			return (pdst);
		i++;
	}
	return (NULL);
}
