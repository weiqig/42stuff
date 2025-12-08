/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:15 by wgan              #+#    #+#             */
/*   Updated: 2025/10/15 17:47:02 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_is_n(int i)
{
	if (i < 0)
		write(1, "N\n", 2);
	else
		write(1, "P\n", 2);
}*/

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(f)(tab[i]);
		i++;
	}
}

/*int	main()
{
	int tab[] = {1, 4, 5, 7, -3, -5, 5};
	void (*is_n_ptr)(int) = &ft_is_n;
	// (*is_n_ptr)(1);
	ft_foreach(tab, 7, is_n_ptr);
	return (0);
}*/
