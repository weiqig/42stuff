/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:25:37 by wgan              #+#    #+#             */
/*   Updated: 2025/10/29 14:26:17 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	length;
	size_t	set_len;
	char	*result;

	idx = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	length = ft_strlen(s1) - 1;
	set_len = ft_strlen(set);
	while (s1[idx] && ft_memchr(set, s1[idx], set_len))
		idx++;
	while (length >= idx && ft_memchr(set, s1[length], ft_strlen(set)))
		length--;
	if (idx > length)
		length = 0;
	else
		length = length - idx + 1;
	result = malloc(length + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + idx, length + 1);
	return (result);
}

/*int	main(void)
{
	//char *result;
	char const *s1 = "HELLO";

	//result = ft_strtrim("_ohio_", "_o");
	//result = ft_strtrim("quote thy wart", "quartz");
	//result = ft_strtrim("abbababbabchrisabbbabab", "ab");
	//result = ft_strtrim("print this whole string", "");
	//result = ft_strtrim("", "no output");
	//result = ft_strtrim("            ", "\n \t");
	//printf("output:%s\n", result);
	//free(result);
	free(ft_strtrim(s1, "abc"));
	free(ft_strtrim(NULL, "abc"));
	free(ft_strtrim(s1, ""));
	free(ft_strtrim("", ""));
	free(ft_strtrim("", "abc"));
	free(ft_strtrim(s1, NULL));
}*/
