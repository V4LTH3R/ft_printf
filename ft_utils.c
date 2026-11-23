/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v4lth3r <v4lth3r@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:39:47 by v4lth3r          #+#    #+#             */
/*   Updated: 2026/11/09 11:39:48 by v4lth3r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;
	return (write(1, &cc, 1));
}

int	ft_string(char *str)
{
	int	len;
	int	check;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
	{
		if (len == INT_MAX)
			return (-1);
		check = write(1, &str[len], 1);
		if (check == -1)
			return (-1);
		len += check;
	}
	return (len);
}

int	ft_pointer(void *ptr)
{
	int	len;
	int	recs;

	len = 0;
	recs = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (ft_string("0x") == -1)
		return (-1);
	len += 2;
	recs = ft_hexa((unsigned long)ptr, 'x');
	if (recs == -1)
		return (-1);
	len += recs;
	return (len);
}

int	ft_number(long nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_number(nb / 10);
	}
	count += ft_char('0' + (nb % 10));
	return (count);
}

int	ft_hexa(unsigned long nb, char x)
{
	int		len;
	char	*base;
	int		recs;

	len = 0;
	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb > 15)
	{
		recs = ft_hexa((nb / 16), x);
		if (recs == -1)
			return (-1);
		len += recs;
	}
	if (write(1, &base[nb % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}
