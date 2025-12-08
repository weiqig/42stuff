/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:02:14 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 16:38:13 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer(int n)
{
	long	nbr;
	int		count;

	nbr = (long)n;
	count = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		count++;
	}
	count += ft_putnbr_base((unsigned long)nbr, "0123456789");
	return (count);
}
