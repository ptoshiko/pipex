/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:25:44 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/03/13 14:42:50 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_connect(char *s1, char *s2, char	*new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	if (s1 == 0 || s2 == 0)
		return (0);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == 0)
		return (0);
	return (ft_connect(s1, s2, new));
}
