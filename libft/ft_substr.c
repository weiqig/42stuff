/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:32:13 by wgan              #+#    #+#             */
/*   Updated: 2025/10/22 19:32:15 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	dlen;
	char	*str;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	dlen = length - start;
	if (dlen > len)
		dlen = len;
	str = (char *)malloc(dlen + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, dlen + 1);
	return (str);
}

/*int	main(void)
{
	char	str[100] = "hello world i am very long";
	char	*output = ft_substr(str, 0, 200);
	printf("%s\n", output);
	free(output);
}*/
