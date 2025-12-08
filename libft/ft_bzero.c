/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:34:22 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 17:36:49 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (n-- > 0)
		*dest++ = 0;
}

/*void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}*/

/*int	main(void)
{
	char	str[15] = "abcdefghijkl";
	printf("%s\n", str);
	ft_bzero(str, 3);
	printf("%s\n", str);
}*/
