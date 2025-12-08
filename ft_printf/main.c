/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:14:34 by wgan              #+#    #+#             */
/*   Updated: 2025/11/10 14:14:35 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("%%%");
	printf("%%%");
}

/*int	main(void)
{
	//printf("\nchar: %c %c\n", 'A', 'f');
	//ft_printf("char: %c %c", 'A', 'f');
	//printf("\n %c %c %c hm\n", '0', 0, '1');
	//ft_printf(" %c %c %c hm", '0', 0, '1');
	//printf("\ne %c\n", '0' - 256);
	//ft_printf("a %c", '0' - 256);
	//printf("\ne %c\n", '0' + 256);
	//ft_printf("a %c", '0' + 256);
	//printf("\n NULL %s NULL \n", NULL);
	//ft_printf(" NULL %s NULL ", NULL);
	//printf("\n %c %c %c\n", '2', '1', 0);
	//ft_printf(" %c %c %c ", '2', '1', 0);
	//printf("\n %c %c %c\n", 0, '1', '2');
	//ft_printf(" %c %c %c ", 0, '1', '2');
	printf("\n %p \n", (void *)-1);
	ft_printf(" %p ", (void *)-1);
	printf("\n %p \n", (void *)1);
	ft_printf(" %p ", (void *)1);
	printf("\n %p \n", (void *)15);
	ft_printf(" %p ", (void *)15);
	printf("\n %p \n", (void *)16);
	ft_printf(" %p ", (void *)16);
	printf("\n");
	//printf("\ndec: %d vs int- %i\n", 42000, 42000);
	//ft_printf("dec: %d vs int- %i", 42000, 42000);

	//printf("\nit is %s\n", "what it is");
	//ft_printf("it is %s", "what it is");

	//char    *ptr = "hi";
	//printf("\np_va.l:%p\n", ptr);
	//ft_printf("p_va.l:%p", ptr);

	//printf("\npos:%u, neg:%u\n", 42, -42);
	//ft_printf("pos:%u, neg:%u", 42, -42);

	//printf("\nthis is a percent: %% test\n");
	//ft_printf("this is a percent: %% test");

	//printf("\nlower:%x, upper:%X\n", 42, 42);
	//ft_printf("lower:%x, upper:%X", 42, 42);
}*/
