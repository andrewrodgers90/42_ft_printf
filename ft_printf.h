/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:47:38 by arodgers          #+#    #+#             */
/*   Updated: 2023/10/09 16:19:21 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_parse(char *c, va_list *args);

int		ft_putnbr(int n);

int		ft_putunbr(unsigned int nbr);

int		ft_putptr(void *ptr);

int		ft_putnbr_hex(unsigned int num, char *c);

int		ft_putstr(char *s);

int		ft_putchar(int c);

#endif
