/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:15:17 by wgan              #+#    #+#             */
/*   Updated: 2025/10/29 14:15:46 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*str1;
	unsigned char	*str2;

	idx = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		idx++;
	}
	return (0);
}

/*int	main(void)
{
	char s1[10] = "abcdefg";
	char s2[10] = "abcabcz";
	printf("%i\n", ft_memcmp(s1, s2, 5));
	printf("%i\n", ft_memcmp("t\200", "t\0", 2));
}*/
