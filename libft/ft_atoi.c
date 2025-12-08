/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:37:58 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 17:41:12 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	idx;
	int	sign;
	int	result;

	idx = 0;
	sign = 1;
	result = 0;
	while ((nptr[idx] >= 9 && nptr[idx] <= 13) || nptr[idx] == 32)
		idx++;
	if (nptr[idx] == '-' || nptr[idx] == '+')
	{
		if (nptr[idx] == '-')
			sign = -sign;
		idx++;
	}
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
		result = result * 10 + nptr[idx++] - '0';
	if (result != 0)
		return (result * sign);
	return (0);
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ft_atoi(argv[1]));
	return (0);
}*/
