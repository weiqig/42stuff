/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wgan@student.42kl.edu.my>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:25:37 by wgan              #+#    #+#             */
/*   Updated: 2025/09/23 15:25:39 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*ptr;

	ptr = argv[1];
	if (argc != 2)
		printf("Invalid input");
	else
		ft_putstr(ptr);
}*/
