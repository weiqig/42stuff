/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:50:28 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:39:35 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

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

int	ft_getpos(char *string, char *target)
{
	int	idx;
	int	count;
	int	pos;

	idx = 0;
	count = 0;
	pos = 0;
	while (count != ft_strlen(target) && string[idx] != '\0')
	{
		if (string[idx] == target[count])
			count++;
		else
			count = 0;
		idx++;
	}
	if (count != ft_strlen(target))
		pos = -1;
	else
		pos = idx - count;
	return (pos);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		idx;
	int		pos;

	idx = 0;
	pos = ft_getpos(str, to_find);
	if (pos >= 0)
		return (&str[pos]);
	else
		return (0);
}

/*int	main(void)
{
	char	*haystack;
	char	*needle;

	haystack = "abcdefghijklmnopqrstuvwxyz";
	needle = "abc";
	printf("%s\n", haystack);
	printf("Expected output: %s\n", strstr(haystack, needle));
	printf("My output: %s\n", ft_strstr(haystack, needle));
	needle = "mnop";
        printf("Expected output: %s\n", strstr(haystack, needle));
	printf("My output: %s\n", ft_strstr(haystack, needle));
	needle = "";
        printf("Expected output: %s\n", strstr(haystack, needle));
	printf("My output: %s\n", ft_strstr(haystack, needle));
	needle = "124562t42tf";
        printf("Expected output: %s\n", strstr(haystack, needle));
        printf("My output: %s\n", ft_strstr(haystack, needle));
}*/
