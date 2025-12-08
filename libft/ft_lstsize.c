/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:57:21 by wgan              #+#    #+#             */
/*   Updated: 2025/10/29 16:01:58 by wgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		length;

	if (!lst)
		return (0);
	list = lst;
	length = 0;
	while (list)
	{
		list = list->next;
		length++;
	}
	return (length);
}
