/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:24:27 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:09:02 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
/*#include <stdio.h>
int	main(void)
{
	int	size = 10;
	char	destination[10] = "test";
	char	source[15] = "Hello, world!";

	printf("current destination: %s\n", destination);
	printf("Source string: %s\n", source);
	printf("Source length: %i\n", ft_strlen(source));
	printf("Buffer size: %i\n", size);
	printf("Srclen returned: %u\n", ft_strlcpy(destination, source, size));
	printf("Final destination: %s\n", destination);
}*/
