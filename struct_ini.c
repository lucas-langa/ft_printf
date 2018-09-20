/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:31:17 by llanga            #+#    #+#             */
/*   Updated: 2018/08/22 18:31:19 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_init_struct(t_p_args *fmt_args)
{
	fmt_args->xoflags = 0;
	fmt_args->ret = 0;
	fmt_args->pound = -1;
	fmt_args->negsignisat = -1;
	fmt_args->space_thing = -1;
	fmt_args->plus_sign = -1;
	fmt_args->poundisat = -1;
	fmt_args->zero_pad = -1;
	fmt_args->lpadisat = -1;
	fmt_args->nbr_data_res = NULL;
	fmt_args->specifier = '\0';
	fmt_args->char_arg = '\0';
	return ;
}

void	ragnarok(t_p_args *fmt_args)
{
	fmt_args->nbr_data_res != NULL ? \
	ft_strdel(&fmt_args->nbr_data_res) : 0;
	return ;
}
