/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:33:45 by llanga            #+#    #+#             */
/*   Updated: 2018/08/23 14:35:54 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_check_arg(t_p_args *fmt_args)
{
	x_check_flags(fmt_args);
	x_save_args(fmt_args);
	x_save_el_args(fmt_args);
	x_save_2els_args(fmt_args);
	x_save_h_args(fmt_args);
	x_save_j_args(fmt_args);
	x_save_2h_args(fmt_args);
	x_save_z_args(fmt_args);
	x_assign_pound(fmt_args);
	x_do_the_plus_thing(fmt_args);
	x_do_the_space_thing(fmt_args);
	x_save_z_args(fmt_args);
	if (fmt_args->specifier == 's')
		fmt_args->ret += f_putstr(fmt_args->nbr_data_res);
	else if (fmt_args->specifier == 'c')
		fmt_args->ret += f_putchar(fmt_args->char_arg);
	else if (fmt_args->specifier != '\0')
		f_putstr(fmt_args->nbr_data_res);
	return ;
}

void	x_check_flags(t_p_args *fmt_args)
{
	while ((*(fmt_args->format) == '#' || *(fmt_args->format) == '0' \
	|| *(fmt_args->format) == '-' || *(fmt_args->format) == ' ' || \
	*(fmt_args->format) == '+') && *(fmt_args->format) != '\0')
	{
		if (*(fmt_args->format) == '#')
			fmt_args->poundisat = ft_indexof(fmt_args->format, '#');
		if (*(fmt_args->format) == '0')
			fmt_args->zero_pad = ft_indexof(fmt_args->format, '0');
		if (*(fmt_args->format) == '-')
			fmt_args->lpadisat = ft_indexof(fmt_args->format, '-');
		if (*(fmt_args->format) == ' ')
			fmt_args->space_thing = ft_indexof(fmt_args->format, ' ');
		if (*(fmt_args->format) == '+')
			fmt_args->plus_sign = ft_indexof(fmt_args->format, '+');
		(fmt_args->format++);
	}
	return ;
}

void	x_assign_pound(t_p_args *fmt_args)
{
	if (fmt_args->poundisat >= 0 && fmt_args->xoflags > 0)
	{
		if (fmt_args->specifier == 'o')
		{
			fmt_args->nbr_data_res = ft_strjoin("0", fmt_args->nbr_data_res);
			fmt_args->ret += 1;
		}
		if (fmt_args->specifier == 'X')
		{
			fmt_args->nbr_data_res = ft_strjoin("0X", fmt_args->nbr_data_res);
			fmt_args->ret += 2;
		}
		if (fmt_args->specifier == 'x')
		{
			fmt_args->nbr_data_res = ft_strjoin("0x", fmt_args->nbr_data_res);
			fmt_args->ret += 2;
		}
		else
			return ;
	}
	return ;
}

void	x_do_the_space_thing(t_p_args *fmt_args)
{
	int wtf;

	wtf = 0;
	if (fmt_args->plus_sign >= 0)
		return ;
	if (fmt_args->space_thing >= 0 && ft_strchr("diD", \
	fmt_args->specifier) && fmt_args->xoflags >= 0)
	{
		wtf = ft_atoi(fmt_args->nbr_data_res);
		if (wtf >= 0)
			fmt_args->nbr_data_res = ft_strjoin(" ", fmt_args->nbr_data_res);
	}
	return ;
}

void	x_do_the_plus_thing(t_p_args *fmt_args)
{
	if (fmt_args->plus_sign >= 0)
	{
		if (ft_strchr("diD", fmt_args->specifier) != NULL \
		&& fmt_args->xoflags >= 0)
			fmt_args->ret += f_putchar('+');
	}
	return ;
}
