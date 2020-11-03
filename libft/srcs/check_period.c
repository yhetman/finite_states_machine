/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_period.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:35:45 by yhetman           #+#    #+#              */
/*   Updated: 2019/03/25 13:37:36 by yhetman          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					check_period(t_neg_exp_of_digit *neg)
{
	int				i;
	int				r;

	r = 0;
	i = neg->div_len;
	while (i >= 0 && neg->div[--i] == 0)
		;
	if (i >= 0)
	{
		while (i >= 0)
		{
			r *= 10;
			r += neg->div[i--];
		}
		i = 0;
		while (i < neg->per_len && neg->per[i] > 0)
			if (neg->per[i++] == r)
				return (1);
		neg->per[i] = r;
	}
	return (0);
}
