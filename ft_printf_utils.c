/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:08:08 by arodgers          #+#    #+#             */
/*   Updated: 2023/10/09 17:48:19 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 10)
	{
		count += ft_putchar(nbr + 48);
	}
	if (nbr >= 10)
	{
		count += ft_putunbr(nbr / 10);
		count += ft_putchar((nbr % 10) + 48);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	int				i;
	char			arr[32];
	char			*hex;
	unsigned long	add;

	hex = "0123456789abcdef";
	add = (unsigned long)ptr;
	count = 0;
	i = 0;
	if (!ptr)
		count += ft_putchar('0');
	while (add > 0)
	{
		arr[i++] = hex[add % 16];
		add /= 16;
	}
	while (i)
		count += ft_putchar(arr[--i]);
	return (count);
}

int	ft_putnbr_hex(unsigned int num, char *c)
{
	int			count;
	int			i;
	char		arr[10];
	const char	*hex;

	count = 0;
	i = 0;
	if (*c == 'x')
		hex = "0123456789abcdef";
	else if (*c == 'X')
		hex = "0123456789ABCDEF";
	if (num == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	while (num != 0)
	{
		arr[i++] = hex[num % 16];
		num /= 16;
	}
	while (i)
		count += ft_putchar(arr[--i]);
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int		i;
	char	arr[20];
	int		count;

	count = 0;
	num = n;
	i = 0;
	if (0 == n)
		count += ft_putchar('0');
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	while (num > 0)
	{
		arr[i++] = (num % 10) + 48;
		num /= 10;
	}
	while (i > 0)
		count += ft_putchar(arr[--i]);
	return (count);
}
