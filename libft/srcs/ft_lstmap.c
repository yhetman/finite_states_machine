/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:45:10 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/12 14:36:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (f && lst)
	{
		tmp = f(lst);
		res = tmp;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = f(lst);
			if (tmp->next)
			{
				tmp = tmp->next;
			}
		}
		return (res);
	}
	return (NULL);
}
