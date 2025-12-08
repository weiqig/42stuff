/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:41:26 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 17:44:13 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(int argc, char *argv[])
{
	if (argc != 2)
		printf("kekw\n");
	else
	{
		printf("Input: %s\n", argv[1]);
		printf("Duplicate: %s\n", ft_strdup(argv[1]));
	}
	return 0;
}*/
