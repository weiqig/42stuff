/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:37:12 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 17:37:46 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	j;
	size_t	length;

	idx = 0;
	length = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (length > len)
		return (NULL);
	while (big[idx] != '\0' && idx < len)
	{
		j = 0;
		while (big[idx + j] == little[j] && idx + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[idx]);
		idx++;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	char str[30] = "lorem ipsum dolor sit amet";
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("%s\n", strnstr(haystack, needle, -1));
	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	printf("%s\n", strnstr(haystack, "abcd", 9));
	if (argc == 3)
		printf("%s\n", ft_strnstr(str, argv[1], atoi(argv[2])));
	else
		return (0);
}*/
