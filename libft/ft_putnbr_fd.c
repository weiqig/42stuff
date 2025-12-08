/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:04:20 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 18:07:30 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = (long)n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	if (i == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
		ft_putchar_fd(i + '0', fd);
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putnbr_fd(atoi(argv[1]), 2);
		printf("\n");
		ft_putnbr_fd(-2147483648LL, 2);
	}
	return (0);
}*/
