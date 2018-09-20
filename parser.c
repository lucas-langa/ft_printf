/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:51:15 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 11:39:52 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mk_push_str(char *src)
{
	char *res;

	res = NULL;
	res = ft_strnew(ft_strlen(src));
	ft_bzero(res, ft_strlen(src));
	ft_strcpy(res, src);
	return (res);
}

int		gimme_nbr_base(char specifier)
{
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (16);
	else if (specifier == 'u' || specifier == 'i' || specifier == 'd' \
	|| specifier == 'D' || specifier == 'U')
		return (10);
	else if (specifier == 'o' || specifier == 'O')
		return (8);
	return (-1);
}

void	xdtypes(t_p_args *fmt_args)
{
	if (*(fmt_args->format) == '%')
		fmt_args->ret += f_putchar(*(fmt_args->format));
	else
		x_check_arg(fmt_args);
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_p_args	fmt;

	fmt.format = (char*)format;
	fmt.args = &args;
	va_start(args, format);
	x_init_struct(&fmt);
	if (!format)
		return (-1);
	while (*(fmt.format) != '\0')
	{
		if (*(fmt.format) == '%')
		{
			(fmt.format++);
			xdtypes(&fmt);
		}
		else
			fmt.ret += f_putchar(*(fmt.format));
		(fmt.format++);
	}
	ragnarok(&fmt);
	va_end(args);
	return (fmt.ret);
}
