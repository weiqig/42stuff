/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:43:36 by wgan              #+#    #+#             */
/*   Updated: 2025/10/13 17:43:38 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c);

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx])
		idx++;
	if (s1[idx] != s2[idx])
		return (s1[idx] - s2[idx]);
	return (0);
}

void	ft_swap(char **val1, char **val2)
{
	char	*temp;

	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void	ft_sort_params(int argc, char **argv)
{
	int	idx;
	int	swapped;

	idx = 1;
	swapped = 0;
	while (idx < argc - 1)
	{
		if (ft_strcmp(argv[idx], argv[idx + 1]) > 0)
		{
			ft_swap(&argv[idx], &argv[idx + 1]);
			swapped = 1;
		}
		if (swapped == 1)
		{
			idx = 1;
			swapped = 0;
		}
		else
			idx++;
	}
	idx = 0;
	ft_print_params(argc, argv);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	else
		ft_sort_params(argc, argv);
	return (0);
}
