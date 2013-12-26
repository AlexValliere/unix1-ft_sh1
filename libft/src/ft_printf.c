/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:26:18 by apetit            #+#    #+#             */
/*   Updated: 2013/12/22 19:21:39 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

static int	ft_printf_check_opt_precision(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '.')
	{
		++i;
		while (ft_isdigit(str[i]) == 1)
			++i;
	}
	return (i);
}

static int	ft_printf_check_opt(const char *str)
{
	int		i;

	i = 0;
	i = ft_printf_check_opt_precision(str);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = i + ft_printf_check_opt(&format[i + 1]);
			if (format[i + 1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putnbr(va_arg(args, int));
			else if (format[i + 1] == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (format[i + 1] == 'u')
				ft_putnbr_uint(va_arg(args, unsigned int));
			else
				ft_putchar(format[i + 1]);
			++i;
		}
		else
			ft_putchar(format[i]);
		++i;
	}
	va_end(args);
	return (i + 1);
}
