/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:21:10 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 18:22:25 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	length;
	char	*result;

	result = (char *)s;
	length = ft_strlen(s);
	i = length + 1;
	if (!s)
		return (NULL);
	while (length >= 0 && i != 0)
	{
		if (result[length] == (char)c)
			return (&result[length]);
		length--;
		i--;
	}
	return (0);
}

/*int	main(void)
{
	char s[] = "bonjour";
	printf("%s\n", ft_strrchr(s, 'b'));
	printf("%s\n", ft_strrchr(s, 'o'));
	printf("%s\n", ft_strrchr("bonjourno", 'o'));
	printf("%s\n", ft_strrchr(s, 'j'));
	printf("%s\n", ft_strrchr(s, 's'));
	printf("%s\n", ft_strrchr(s, '\0'));
	printf("%s\n", ft_strrchr("", '\0'));
	printf("%s\n", ft_strrchr(s + 2, 'b'));
}*/
