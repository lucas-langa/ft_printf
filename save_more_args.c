/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_more_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:26:12 by llanga            #+#    #+#             */
/*   Updated: 2018/08/23 10:48:37 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_save_j_args(t_p_args *fmt_args)
{
	int base;

	base = 0;
	if (*fmt_args->format == 'j')
	{
		if (ft_strchr("di", *(fmt_args->format + 1)))
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base(\
			va_arg(*fmt_args->args, intmax_t), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format++;
		}
		else if (ft_strchr("OouxX", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base(va_arg(*fmt_args->args,\
			uintmax_t), base, &fmt_args->ret, fmt_args->specifier);
			fmt_args->format++;
		}
	}
	return ;
}

void	x_save_args(t_p_args *fmt_args)
{
	int base;

	base = gimme_nbr_base(*fmt_args->format);
	(*fmt_args->format == 'o' || *fmt_args->format == 'O' || *fmt_args->format\
	== 'U' || *fmt_args->format == 'u' || *fmt_args->format == 'x' || \
	*fmt_args->format == 'X') ? fmt_args->xoflags = va_arg(*fmt_args->args,\
	uintmax_t) : 0;
	*fmt_args->format == 'p' || *fmt_args->format == 'D' ? fmt_args->xoflags =\
	va_arg(*fmt_args->args, intmax_t) : 0;
	(*fmt_args->format == 'd' || *fmt_args->format == 'i') ? \
	fmt_args->xoflags = va_arg(*fmt_args->args, int) : 0;
	x_save_args_2(fmt_args, base);
	return ;
}

void	x_save_args_2(t_p_args *fmt_args, int base)
{
	char *temp;

	temp = NULL;
	if (*fmt_args->format == 'c')
	{
		fmt_args->char_arg = va_arg(*fmt_args->args, int);
		fmt_args->specifier = 'c';
	}
	if (ft_strchr("dDiuUxXpoO", *fmt_args->format) != NULL)
	{
		fmt_args->nbr_data_res = f_itoa_base(fmt_args->xoflags, base, \
		&fmt_args->ret, *fmt_args->format);
		fmt_args->specifier = *fmt_args->format;
	}
	else if (ft_strchr("s", *fmt_args->format) != NULL)
	{
		temp = va_arg(*fmt_args->args, char*);
		if (!temp)
			fmt_args->nbr_data_res = mk_push_str("(null)");
		else
			fmt_args->nbr_data_res = mk_push_str(temp);
		fmt_args->specifier = *fmt_args->format;
	}
}
