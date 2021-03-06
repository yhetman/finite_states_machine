/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memspy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:55:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/12 14:36:57 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sr;
	char	*ds;

	sr = (char *)src;
	ds = (char *)dst;
	i = -1;
	while (++i < n)
		ds[i] = sr[i];
	return (dst);
}
