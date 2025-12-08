/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:39:47 by wgan              #+#    #+#             */
/*   Updated: 2025/10/29 16:40:40 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(long n)
{
	int	length;

	length = 0;
	if (n <= 0)
	{
		n = -n;
		length++;
	}
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_itoa_long(int n)
{
	int		length;
	char	*result;
	long	l;

	length = ft_count_len(n);
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	l = (long)n;
	if (l == 0)
	{
		result[--length] = l + '0';
		return (result);
	}
	if (l < 0)
	{
		l = -l;
		result[0] = '-';
	}
	while (l > 0)
	{
		result[--length] = (l % 10) + '0';
		l /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;

	length = ft_count_len(n);
	result = NULL;
	result = ft_itoa_long(n);
	if (!result)
		return (NULL);
	result[length] = 0;
	return (result);
}

/*int	main(int argc, char **argv)
{
	char	*result;

	result = NULL;
	if (argc == 2)
	{
		result = ft_itoa(atoi(argv[1]));
		if (!result)
		{
			free(result);
			return (0);
		}
		printf("%s\n", result);
		free(result);
	}
	return (0);
}*/
