/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:19:55 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 18:20:51 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		idx;
	char		*str;

	idx = 0;
	str = (char *)s;
	while (*s && idx < ft_strlen(s) + 1)
	{
		if (str[idx] == (char)c)
			return (&str[idx]);
		idx++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*int	main(void)
{
	char str[10] = "";
	printf("expected: %s\n", strchr(str, '\0'));
	printf("%s\n", ft_strchr(str, '\0'));
}*/
