/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:23:54 by arodgers          #+#    #+#             */
/*   Updated: 2023/10/09 16:57:58 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (s[count])
	{
		count++;
	}
	write(1, s, count);
	return (count);
}

int	ft_parse(char *c, va_list *args)
{
	int	count;

	count = 0;
	if (*c == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (*c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (*c == 'd' || *c == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (*c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putptr(va_arg(*args, void *));
	}
	else if (*c == 'u')
		count += ft_putunbr(va_arg(*args, unsigned int));
	if (*c == 'x' || *c == 'X')
		count += ft_putnbr_hex(va_arg(*args, unsigned int), c);
	if (*c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_parse((char *)format, &args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
