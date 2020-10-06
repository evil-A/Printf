/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:36:02 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:31:56 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_some *some)
{
	some->sline = 0;
	some->str = NULL;
	some->len = 0;
	some->width = 0;
	some->precision = 0;
	some->zero = 0;
	some->point = 0;
	some->hyphen = 0;
	some->pos = 0;
	some->posline = 0;
	some->val = 0;
}

void	clean_struct(t_some *some)
{
	some->str = NULL;
	some->len = 0;
	some->width = 0;
	some->precision = 0;
	some->zero = 0;
	some->point = 0;
	some->hyphen = 0;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (c == *s)
		return ((char*)s);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i], sizeof(s[i]));
			i++;
		}
	}
}
