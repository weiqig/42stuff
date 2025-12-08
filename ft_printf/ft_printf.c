/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:04:27 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 16:38:43 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list *args, const char *c)
{
	int	count;

	count = 0;
	if (*c == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (*c == 's')
		count += ft_print_str(va_arg(*args, char *));
	else if (*c == 'p')
		count += ft_print_ptr(va_arg(*args, void *));
	else if (*c == 'd')
		count += ft_print_decimal(va_arg(*args, long));
	else if (*c == 'i')
		count += ft_print_integer(va_arg(*args, long));
	else if (*c == 'u')
		count += ft_print_unsigned(va_arg(*args, unsigned long));
	else if (*c == 'x')
		count += ft_print_hexl(va_arg(*args, unsigned long));
	else if (*c == 'X')
		count += ft_print_hexu(va_arg(*args, unsigned long));
	else if (*c == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
				if (*str++)
					count += ft_check_format(&args, str);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
