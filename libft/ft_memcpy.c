/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:02:39 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 06:07:13 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *p;
	char *p_src;

	p_src = (char *)src;
	p = dst;
	while (n-- != 0)
	{
		p[n] = p_src[n];
	}
	return (dst);
}
