/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:56:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/12 14:36:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t			ft_strlen_chr(const char *s, const char c)
{
	const char	*tmp;

	tmp = s;
	if (s)
		while (*s && *s != c)
			++s;
	return (s - tmp);
}
