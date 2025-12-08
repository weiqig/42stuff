/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:01:45 by wgan              #+#    #+#             */
/*   Updated: 2025/11/03 16:01:45 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_decimal(int n)
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

/*int	main(void)
{
	ft_print_decimal(0);
	ft_print_decimal(-1);
	ft_print_decimal(1);
	ft_print_decimal(9);
	ft_print_decimal(10);
	ft_print_decimal(11);
	ft_print_decimal(15);
	ft_print_decimal(16);
	ft_print_decimal(17);
	ft_print_decimal(99);
}*/
