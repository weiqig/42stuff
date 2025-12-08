/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:26:09 by wgan              #+#    #+#             */
/*   Updated: 2025/10/28 17:27:21 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_isalpha('a'));
	printf("%i\n", ft_isalpha('1'));
	printf("%i\n", ft_isalpha(' '));
	printf("%i\n", ft_isalpha('T'));
}*/
