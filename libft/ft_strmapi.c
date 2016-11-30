/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:16:40 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 06:41:48 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	if (!s || !f)
		return (NULL);
	p = ft_strnew(ft_strlen(s));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}
