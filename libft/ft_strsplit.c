/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 18:21:33 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/19 07:41:39 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		index;

	index = 0;
	nb_word = ft_number_of_words((const char *)s, c);
	if (!((t = (char **)malloc(sizeof(*t) *
						(ft_number_of_words((const char *)s, c) + 1)))))
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(t[index] =
					ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c))))
			return (NULL);
		s = s + ft_wlen(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
