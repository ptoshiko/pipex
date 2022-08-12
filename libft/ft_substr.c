/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:20:13 by ptoshiko          #+#    #+#             */
/*   Updated: 2021/11/13 14:23:17 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*one_char(char	*sub)
{
	sub = (char *)malloc(sizeof(char));
	if (sub == 0)
		return (0);
	else
	{	
		sub[0] = '\0';
		return (sub);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned int	endind;

	sub = NULL;
	if (s == 0)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (one_char(sub));
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	endind = start + (unsigned int)len;
	sub = (char *)malloc(len + 1);
	if (sub == 0)
		return (0);
	while (start < endind)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
