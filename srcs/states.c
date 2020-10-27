/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/26 02:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"

bool is_alphabetic(char *str, char**arr_strs)
{
	while(arr_strs != NULL)
	{
		if (ft_strcmp(*arr_strs, str))
			return (true);
		*arr_strs++;
	}
	return (false);
}

t_state *parse_line_to_state(char *line, char **alphabet)
{
	t_state *state;
	char **parts;

	state = malloc_states();
	parts = ft_strsplit(line, ' ');
	state->current_state = parts[0];
	if(is_alphabetic(parts[1], alphabet))
		state->condition = parts[1];
	state->transfer_state = parts[2];
	return (state);
}



int 	init_states(t_finite_auto	*machine, char	*line, int fd)
{
	int			i;
	t_state	*new_state;

	i = 0;
	while(i < machine->number_states && (get_next_line(fd, &line)))
	{
		if (new_state = parse_line_to_state(line, machine->alphabet))
		{
			new_state->next = machine->states;
			machine->states = new_state;
			printf("%s %s %s\n", machine->states->current_state, machine->states->condition, machine->states->transfer_state);
		}
		i++;
	}
	return (1);
}
