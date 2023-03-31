/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:19:45 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/17 18:25:02 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if ((count >= 922337200000000000)
		|| (size >= 922337200000000000))
		return (0);
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
