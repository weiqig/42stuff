/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:21:03 by wgan              #+#    #+#             */
/*   Updated: 2025/10/24 19:35:29 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	if (size > 0 && nmemb > UINT_MAX / size)
		return (0);
	arr = malloc(size * nmemb);
	if (!arr)
	{
		free(arr);
		return (NULL);
	}
	ft_bzero(arr, size * nmemb);
	return (arr);
}

/*int	main(void)
{
	int	numItems = 10;
	//int *myArray = calloc(numItems, sizeof(int));
	int *myArray = ft_calloc(numItems, sizeof(int));
	printf("\nBefore: ");
	for (int i = 0; i < numItems; i++) {
		printf("%d ", myArray[i]);
  	}
  	for(int i = 0; i < numItems; i++) {
		myArray[i] = i + 1;
	}
	printf("\nAfter: ");
	for (int i = 0; i < numItems; i++) {
		printf("%d ", myArray[i]);
	}
  	free(myArray);
  	return (0);
}*/
