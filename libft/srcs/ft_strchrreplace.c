/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrreplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:07:57 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/23 12:23:44 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strchrreplace(char *str, char a, char b)
{
	int	i;

	i = 0;
	while (*str)
		if (*str == a && (i = 1))
			*(str++) = b;
		else
			++str;
	return ((i ? 1 : 0));
}
