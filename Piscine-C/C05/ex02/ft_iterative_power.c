/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:32:06 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 16:38:18 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	num;

	i = 0;
	num = 1;
	if ((nb == 0 && power == 0) || power == 0)
	{
		return (1);
	}
	if (nb == 0 || power <= 0)
	{
		return (0);
	}
	while (i < power)
	{
		num = num * nb;
		i++;
	}
	return (num);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		printf("Need 2 integer arguments\n");
	else
		printf("%i\n", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}*/
