/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:39:34 by wgan              #+#    #+#             */
/*   Updated: 2025/09/15 16:51:20 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	swap(int *idx1, int *idx2)
{
	int	temp;

	temp = *idx1;
	*idx1 = *idx2;
	*idx2 = temp;
}

void	check_if_swapped(int i, int *j)
{
	if (i != 0)
	{
		*j = 0;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	swapped;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		swapped = 0;
		while (j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				swap(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		check_if_swapped(swapped, &j);
		i++;
	}
}

/*void print_array(int arr[], int size){
	int	i;
	for (i = 0; i < size; i++)
	{
        	printf("%d ", arr[i]);
	}
	printf("\n");
}

int	main(void)
{
	int	*ptr;
	int	size;
	int count = 0;

	int array[] = {42, 1, -111111, 9932, -123, 420, 1337};
	ptr = array;
	size = 7;
	//printf("%p\n", ptr);
	//printf("%d\n", size);
	print_array(array, size);
	ft_sort_int_tab(ptr, size);
	print_array(array, size);
}*/
