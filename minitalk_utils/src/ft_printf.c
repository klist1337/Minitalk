/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:59:22 by eassofi           #+#    #+#             */
/*   Updated: 2021/12/14 16:38:38 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	printer(char fmt, int count)
{
	if (fmt != '%')
	{
		count = ft_putchar(fmt, count);
	}
	return (count);
}

int	string_format(char fmt, va_list args, int count, char *s_args)
{
	if (fmt == 'c')
	{
		count = ft_putchar(va_arg(args, int), count);
	}
	else if (fmt == 's')
	{
		s_args = va_arg(args, char *);
		if (s_args == NULL)
			count = ft_putstr("(null)", count);
		else if (s_args != NULL)
			count = ft_putstr(s_args, count);
	}
	else if (fmt == 'p')
	{
		count = ft_putstr("0x", count);
		count = print_hex_lowercase(va_arg(args, unsigned long int), count);
	}
	return (count);
}

int	number_format(char fmt, va_list args, int count)
{
	if (fmt == 'd' || fmt == 'i')
	{
		count = ft_putnbr_int(va_arg(args, int), count);
	}
	else if (fmt == 'u')
	{
		count = ft_putnbr_uint(va_arg(args, unsigned int), count);
	}
	else if (fmt == 'x' || fmt == 'X')
	{
		if (fmt == 'x')
		{
			count = print_hex_lowercase(va_arg(args, unsigned int), count);
		}
		else
			count = print_hex_uppercase(va_arg(args, unsigned int), count);
	}
	else if (fmt == '%')
		count = ft_putchar('%', count);
	fmt++;
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	char	*s_args;

	count = 0;
	s_args = NULL;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			count = printer(*fmt, count);
		else
		{
			fmt++;
			if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u' || *fmt == 'x'
				|| *fmt == 'X' || *fmt == '%')
				count = number_format(*fmt, args, count);
			else if (*fmt == 'c' || *fmt == 's' || *fmt == 'p')
				count = string_format(*fmt, args, count, s_args);
		}
		fmt++;
	}
	va_end(args);
	return (count);
}
