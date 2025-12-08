/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:46:08 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 16:38:33 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				count;
	unsigned long	baselen;

	count = 0;
	baselen = ft_strlen(base);
	if (nbr >= baselen)
		count += ft_putnbr_base(nbr / baselen, base);
	ft_putchar(base[nbr % baselen]);
	count++;
	return (count);
}
