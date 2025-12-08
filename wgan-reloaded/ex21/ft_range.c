/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:11:47 by wgan              #+#    #+#             */
/*   Updated: 2025/10/14 12:11:48 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_diff(int min, int max)
{
	int	diff;

	diff = max - min;
	if (diff < 0)
		diff = -diff;
	return (diff);
}

int	*ft_range(int min, int max)
{
	int	idx;
	int	size;
	int	*array;

	idx = 0;
	size = ft_diff(min, max);
	array = (int *)malloc(sizeof(int) * size);
	if (min >= max)
		return (NULL);
	while (idx < size)
	{
		array[idx] = min;
		idx++;
		min++;
	}
	return (array);
}

/*int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	else
	{
		printf("%i\n", *ft_range(atoi(argv[1]), atoi(argv[2])));
	}
}*/
