/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:44:07 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/12 14:37:00 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = -1;
	if (s && f)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
			while (s[++i])
				res[i] = f(i, s[i]);
		return (res);
	}
	return (NULL);
}
