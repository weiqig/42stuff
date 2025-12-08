/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:40:54 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:06:08 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src);

int	get_array_size(char *src)
{
	int	length;

	length = 0;
	while (src[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = get_array_size(src);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	if (i == len)
	{
		dest[len] = '\0';
	}
	return (dest);
}

/*int	main(void)
{
	char	destination[5];
	char	*output;
	char	arr2[5] = "hello";
	printf("current destination: %s\n", destination);
	output = ft_strcpy(destination, arr2);
	printf("final destination: %s\n", output);
}*/
