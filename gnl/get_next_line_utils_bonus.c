/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*             	                                      +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:43:17 by wgan              #+#    #+#             */
/*   Updated: 2025/11/04 20:43:18 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(const char *s)
{
	int		idx;
	char	*ptr;

	idx = 0;
	ptr = 0;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[idx])
	{
		ptr[idx] = s[idx];
		idx++;
	}
	ptr[idx] = 0;
	return (ptr);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	size_t		dlen;
	char		*str;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	idx;
	unsigned int	length;
	char			*sptr;

	idx = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	sptr = malloc(length);
	if (!sptr)
		return (NULL);
	while (*s1)
		sptr[idx++] = *s1++;
	while (*s2)
		sptr[idx++] = *s2++;
	sptr[idx] = 0;
	return (sptr);
}
