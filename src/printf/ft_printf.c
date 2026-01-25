/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icezar-s <icezar-s@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:51:40 by icezar-s          #+#    #+#             */
/*   Updated: 2025/12/06 14:56:41 by icezar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_printf_juggler(char conversor, va_list ap, int *count)
{
	if (conversor == 'c')
		*count += ft_putcharc(va_arg(ap, int));
	else if (conversor == 'd' || conversor == 'i')
		*count += ft_putnbrc(va_arg(ap, int));
	else if (conversor == 's')
		*count += ft_putstrc(va_arg(ap, char *));
	else if (conversor == 'p')
		*count += ft_putaddressc(va_arg(ap, void *));
	else if (conversor == 'u')
		*count += ft_putunbrc(va_arg(ap, unsigned int));
	else if (conversor == 'x' || conversor == 'X')
		*count += ft_puthexc(conversor, va_arg(ap, unsigned int));
	else if (conversor == '%')
		*count += ft_putcharc('%');
}

int	ft_printf(const char *fmt, ...)
{
	va_list					ap;
	int						count;
	const char				*p;

	va_start(ap, fmt);
	p = fmt;
	count = 0;
	while (*p)
	{
		if (*p != '%')
		{
			count += ft_putcharc(*p);
		}
		else if (*p == '%')
			ft_printf_juggler(*(++p), ap, &count);
		p++;
	}
	va_end(ap);
	return (count);
}
