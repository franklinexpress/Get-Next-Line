/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_of_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 22:49:26 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/17 22:56:44 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_of_words(const char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	if (s != NULL)
		while (*s != '\0')
		{
			if (in_substring == 1 && *s == c)
				in_substring = 0;
			if (in_substring == 0 && *s != c)
			{
				in_substring = 1;
				cnt++;
			}
			s++;
		}
	return (cnt);
}
