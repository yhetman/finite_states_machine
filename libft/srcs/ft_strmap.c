/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:17:45 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/12 14:37:00 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	const char	*res;
	char		*str;

	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			res = str;
			while (*s)
			{
				*str = f(*s);
				s++;
				str++;
			}
			return ((char *)res);
		}
	}
	return (NULL);
}
