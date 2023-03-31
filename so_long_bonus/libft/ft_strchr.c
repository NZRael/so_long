/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:51:13 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/12 23:43:23 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;
	int				i;
	int				ok;

	i = 0;
	a = (unsigned char)c;
	ok = -1;
	if (!a)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == a)
		{
			ok = i;
			break ;
		}
		i++;
	}
	if (ok == -1)
		return (0);
	return ((char *)&s[ok]);
}
