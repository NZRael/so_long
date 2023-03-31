/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:26 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/21 10:57:36 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
