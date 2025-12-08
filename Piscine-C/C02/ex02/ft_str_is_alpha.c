/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:20:36 by wgan              #+#    #+#             */
/*   Updated: 2025/09/24 13:07:45 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	idx;
	int	output;

	idx = 0;
	output = 1;
	while (str[idx] != '\0')
	{
		if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
		{
			if (!(str[idx] >= 'a' && str[idx] <= 'z'))
			{
				output = 0;
				break ;
			}
		}
		idx++;
	}
	return (output);
}

/*int	main(void)
{
	char	*string;

	printf("1 if only alphabet or empty, else 0\n");
	string = "alphabet";
	printf("%i\n", ft_str_is_alpha(string));
        string = "alPHAbet";
        printf("%i\n", ft_str_is_alpha(string));
        string = "alphab3t";
        printf("%i\n", ft_str_is_alpha(string));
        string = "";
        printf("%i\n", ft_str_is_alpha(string));
}*/
