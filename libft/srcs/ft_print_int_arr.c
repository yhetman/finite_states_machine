/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:28:15 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/22 18:40:11 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_int_arr(int *a, int a_len)
{
	int	i;

	i = 0;
	while (i < a_len)
		ft_putnbr(a[i++]);
}
