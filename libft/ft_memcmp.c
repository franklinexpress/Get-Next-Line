/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:10:12 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/21 15:21:46 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char s1_b;
	unsigned char s2_b;

	while (n--)
	{
		s1_b = *(unsigned char *)s1++;
		s2_b = *(unsigned char *)s2++;
		if (s1_b != s2_b)
			return (s1_b - s2_b);
	}
	return (0);
}
