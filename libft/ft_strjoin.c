/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:57:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/11 18:18:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	res = NULL;
	i = -1;
	if (s1 && s2)
	{
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (res)
		{
			while (*s1)
			{
				res[++i] = *s1;
				s1++;
			}
			while (*s2)
			{
				res[++i] = *s2;
				s2++;
			}
		}
	}
	return (res);
}
