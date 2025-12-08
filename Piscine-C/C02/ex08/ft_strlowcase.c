/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:34:46 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:08:21 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			str[idx] += 32;
		}
		idx++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char c[9] = "LoWerCaSe";
	printf("%s\n", c);
	printf("Output: %s\n", ft_strlowcase(c));
}*/
