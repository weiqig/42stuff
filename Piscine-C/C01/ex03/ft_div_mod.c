/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:40:18 by wgan              #+#    #+#             */
/*   Updated: 2025/09/14 14:40:25 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	div;
	int	mod;
	int	*pdiv;
	int	*pmod;

	pdiv = &div;
	pmod = &mod;
	ft_div_mod(42, 12, pdiv, pmod);
	printf("Div value: %d\n", div);
	printf("Mod value: %d\n", mod);
}*/
