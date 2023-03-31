/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:15:43 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/13 02:18:06 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;
	int		ok;

	i = 0;
	a = (char)c;
	ok = -1;
	if (!a)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == a)
			ok = i;
		i++;
	}
	if (ok == -1)
		return (0);
	return ((char *)&s[ok]);
}
