/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:26:29 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/15 01:02:39 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *text, const char *pattern)
{
	int i;
	int j;
	int m;
	int n;

	i = 0;
	if (!*pattern)
		return ((char *)text);
	m = ft_strlen((char *)pattern);
	n = ft_strlen((char *)text);
	while (i <= (n - m))
	{
		j = 0;
		while ((j < m) && (text[i + j] == pattern[j]))
			j++;
		if (j == m)
			return ((char *)&text[i]);
		i++;
	}
	return (0);
}
