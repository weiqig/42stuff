/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:47:25 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 19:47:31 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2147483647)
		return (nb);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int	isprime;
	for (int i = 0; i < 100; i++){
		isprime = ft_is_prime(i);
		if (isprime == 1)
			printf("%i, ", i);
	}
}*/
/*int	main(int c, char *v[])
{
	if (c != 2)
		return (0);
	else
		printf("%i\n", ft_is_prime(atoi(v[1])));
}*/
