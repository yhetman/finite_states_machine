/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/28 00:28:36 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#include <finite_auto.h>


t_state *parse_line_to_state(char *line)
{
	t_state *state;
	char **parts;

	state = malloc_states();
	parts = ft_strsplit(line, ' ');
	state->current_state = parts[0];
	state->condition = parts[1];
	state->transfer_state = parts[2];
	return (state);
}

int 	init_states(t_finite_auto	*machine, char		*line, int fd)
{
	int			i;
	t_state	*new_state;

	i = 0;
	while(i < machine->number_states)
	{
		get_next_line(fd, &line);
		if (new_state = parse_line_to_state(line))
		{
			new_state->next = machine->states;
			machine->states = new_state;
		}
		i++;
	}
	return (1);
}


int input_w1_w2(t_finite_auto	*machine)
{
	char w1[10];
	char w2[10];

	printf("Enter w1: ");
	scanf("%s", w1);
	printf("Enter w2: ");
	scanf("%s", w2);
	ft_strcpy(machine->w1, w1);
	ft_strcpy(machine->w2, w2);
	//machine->w2 = w2;
	return(1);
}


int			main(int argc, char **argv)
{
	int	fd;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > -1)
	{
		reading_file(fd);
		close(fd);
	}
	else
		ft_putendl("usage ");
	return (1);
}
