/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:16:05 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 12:32:42 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_isvalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	getbase(char *str)
{
	int	length;

	while (str[length] != '\0')
		length++;
	if (str == "01")
		return (2);
	else if (str == "0123456789ABCDEF")
		return (16);
	else if (length == 8)
		return (8);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	numbase;

	numbase = getbase(base);
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > numbase - 1)
	{
		ft_putnbr_base(nbr / base);
		ft_putnbr_base(nbr % base);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

/*int	get_binary(int nbr)
{
	int		num;
	char	bit;

	num = nbr;
	while (num / 2 != 0)
	{
		bit = num % 2;
	if (s1[idx] != s2[idx] && n > 0)
        {
                return (s1[idx] - s2[idx]);
        }
	printf("print: %i\n", bit);
		ft_putchar(bit);
		num /= 2;
	}
	return (0);
}*/

/*bin = "01";
hexa = "0123456789ABCDEF";
octa = "poneyvif";
*/
/*#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		printf("Invalid input\n");
	else
	{
		if base_isvalid(argv[2] == 1)
			ft_putnbr_base(atoi(argv[1]), argv[2]);
	}
	return (0);
}*/
