/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:32:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/15 15:33:28 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

__int128		ft_len_of_digit(__int128 d)
{
	__int128	l;

	l = 0;
	while (d > 0 && ++l)
		d /= 10;
	return (l);
}
