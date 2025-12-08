/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:39:40 by wgan              #+#    #+#             */
/*   Updated: 2025/09/28 11:57:36 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n)
	{
		if (s1[idx] != s2[idx] || s1[idx] == '\0')
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	else
	{
		printf("s1:%s\ns2:%s\nsize:%i\n", argv[1], argv[2], atoi(argv[3]));
		printf("Output: %i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("Expected: %i\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	}
}*/
