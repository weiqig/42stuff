/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:22:44 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:08:06 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

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

int	ft_str_is_uppercase(char *str)
{
	int	idx;
	int	output;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			output = 1;
		}
		else
		{
			output = 0;
			break ;
		}
		idx++;
	}
	if (ft_strlen(str) == 0)
	{
		output = 1;
	}
	return (output);
}

/*int	main(void)
{
	char *string = "abc";
	printf("%d", ft_str_is_uppercase(string));
}*/
