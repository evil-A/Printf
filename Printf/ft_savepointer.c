/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:47:52 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/12 12:19:46 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ponter(t_some *some) //poner el 0x donde el - en los enteros
{
	unsigned int	d;

	d = va_arg(some->args, unsigned int);
	if (!d && some->point)
	{
//		printf("no d");
		some->str = "0x";
		some->len = 2;	
	}
	else if (d == 0 && !some->val && some->point)
	{
//		printf("p_val");
		p_val(some);
	}
	else
	{
//		printf("normal");
		some->str = ft_itox(d);
		some->len = ft_strlen(some->str);
	}
//	printf("-- %s -- %d --", some->str, some->len);
	fix(some);
	if (some->hyphen)
		f_hyp(some);
	else if (some->zero)
		f_z(some);
	else if (!some->hyphen)
	{
		f_left(some);
		ft_putstr_fd(some->str, 1);
	}
	some->pos++;
	some->posline += some->len;
}
