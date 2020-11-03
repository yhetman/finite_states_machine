/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_del_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:37:42 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/11 14:42:32 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_del_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*arr)
		ft_strdel(&(*(arr++)));
	free(tmp);
	return (0);
}
