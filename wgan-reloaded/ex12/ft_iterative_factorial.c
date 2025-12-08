/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:18:48 by wgan              #+#    #+#             */
/*   Updated: 2025/10/13 17:19:02 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (result);
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if  (argc != 2)
		return (0);
	else
		printf("%i\n", ft_iterative_factorial(atoi(argv[1])));
}*/
