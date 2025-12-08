/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:20:30 by wgan              #+#    #+#             */
/*   Updated: 2025/09/25 00:57:55 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && (s1[idx] != '\0' || s2[idx] != '\0'))
	{
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

/*int	main(void)
{
	int	ans;
	printf("my output: %i\n", ft_strcmp("ABC", "ABC"));
	ans = strcmp("ABC", "ABC");
	printf("proper answer: %i\n", ans);
	printf("my output: %i\n", ft_strcmp("ABCDEFGHIJKLMNOP", "ABz"));
        ans = strcmp("ABCDEFGHIJKLMNOP", "ABz");
        printf("proper answer: %i\n", ans);
	printf("my output: %i\n", ft_strcmp("ABC", "ABf2ig4y3rbdnefrib"));
	ans = strcmp("ABC", "ABf2ig4y3rbdnefrib");
	printf("proper answer: %i\n", ans);
	printf("my output: %i\n", ft_strcmp("   ", "ABZ"));
	ans = strcmp("   ", "ABZ");
	printf("proper answer: %i\n", ans);
	printf("my output: %i\n", ft_strcmp("ABJOJO", "ABC"));
	ans = strcmp("ABJOJO", "ABC");
	printf("proper answer: %i\n", ans);
	printf("my output: %i\n", ft_strcmp("$'\201'", "A   "));
	ans = strcmp("$'\201'", "A   ");
	printf("proper answer: %i\n", ans);
}*/
