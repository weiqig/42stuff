/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wgan@student.42kl.edu.my>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:01:33 by wgan              #+#    #+#             */
/*   Updated: 2025/09/23 18:01:36 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	idx;
	int	sign;
	int	result;

	idx = 0;
	sign = 1;
	result = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	while (str[idx] == '-' || str[idx] == '+')
		if (str[idx++] == '-')
			sign = -sign;
	while (str[idx] >= '0' && str[idx] <= '9')
		result = result * 10 + str[idx++] - '0';
	if (result != 0)
		return (result * sign);
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		printf("Bro");
	else
		printf("stdlib: %i , mine: %i\n", atoi(argv[1]), ft_atoi(argv[1]));
}*/
