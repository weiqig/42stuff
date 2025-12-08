/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:44:35 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 17:48:02 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char	*output;

	output = ft_strjoin("it is", " not what it is");
	printf("%s\n", output);
	free(output);
}*/
