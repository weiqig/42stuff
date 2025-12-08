/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:26:07 by wgan              #+#    #+#             */
/*   Updated: 2025/10/01 14:26:10 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strdup(char *src)
{
	int		idx;
	int		len;
	char	*ptr;

	idx = 0;
	len = ft_strlen(src);
	ptr = 0;
	ptr = (char *)malloc(sizeof(len));
	while (src[idx] != '\0')
	{
		ptr[idx] = src[idx];
		idx++;
	}
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		printf("kekw\n");
	else
	{
		printf("Input: %s\n", argv[1]);
		printf("Duplicate: %s\n", ft_strdup(argv[1]));
	}
	return 0;
}*/
