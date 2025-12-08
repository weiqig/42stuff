/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:14:49 by wgan              #+#    #+#             */
/*   Updated: 2025/09/12 12:17:38 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *ptr)
{
	*ptr = 42;
}

/*int     main(void)
{
        int     nbr;
        int     *pN;

        nbr = 1;
        pN = &nbr;

        printf("Value: %d\n", nbr);
        printf("Address: %p\n", &nbr);
        ft_ft(pN);
        printf("New value: %d\n", nbr);
        return (0);
}*/
