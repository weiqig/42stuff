/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:19:51 by wgan              #+#    #+#             */
/*   Updated: 2025/10/23 17:19:55 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	idx;
	int	is_word;
	int	count;

	idx = 0;
	is_word = 0;
	count = 1;
	while (str[idx])
	{
		if (str[idx] != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (str[idx] == c)
			is_word = 0;
		str++;
	}
	return (count);
}

static size_t	ft_word_length(char const *s, size_t start, char c)
{
	int	idx;

	idx = 0;
	while (s[start] != c && s[start] != '\0')
	{
		idx++;
		start++;
	}
	return (idx);
}

static char	*ft_ins_arr(char const *s, size_t curr_idx, char c)
{
	size_t	word_length;
	char	*temp;

	word_length = ft_word_length(s, curr_idx, c);
	temp = ft_substr(s, curr_idx, word_length);
	if (!temp)
		return (NULL);
	return (temp);
}

static void	*ft_free(char **stuff, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(stuff[i++]);
	free(stuff);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	size_t		j;
	int			word_count;
	char		**result;

	i = 0;
	j = 0;
	word_count = ft_count_words(s, c);
	result = ft_calloc((word_count), sizeof(char *));
	if (!result)
		return (NULL);
	while (i < word_count - 1)
	{
		if (s[j] != c)
		{
			result[i] = ft_ins_arr(s, j, c);
			if (!result[i])
				return (ft_free(result, i + 1));
			i++;
			j += ft_word_length(s, j, c);
		}
		else
			j++;
	}
	return (result);
}

/*int	main(int argc, char **argv)
{
	char	*str;
	int		words;
	char	c;
	char	**arr;

	if (argc == 2 && ft_strlen(argv[1]) == 1)
	{
		c = *argv[1];
		str = "helo world asdfghjkl;";
		words = ft_count_words(str, c);
		arr = ft_split(str, c);
		printf("ft_split() finished successfully\n");
		for (int i = 0; i < words; i++)
			printf("%s\n", arr[i]);
		for (int i = 0; i < words; i++)
		{
			free(arr[i]);
		}
		free(arr);
	}
	else
		return (0);
}*/
