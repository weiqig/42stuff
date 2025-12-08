/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:15:01 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:39:32 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strcat(char *dest, char *src);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;
	int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (src_len > 0)
	{
		while (i < src_len)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (dest);
}

/*int	main(void)
{
	char	*output;
	char	arrd[10] = "aaa";
	char	source[10] = " bbb";
	printf("current destination: %s\n", arrd);
	printf("current source: %s\n", source);
	output = ft_strcat(arrd, source);
	printf("final destination: %s\n", output);
	printf("destination length: %i\n", ft_strlen(output));
}*/
