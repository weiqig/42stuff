/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:24:53 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 18:27:03 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	unsigned char		chr;
	unsigned char		*result;

	idx = 0;
	chr = (unsigned char)c;
	result = (unsigned char *)s;
	while (idx < n)
	{
		if (result[idx] == chr)
			return ((void *)&result[idx]);
		idx++;
	}
	return (NULL);
}

/*int	main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	char s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%s\n", (char *)ft_memchr("bonjour", 'b', 4));
	printf("%s\n", (char *)ft_memchr("bonjour", 'o', 7));
	printf("%s\n", (char *)ft_memchr("bonjour", 'n', 2));
	printf("%s\n", (char *)ft_memchr("bonjour", 'j', 6));
	printf("%s\n", (char *)ft_memchr("bonjour", 's', 7));
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	//printf("exp:%s\n", s + 2);
	printf("%s\n", (char *)ft_memchr(s, 2 + 256, 3));
}*/
