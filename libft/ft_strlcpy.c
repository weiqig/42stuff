/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:46 by wgan              #+#    #+#             */
/*   Updated: 2025/10/29 13:35:17 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[idx] && idx < size - 1)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	char dest[20] = "rrrrrr";
	//char src[10] = "print me";
	//printf("%zu\n", ft_strlcpy(dst, src, 4));
		ft_strlcpy(dest, "lorem", 15);
		ft_strlcpy(dest, "", 15);
		ft_strlcpy(dest, "lorem ipsum", 3);
		ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15);
		ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
}*/
