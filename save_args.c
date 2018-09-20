/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:11:42 by llanga            #+#    #+#             */
/*   Updated: 2018/08/23 10:25:05 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_save_h_args(t_p_args *fmt_args)
{
	int base;

	base = 0;
	if (*fmt_args->format == 'h')
	{
		if (ft_strchr("di", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((short)\
			va_arg(*fmt_args->args, int), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format++;
		}
		else if (ft_strchr("OouxX", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((unsigned short)\
			va_arg(*fmt_args->args, unsigned int), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format++;
		}
	}
	return ;
}

void	x_save_z_args(t_p_args *fmt_args)
{
	int base;

	base = 0;
	if (*fmt_args->format == 'z')
	{
		if (ft_strchr("di", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((ssize_t)\
			va_arg(*fmt_args->args, ssize_t), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format++;
		}
		else if (ft_strchr("OouxX", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((size_t)\
			va_arg(*fmt_args->args, size_t), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format++;
		}
	}
	return ;
}

void	x_save_el_args(t_p_args *fmt_args)
{
	int base;

	base = 0;
	if (*fmt_args->format == 'l')
	{
		if (ft_strchr("di", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((long)\
			va_arg(*fmt_args->args, intmax_t), base, &fmt_args->ret, 'd');
			fmt_args->format++;
		}
		else if (ft_strchr("OouxX", *(fmt_args->format + 1)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 1);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((unsigned long)\
			va_arg(*fmt_args->args, uintmax_t), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format++;
		}
	}
	return ;
}

void	x_save_2els_args(t_p_args *fmt_args)
{
	int base;

	base = 0;
	if (ft_strstr(fmt_args->format, "ll") != NULL)
	{
		if (ft_strchr("di", *(fmt_args->format + 2)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 2);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((long long)\
			va_arg(*fmt_args->args, intmax_t), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format += 2;
		}
		else if (ft_strchr("OouxX", *(fmt_args->format + 2)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 2);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((unsigned long long)\
			va_arg(*fmt_args->args, uintmax_t), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format += 2;
		}
	}
	return ;
}

void	x_save_2h_args(t_p_args *fmt_args)
{
	int base;

	base = 0;
	if (ft_strstr(fmt_args->format, "hh") != NULL)
	{
		if (ft_strchr("di", *(fmt_args->format + 2)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 2);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((char)\
			va_arg(*fmt_args->args, int), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format += 2;
		}
		else if (ft_strchr("OouxX", *(fmt_args->format + 2)) != NULL)
		{
			fmt_args->specifier = *(fmt_args->format + 2);
			base = gimme_nbr_base(fmt_args->specifier);
			fmt_args->nbr_data_res = f_itoa_base((unsigned char)\
			va_arg(*fmt_args->args, int), base, &fmt_args->ret,\
			fmt_args->specifier);
			fmt_args->format += 2;
		}
	}
	return ;
}
