/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 09:25:30 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 06:40:19 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*current;

	current = s1;
	while (*current != '\0')
	{
		current++;
	}
	while (*s2 != '\0' && n > 0)
	{
		*current = *s2;
		current++;
		s2++;
		n--;
	}
	*current = '\0';
	return (s1);
}
