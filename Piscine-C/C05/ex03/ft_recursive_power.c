/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:15:52 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 18:15:57 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	int	output;

	output = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 0)
	{
		output = nb * (ft_recursive_power(nb, power - 1));
	}
	return (output);
}

/*#include <stdio.h>
#include <stdlib.h>
int     main(int argc, char *argv[])
{
        if (argc != 3)
                printf("Need 2 integer arguments\n");
        else
                printf("%i\n", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
}*/
