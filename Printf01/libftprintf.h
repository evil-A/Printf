/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:27:05 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/16 14:57:19 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_some
{
	const char	*sline;
	va_list		args;
	char		*str;
	int			len;
	int			width;
	int			precision;
	int			zero;
	int			point;
	int			hyphen;
	int			pos;
	int			posline;
	int			val;
}					t_some;

int					ft_printf(const char *line, ...);
void				init_struct(t_some *some);
void				clean_struct(t_some *some);
void				ft_putchar_fd(char c, int fd);
char				*ft_strchr(const char *s, int c);
void				ft_putstr_fd(char *s, int fd);
char				*ft_itoa(int n);
char				*ft_itu(unsigned int n);
char				*ft_itox(unsigned long n);
char				*ft_itoxx(unsigned int n);
int					len(long nb);
int					lenx(unsigned long nb);
size_t				ft_strlen(const char *s);
void				p_zero(t_some *some);
void				p_space(t_some *some);
void				zero_flag(t_some *some);
void				gotoparser(t_some *some);
void				strhyp(t_some *some);
void				putspa(t_some *some);
void				putpo(t_some *some);
void				putze(t_some *some);
void				neg(t_some *some);
void				p_hyp(t_some *some);
void				z_val(t_some *some);
void				fix(t_some *some);
void				inter(t_some *some);
void				f_hyp(t_some *some);
void				f_z(t_some *some);
void				f_left(t_some *some);
void				unsign(t_some *some);
void				hex(t_some *some);
void				hexx(t_some *some);
void				ponter(t_some *some);
void				per(t_some *some);
void				p_val(t_some *some);
void				pz(t_some *some);
void				cha(t_some *some);
void				stringer(t_some *some);
void				init_string(t_some *some);
void				point_string(t_some *some);

#endif
