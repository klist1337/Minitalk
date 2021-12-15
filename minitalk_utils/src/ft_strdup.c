/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:54:08 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/15 19:47:13 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(sizeof(char) * len);
	if (dup == 0)
	{
		return (NULL);
	}
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
