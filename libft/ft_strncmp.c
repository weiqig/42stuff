/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:22:36 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 18:24:32 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*str1;
	unsigned char	*str2;

	idx = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (idx < n)
	{
		if (str1[idx] != str2[idx] || str1[idx] == '\0')
			return (str1[idx] - str2[idx]);
		idx++;
	}
	return (0);
}
