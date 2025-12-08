/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:21:33 by wgan              #+#    #+#             */
/*   Updated: 2025/10/24 17:47:47 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	int		length;
	char	*arr;
	char	result;

	idx = 0;
	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * length + 1);
	if (!arr)
		return (NULL);
	while (idx < length)
	{
		result = (f)(idx, s[idx]);
		arr[idx] = result;
		idx++;
	}
	arr[idx] = '\0';
	return (arr);
}

/*int	main(int argc, char **argv)
{
	char(*fptr)(unsigned int, char) = ft_translate;
	if (argc == 2)
		printf("%s\n", ft_strmapi(argv[1], fptr));
		free();
	else
		return(0);
	return (0);
}*/
