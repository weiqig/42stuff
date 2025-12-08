/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:11:25 by wgan              #+#    #+#             */
/*   Updated: 2025/10/14 12:11:27 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strdup(char *src)
{
	int		idx;
	char	*str;

	idx = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(src));
	if (str == NULL)
		return (0);
	while (src[idx] != '\0')
	{
		str[idx] = src[idx];
		idx++;
	}
	return (str);
}

/*int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	else
	{
		printf("%s\n", ft_strdup(argv[1]));
	}
}*/
