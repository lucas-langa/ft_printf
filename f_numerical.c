/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_numerical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:21:28 by llanga            #+#    #+#             */
/*   Updated: 2018/08/23 14:36:50 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		f_tolower(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			*str += 32;
		str++;
	}
}

static char		*mk_str(char *str, int pos, intmax_t nbr, int base)
{
	while (pos--)
	{
		str[pos] = nbr % base + '0';
		nbr /= base;
		if (str[pos] > '9')
			str[pos] += 7;
	}
	return (str);
}

static void		mkneg(intmax_t *nbr, int *negator, int base)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		if (base != 10)
			*nbr = (LONG_MAX) - *nbr;
		else if (base == 10)
			*negator = 1;
	}
}

char			*f_itoa_base(intmax_t nbr, int base, int *ret, char format)
{
	intmax_t	temp;
	int			negator;
	int			pos;
	char		*str;

	temp = nbr;
	if (base < 2 || base > 16)
		return (NULL);
	str = NULL;
	pos = 2;
	negator = 0;
	mkneg(&nbr, &negator, base);
	temp = nbr;
	while (temp /= base)
		pos++;
	pos += negator;
	if (!(str = ft_strnew(pos - 1)))
		return (NULL);
	str[--pos] = '\0';
	str = mk_str(str, pos, nbr, base);
	(negator && base == 10) ? str[0] = '-' : 0;
	(format == 'x' || format == 'p') ? f_tolower(str) : 0;
	(format == 'p') ? str = ft_strjoin("0x", str) : 0;
	*ret += ft_strlen(str);
	return (str);
}
