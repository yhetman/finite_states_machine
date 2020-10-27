/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/26 02:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"
#include "libft/includes/libft.h"
#include <fcntl.h>

static t_state *malloc_states()
{
	t_state	*states;

	states = (t_state *)malloc(sizeof(t_state));
	ft_bzero(states, sizeof(t_state));
	return states;
}

static t_finite_auto 	*malloc_finite_auto()
{
	t_finite_auto *machine;

	machine = (t_finite_auto *)malloc(sizeof(t_finite_auto));
	ft_bzero(machine, sizeof(t_finite_auto));
	return (machine);
}


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


int 		reading_file(int fd)
{
	t_finite_auto	*machine;
	char		*line;
	int			i;

	line = NULL;
	machine = malloc_finite_auto();
	if (get_next_line(fd, &line))
		machine->alphabet = ft_strsplit(line, ' ');
	if (get_next_line(fd, &line))
		machine->number_states = ft_atoi(line);
	if (get_next_line(fd, &line))
		machine->start_states = line;
		machine->current_state = machine->start_states;
	if (get_next_line(fd, &line))
		machine->finish_states = ft_strsplit(line, ' ');
	init_states(machine, line, fd);
	printf("%s\n%s\n%s\n%d\n",
		machine->alphabet[0], machine->start_states, machine->finish_states[0],machine->number_states);
	printf("%s\n", machine->states->next->condition);
	return (1);
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
