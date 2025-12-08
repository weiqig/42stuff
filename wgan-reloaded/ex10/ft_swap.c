/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:19:37 by wgan              #+#    #+#             */
/*   Updated: 2025/10/13 17:19:40 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*#include <stdio.h>
int	main(void)
{
	int	i;
	int	j;
	int	*k;
	int	*l;

	i = 42;
	j = 69;
	k = &i;
	l = &j;
	printf("%i | %i\n", i, j);
	ft_swap(k, l);
	printf("%i | %i\n", i, j);
}*/
