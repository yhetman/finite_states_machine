/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_w1_w2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/26 02:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"


char *check_w2(t_finite_auto *machine)
{
	printf("%s\n", machine->current_state);
	return("fuck");
}

char *check_w1(t_finite_auto *machine)
{
	t_state *states;
	char	*to_state;

	to_state = NULL;
	states = machine->states;
	while (states && states->next)
	{
		if (ft_strcmp(states->current_state, machine->current_state)
			&& ft_strcmp(states->condition, "a"))
			to_state = states->transfer_state;
		states = states->next;
	}
	return(to_state);
}


int input_w1_w2(t_finite_auto	*machine)
{
	char w1[10];
	char w2[10];

	printf("Enter w1: ");
	scanf("%s", w1);
		ft_strcpy(machine->w1, w1);
	printf("Enter w2: ");
	scanf("%s", w2);
	if(!is_alphabetic(w1, machine->alphabet) || !is_alphabetic(w2, machine->alphabet))
		return(0);
	//machine->w2 = w2;
	return(1);
}
