/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/29 11:10:27 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					main_function(const char **format, va_list ap)
{
	parse_format_specifiers(format);
	if (check_errors() == -1)
		return (-1);
	result_preparation(ap);
	return (0);
}
