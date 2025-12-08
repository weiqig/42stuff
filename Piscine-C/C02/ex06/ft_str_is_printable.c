/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:27:34 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:08:13 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	idx;
	int	output;

	idx = 0;
	output = 1;
	while (str[idx] != '\0')
	{
		if ((str[idx] >= 32) && (str[idx] <= 126))
		{
			output = 1;
			idx++;
		}
		else
		{
			output = 0;
			return (output);
		}
	}
	return (output);
}

/*int	main(void)
{
	char *c = "abc123%^&";
	printf("my output: %i\n",ft_str_is_printable(c));
	char *c1 = "";
        printf("my output: %i\n",ft_str_is_printable(c1));
	char *c2 = "a\nfbbejf";
        printf("my output: %i\n",ft_str_is_printable(c2));
	char *c3 = "       \r";
        printf("my output: %i\n",ft_str_is_printable(c3));
}*/
