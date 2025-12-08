/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:09:37 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 18:11:20 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char *)s;
	while (n-- > 0)
		*m++ = c;
	return (s);
}

/*int	main(void)
{
	char	s[12] = "Hello World";
	printf("%s\n", (char *)ft_memset(s, 'e', 10));
	return (0);
}*/
