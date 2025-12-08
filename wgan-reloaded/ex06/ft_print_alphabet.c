/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:20:33 by wgan              #+#    #+#             */
/*   Updated: 2025/10/13 17:20:36 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	abc;
	int		idx;

	abc = 'a';
	idx = 0;
	while (abc <= 'z')
	{
		ft_putchar(abc);
		abc++;
		idx++;
	}
}

/*int	main(void)
{
	ft_print_alphabet();
}*/
