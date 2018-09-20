/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:59:59 by llanga            #+#    #+#             */
/*   Updated: 2018/06/22 13:44:23 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ADD_NULL 1

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = 0;
	if (!(dup = (char*)malloc(ADD_NULL + ft_strlen(s1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
