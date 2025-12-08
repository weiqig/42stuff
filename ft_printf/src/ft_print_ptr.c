/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:01:22 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 16:38:20 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(void *p)
{
	int				count;
	unsigned long	addr;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	addr = (unsigned long)p;
	write(1, "0x", 2);
	count += ft_putnbr_base(addr, "0123456789abcdef");
	return (count);
}
