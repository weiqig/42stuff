/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:45:50 by wgan              #+#    #+#             */
/*   Updated: 2025/09/29 21:45:51 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_sort_params(char *str, int argc);

int	ft_sort_params(char *str, int argc)
{
	int	current;
	int	temp;

	current = 0;
	temp = 0;
	while (argc > 1)
	{
		printf("%s\n", str[current]);
		argc--;
	}
	return (0);
}

int	ft_get_value(char *str)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		i += str[idx];
		idx++;
	}
	return (i);
}

int	ft_print_program_name(char *str)
{
	int	idx;
	int	n;
	int	value;

	idx = 0;
	n = 0;
	value = 0;
	while (str[idx] != '\0')
		idx++;
	while (n < idx)
	{
		write(1, &str[n], 1);
		n++;
	}
	write (1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*ptr;

	i = 1;
	ptr = 0;
	if (argc <= 1)
		return (0);
	else
	{
		printf("value of %s: %i\n", argv[1], ft_get_value(argv[1]));
	}
	while (i < argc)
	{
		ft_sort_params(argv[i], argc);
		ft_print_program_name(argv[--i]);
	}
	return (0);
}
