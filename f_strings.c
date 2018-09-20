/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:21:35 by llanga            #+#    #+#             */
/*   Updated: 2018/08/23 14:43:20 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		f_putstr(char *str)
{
	int ret;

	ret = 0;
	while (*str)
	{
		ret += f_putchar(*str);
		str++;
	}
	return (ret);
}
