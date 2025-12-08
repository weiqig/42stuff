/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:49 by wgan              #+#    #+#             */
/*   Updated: 2025/10/14 12:13:52 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_bool_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '1')
		return (1);
	else
		return (0);
}*/

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (tab[i])
	{
		if ((f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*int	main(int argc, char **argv)
{
	int	i;
	int(*my_ft)(char*) = ft_bool_int;

	if (argc <= 1)
		return (0);
	else
		printf("%i\n", ft_count_if(argv, my_ft));
	return (0);
}*/
