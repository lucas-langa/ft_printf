/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:52:12 by llanga            #+#    #+#             */
/*   Updated: 2018/08/22 17:03:39 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <limits.h>

typedef struct		s_p_args
{
	char			*format;
	intmax_t		xoflags;
	va_list			*args;
	int				ret;
	int				pound;
	int				negsignisat;
	int				space_thing;
	int				plus_sign;
	int				poundisat;
	int				zero_pad;
	int				lpadisat;
	char			*nbr_data_res;
	char			specifier;
	char			char_arg;
}					t_p_args;

void				ft_memdel(void **ap);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *s1, const char *s2);
int					ft_indexof(char *str, char c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strstr(const char *haystack, const char *needle);
void				x_handle_zpad(t_p_args *fmt_args);
void				xdtypes(t_p_args *fmt_args);
void				x_check_flags(t_p_args *fmt_args);
void				x_assign_flags(t_p_args *fmt_args);
int					ft_printf(const char *format, ...);
int					f_putchar(char c);
int					f_putstr(char *str);
int					f_putnbr(int nbr);
char				*f_itoa_base(intmax_t nbr, int base, int *ret, char format);
void				x_save_h_args(t_p_args *fmt_args);
void				x_save_z_args(t_p_args *fmt_args);
void				x_save_el_args(t_p_args *fmt_args);
void				x_save_2els_args(t_p_args *fmt_args);
void				x_save_2h_args(t_p_args *fmt_args);
void				x_save_j_args(t_p_args *fmt_args);
void				x_save_args(t_p_args *fmt_args);
void				x_save_args_2(t_p_args *fmt_args, int base);
void				strset(char *str, char c, size_t len);
void				x_assign_pound(t_p_args *fmt_args);
void				x_do_the_zero_thing(t_p_args *fmt_args);
void				x_do_the_space_thing(t_p_args *fmt_args);
void				x_do_the_plus_thing(t_p_args *fmt_args);
void				x_check_flags(t_p_args *fmt_args);
char				*mk_push_str(char *src);
void				x_check_arg(t_p_args *fmt_args);
void				xdtypes(t_p_args *fmt_args);
void				x_init_struct(t_p_args *fmt_args);
void				ragnarok(t_p_args *fmt_args);
int					ft_indexof(char *str, char c);
int					gimme_nbr_base(char specifier);

#endif
