/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:39:16 by wgan              #+#    #+#             */
/*   Updated: 2025/09/13 17:39:17 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	new_a;
	int	new_b;

	new_a = *b;
	new_b = *a;
	*a = new_a;
	*b = new_b;
}

/*int	main(void)
{
	int	num1;
	int	num2;
	int	*numa;
	int	*numb;

	num1 = 42;
	num2 = 69;
	numa = &num1;
	numb = &num2;
	printf("Num 1 value: %d\n", num1);
	printf("Num 2 value: %d\n", num2);
	ft_swap(numa, numb);
	printf("New Num 1 value: %d\n", num1);
	printf("New Num 2 value: %d\n", num2);
}*/
