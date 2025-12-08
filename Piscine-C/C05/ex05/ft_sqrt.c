/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:27:24 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 19:27:27 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	nbr;

	nbr = 1;
	if (nb == 1)
		return (nbr);
	while (nbr < nb)
	{
		if (nbr * nbr == nb)
			return (nbr);
		nbr++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	int	i;
	//for (i = 0; i <= 64; i++){
	//		printf("Square root of %i is %i\n", i, ft_sqrt(i));
	//}
	if (argc != 2)
		return (0);
	else
	i = ft_sqrt(atoi(argv[1]));
		printf("Square root of %i is %i\n", atoi(argv[1]), i);
}*/
