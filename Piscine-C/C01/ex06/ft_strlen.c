/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:56:18 by wgan              #+#    #+#             */
/*   Updated: 2025/09/14 15:56:22 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/*int	main(void)
{
	int	output1;
	int	output2;

	output1 = ft_strlen("test");
	printf("Length of string test is: %d\n", output1);
	output2 = ft_strlen("zimbabwe");
	printf("Length of string zimbabwe is: %d\n", output2);
}
*/
