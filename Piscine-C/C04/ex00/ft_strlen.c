/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wgan@student.42kl.edu.my>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:15:48 by wgan              #+#    #+#             */
/*   Updated: 2025/09/23 15:15:49 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

/*#include <stdio.h>
int	main(void)
{
	char	*string;

	string = "Hello world!";
	//string = "abcdefghijklmnopqrstuvwxyz";
	printf("Output length of %s: %i\n", string, ft_strlen(string));
}*/
