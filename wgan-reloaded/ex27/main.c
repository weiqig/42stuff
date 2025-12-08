/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:18:23 by wgan              #+#    #+#             */
/*   Updated: 2025/10/15 15:18:25 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_print_err(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_display_file(char *file)
{
	int	fd;
	int	buf[10000];
	int	isread;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_print_err("Cannot read file.\n");
	isread = read(fd, buf, 1);
	if (isread == -1)
	{
		close(fd);
		return ;
	}
	while (isread > 0)
	{
		write(1, buf, 1);
		isread = read(fd, buf, 1);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_print_err("File name missing.\n");
	else if (argc > 2)
		ft_print_err("Too many arguments.\n");
	else if (argc == 2)
		ft_display_file(argv[1]);
	return (0);
}
