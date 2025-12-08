/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:03:31 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 16:37:59 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexl(unsigned int nbr)
{
	int	count;

	count = 0;
	count += ft_putnbr_base(nbr, "0123456789abcdef");
	return (count);
}
