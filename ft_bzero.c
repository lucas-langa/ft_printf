/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:28:16 by llanga            #+#    #+#             */
/*   Updated: 2018/06/07 13:58:21 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_h;

	s_h = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_h[i] = '\0';
		i++;
	}
}
