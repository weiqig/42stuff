/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:39:31 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 15:39:38 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	output;

	i = 0;
	output = 1;
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		output *= nb;
		nb--;
	}
	return (output);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{

	if (argc != 2)
		printf("Error");
	else
		printf("%i\n", ft_iterative_factorial(atoi(argv[1])));
}*/
