/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v4lth3r  v4lth3r@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:01:30 by v4lth3r          #+#    #+#             */
/*   Updated: 2026/11/09 10:01:32 by v4lth3r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convo(const char type, va_list ap)
{
	if (type == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (type == 's')
		return (ft_string(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_number(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_number(va_arg(ap, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_hexa(va_arg(ap, unsigned int), type));
	else if (type == '%')
		return (ft_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				count;
	int				rtrnb;

	if (!format || write(1, "", 0) == -1)
		return (-1);
	va_start(ap, format);
	count = 0;
	rtrnb = 0;
	while (*format)
	{
		if (*format == '%')
			rtrnb = ft_convo(*(++format), ap);
		else
			rtrnb = write(1, format, 1);
		if (rtrnb < 0)
		{
			va_end(ap);
			return (-1);
		}
		count += rtrnb;
		format++;
	}
	va_end(ap);
	return (count);
}
