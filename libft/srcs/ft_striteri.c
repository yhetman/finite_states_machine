/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:35:49 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/12 14:36:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (s && f)
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
}
