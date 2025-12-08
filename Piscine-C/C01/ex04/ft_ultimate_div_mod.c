/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:54:14 by wgan              #+#    #+#             */
/*   Updated: 2025/09/14 14:54:17 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*adiv;
	int	*bmod;

	a = 42;
	b = 10;
	adiv = &a;
	bmod = &b;
	printf("The div and mod of %d and %d is: ", a, b);
	ft_ultimate_div_mod(adiv, bmod);
	printf("%d and %d\n", a, b);
}*/
