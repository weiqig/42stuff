/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:44:50 by wgan              #+#    #+#             */
/*   Updated: 2025/10/01 18:44:53 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_len;
	unsigned int	src_len;

	idx = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (dest_len + idx + 1 < size && idx < size - dest_len - 1)
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	if (size <= 0 || size < dest_len)
		return (size + src_len);
	if (size > dest_len + src_len)
		return (dest_len + src_len);
	return (dest_len + idx);
}

/*int	main(int argc, char *argv[])
{
	if (argc != 4)
		printf("Eww");
	else
		printf("Length: %i\n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
}*/
