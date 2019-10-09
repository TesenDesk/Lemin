/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:16:36 by jjerde            #+#    #+#             */
/*   Updated: 2019/09/28 20:53:54 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_flags{
	int			end;
	char		*out;
	int			count;
}					t_flags;

typedef struct		s_prms{
	char		c;
	int			l;
	char		*f;
	int			wd;
	int			ac;
	int			zero;
	int			space;
	int			box;
	int			plus;
	int			minus;
	int			dot;
	int			valid;
	int			type;
	int			empty;
}					t_prms;

char				*ft_printf_plus(char *n);
char				*ft_printf_space(char *n);
char				*ft_printf_zero_int(char *s, int n);
int					ft_strsearch(char const *str, char c);
void				flags_loop(const char *str);
char				*ft_flags_start(char *str);
char				*ft_strreplchar(char *str, char c, char k);
char				*ft_strjoinre(char const *s1, char const *s2);
int					int_len(int c);
char				*colors_apply(char *str);
int					flag_check1(t_prms *p);
char				*re_gr(char *r, char c);
char				*ft_space(char *r);
char				*ft_plus(char *r);
char				*ft_uitoa(unsigned long long n);
char				*ft_litoa(long long n);
int					lint_len(long long c);
int					printf_one(t_prms *p, va_list factor);
void				todo(t_prms *p, va_list factor);
int					get_ac(t_prms *p, va_list factor);
int					get_wd(t_prms *p, va_list factor);
char				*mod_apply(t_prms *p, char *r);
int					flag_checker(t_prms *p);
char				*pool(t_prms *p, va_list factor);
char				*redirect_float(t_prms *p, va_list factor);
char				*redirect_char(t_prms *p, va_list factor);
char				*redirect_str(va_list factor);
char				*redirect_prc(void);
char				*redirect_int(t_prms *p, va_list factor);
long long			get_int(t_prms *p, va_list factor);
unsigned long long	get_uint(t_prms *p, va_list factor);
long double			get_double(t_prms *p, va_list factor);
char				*redirect_other(t_prms *p, va_list factor);

char				*ft_width(int i, char *str);
char				*ft_flag_e(long double i, int index, int big);
char				*ft_flag_f(long double i, int index, int big);
char				*ft_flag_o(unsigned long long i, int f);
char				*ft_flag_u(unsigned long long i);
char				*ft_flag_p(void *srr, int ac);
char				*ft_flag_x(unsigned long long i, int a, int f, int r);
char				*ft_flag_g(long double f, int index, int big);
char				*ft_flag_i(long long int i, int index);
char				*ft_zero(int i, char *str);
char				*ft_i_5(char *s, int f);
void				ft_flag_e_1(char *str, int a, int f);
void				ft_flag_e_3(char *str, int flag, int a);
char				*ft_proverka(long double i, int big);
char				*ft_str(char *str, int f);
char				*ft_sswap(char *str);
char				*ft_flag_f_1(int a, char *str, int flag);
int					ft_flag_f_0(char *str, long double i, int a, int index);
char				ft_abcd(unsigned long long i, int g);
char				*ft_minus(int i, char *str);
char				*ft_flag_g_end_free(char *str, char *str1);

#endif
