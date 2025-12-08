/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:08:23 by wgan              #+#    #+#             */
/*   Updated: 2025/11/03 16:11:09 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *p);
int		ft_print_decimal(int n);
int		ft_print_integer(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hexl(unsigned int nbr);
int		ft_print_hexu(unsigned int nbr);
int		ft_print_percent(void);

#endif
