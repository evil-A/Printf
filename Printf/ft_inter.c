/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:01:05 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/11 10:03:00 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_zero(t_some *some)
{
	if (some->str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		some->str++;
		if (some->precision && !some->zero)
			some->precision++;
	}
}

void	p_hyp(t_some *some)
{
	if (some->str[0] == '-' && some->precision)
	{
		ft_putchar_fd('-', 1);
		some->str++;
		some->precision++;
	}
}

void	fix(t_some* some)
{
	if (some->len > some->precision && some->precision)
	{
		some->precision = some->len;
		if (some->str[0] == '-')
			some->precision--;
		if (!some->width)
			some->precision--;
	}
	else if (some->precision > some->width)
	{
		some->width = some->precision;
		if (some->str[0] == '-')
		{
			some->width++;
			if (some->len >= some->precision)
				some->precision++;
		}
	}
}

void	inter(t_some *some)
{
	int	d;

	d = va_arg(some->args, int);
	if (d == 0 && !some->val && some->point)
	{
		some->len = 1;
		if (!some->precision)
		{
			if (!some->width)
			{
				some->str = "";
				some->len = 0;
			}
			else if (!some->precision || some->width)
				some->str = " ";
		}
		else
			some->str = "0";
	}
	else
	{
		some->str = ft_itoa(d);
		some->len = ft_strlen(some->str);
	}
	fix(some);
	if (some->hyphen)
	{
		p_hyp(some);
		while (some->precision > some->len && some->precision)
		{
			ft_putchar_fd('0', 1);
			some->precision--;
			some->width--;
			some->posline++;
		}
		ft_putstr_fd(some->str, 1);
		while (some->width > some->len)
		{
			ft_putchar_fd(' ', 1);
			some->len++;
		}
	}
	else if (some->zero)
	{
		if (some->str[0] == '-' && some->precision)
			some->precision++;
		while (some->width > some->precision && some->precision)
		{
			ft_putchar_fd(' ', 1);
			some->width--;
			some->posline++;
		}
		p_zero(some);
		while (some->precision > some->len && some->precision)
		{
			ft_putchar_fd('0', 1);
			some->precision--;
			some->posline++;
		}
		while (some->width > some->len && !some->precision)
		{
			ft_putchar_fd('0', 1);
			some->width--;
			some->posline++;
		}
		ft_putstr_fd(some->str, 1);
	}
	else if (!some->hyphen)
	{
		if (some->precision)
		{
			if (some->str[0] == '-')
				some->width--;
			while (some->width > some->precision)
			{
				ft_putchar_fd(' ', 1);
				some->width--;
				some->posline++;
			}
			p_zero(some);
			while (some->precision > some->len)
			{
				ft_putchar_fd('0', 1);
				some->precision--;
				some->posline++;
			}
		}
		else if (!some->precision)
		{
			while (some->width > some->len)
			{
				ft_putchar_fd(' ', 1);
				some->width--;
				some->posline++;
			}
		}
		ft_putstr_fd(some->str, 1);
	}
	some->pos++;
	some->posline += some->len;
}
