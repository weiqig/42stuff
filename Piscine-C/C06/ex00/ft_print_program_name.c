/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:44:42 by wgan              #+#    #+#             */
/*   Updated: 2025/09/29 21:44:44 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *str)
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
	if (argc > 1)
		return (0);
	else
		ft_print_program_name(argv[0]);
}
