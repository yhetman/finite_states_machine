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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
static t_state *malloc_states()
{
	t_state	*states;

	states = (t_state *)malloc(sizeof(t_state));
	ft_bzero(states, sizeof(t_state));
	return states;
}


int 		reading_file(int fd, t_finite_auto	*machine)
{
	char		*line;
	int			i;

	line = NULL;
	if (get_next_line(fd, &line))
		machine->alphabet = ft_strsplit(line, ' ')
	if (get_next_line(fd, &line))
		machine->number_states = ft_atoi(line);
	if (get_next_line(fd, &line))
		machine->start_states = ft_strsplit(line, ' ');
	if (get_next_line(fd, &line))
		machine->finish_states = ft_strsplit(line, ' ');
	machine->states = malloc_states()
	while(get_next_line(fd, &line))
		machine->states = init_states(machine);
}


int			main(int argc, char **argv)
{
	int	fd;
	t_finite_auto	machine;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > -1)
	{
		reading_file(fd, &machine);
		close(fd);
	}
	else
		ft_putendl("usage ./fillit file_name");
	return (1);
}
