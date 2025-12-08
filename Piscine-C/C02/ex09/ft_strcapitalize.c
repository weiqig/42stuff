/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:47:46 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:08:55 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	is_alphanum(char *str, int idx)
{
	int	output;

	output = 0;
	if (str[idx] >= 'a' && str[idx] <= 'z')
		output = 1;
	if (str[idx] >= 'A' && str[idx] <= 'Z')
		output = 2;
	if (str[idx] >= '0' && str[idx] <= '9')
		output = 3;
	return (output);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (is_alphanum(str, 0) == 1)
			str[idx] -= 32;
		else
		{
			if (is_alphanum(str, idx - 1) == 0 && is_alphanum(str, idx) == 1)
				str[idx] -= 32;
			if (is_alphanum(str, idx) == 2 && is_alphanum(str, idx - 1) != 0)
				str[idx] += 32;
		}
		idx++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	//char string[] = "test 1one";
	char	string[] = "hi, how are you? 42words forty-two; fifty+and+one";
	char	string1[] = "itIsWhAtItiS";
	char	string2[] = "x * y * z = *xYZ*";
	char	string3[] = "1ONE2two3ThRee4FoUr5fivE";
	printf("Before: %s\n", string);
	printf("After : %s\n", ft_strcapitalize(string));
	printf("Before: %s\n", string1);
        printf("After : %s\n", ft_strcapitalize(string1));
	printf("Before: %s\n", string2);
        printf("After : %s\n", ft_strcapitalize(string2));
	printf("Before: %s\n", string3);
        printf("After : %s\n", ft_strcapitalize(string3));
}*/
