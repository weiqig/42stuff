/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:17:24 by wgan              #+#    #+#             */
/*   Updated: 2025/10/13 17:17:36 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	else
		printf("%i\n", ft_sqrt(atoi(argv[1])));
}*/
