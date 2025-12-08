/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:57:32 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 15:57:43 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	else
	{
		nb *= ft_recursive_factorial(nb - 1);
	}
	return (nb);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{

	if (argc != 2)
		printf("Error");
	else
		printf("%i\n", ft_recursive_factorial(atoi(argv[1])));
}*/
