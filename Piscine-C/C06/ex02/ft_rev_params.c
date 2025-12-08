/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:45:37 by wgan              #+#    #+#             */
/*   Updated: 2025/09/29 21:45:39 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *str)
{
	int	idx;
	int	n;

	idx = 0;
	n = 0;
	while (str[idx] != '\0')
		idx++;
	while (n < idx)
	{
		write(1, &str[n], 1);
		n++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc;
	if (argc <= 1)
		return (0);
	else
		while (i > 1)
			ft_rev_params(argv[--i]);
	return (0);
}
