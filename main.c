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

#include "finish_auto.h"
#include "libft.h"

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
	machine->states = malloc_states
	return machine;
}

int 		reading_file(int fd)
{
	t_finite_auto	*machine
	char		*line;
	int			i;

	line = NULL;
	machine = malloc_finite_auto()
	if (get_next_line(fd, &line))
		machine->alphabet = ft_strsplit(line, ' ')
	if (get_next_line(fd, &line))
		machine->number_states = ft_atoi(line);
	if (get_next_line(fd, &line))
		machine->start_states = ft_strsplit(line, ' ');
	if (get_next_line(fd, &line))
		machine->finish_states = ft_strsplit(line, ' ');
	while(get_next_line(fd, &line))
		machine->states = init_states(machine);
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
