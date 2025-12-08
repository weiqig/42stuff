/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:03:43 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 16:38:05 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexu(unsigned int nbr)
{
	int	count;

	count = 0;
	count += ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (count);
}
