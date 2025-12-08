/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:28:10 by wgan              #+#    #+#             */
/*   Updated: 2025/09/15 12:28:14 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	is_even_odd(int size)
{
	int	output;

	output = size % 2;
	if (output == 1)
	{
		output = size / 2;
	}
	else
	{
		output = (size / 2) - 1;
	}
	return (output);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	range;
	int	temp;

	i = 0;
	range = is_even_odd(size);
	while (i <= range)
	{
		temp = tab[i];
		tab[i] = tab[size - (i + 1)];
		tab[size - (i + 1)] = temp;
		i++;
	}
}

/*int	main(void)
{
	int	i;
	i = 0;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int size = 8;
	printf("array size: %i\n", size);
	ft_rev_int_tab(array, size);
	while (i < size)
	{
		printf("%i, ", array[i]);
		i++;
	}
}*/
