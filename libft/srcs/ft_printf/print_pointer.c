/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:01:12 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_pointer(va_list ap)
{
	void		*ptr;
	intptr_t	p;

	ptr = va_arg(ap, void *);
	p = (intptr_t)ptr;
	g_data.specifier = 'p';
	g_data.length = 1;
	g_data.flags[0] = '#';
	print_hex(p);
}
