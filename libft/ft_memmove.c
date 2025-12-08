/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:47:34 by wgan              #+#    #+#             */
/*   Updated: 2025/10/29 11:49:06 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d > s || d + n < s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char 	src[] = "lorem ipsum dolor sit amet";
	char    *dest = src + 1;
	//printf("dest: %s\n", dest);
	//printf("%s\n", (char *)ft_memmove(dest, "consectetur", 5));
	//printf("%s\n", (char *)ft_memmove(dest, "con\0sec\0\0te\0tur", 10));
	//printf("%s\n", (char *)ft_memmove(dest, src, 8));
	printf("%s\n", (char *)ft_memmove(src, dest, 8));
	//printf("%s\n", (char *)ft_memmove(src, dest, 0));
	//printf("expected: %s\n", (char *)memmove(src, dest, 8));
}*/
