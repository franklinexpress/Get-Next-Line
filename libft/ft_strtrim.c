/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 18:01:05 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 06:41:24 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str_trimmed;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	str_trimmed = NULL;
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		j--;
	if (j <= 0)
		j = 0;
	str_trimmed = (char *)malloc(sizeof(char) * (j + 1));
	if (str_trimmed == NULL)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < j)
		str_trimmed[i] = *s++;
	str_trimmed[i] = '\0';
	return (str_trimmed);
}
