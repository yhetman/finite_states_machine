/* ************************************************************************** */
/*                                                                            */
/*                                                        				      */
/*   read.c                             	              				      */
/*                                                          				  */
/*   By: yhetman <yhetman@student.unit.ua>                    				  */
/*                                                        				      */
/*   Created: 2020/10/19 18:04:00 by yhetman           				          */
/*   Updated: 2020/10/28 10:28:35 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"

int 		reading_file(int fd)
{
	t_finite_auto	*machine;
	char			*line;
	char			**fin;
	int          	i;

	if (i){}

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
	{
		fin = ft_strsplit(line, ' ');
		machine->number_finish = ft_atoi(fin[0]);
		fin = &fin[1];
		machine->finish_states = fin;
		printf("%d %s\n", machine->number_finish, machine->finish_states[0]);
	}
	init_states(machine, line, fd);
	if (!input_w1_w2(machine))
		return (0);
	if (!check_w1_w2(machine))
		return (0);
	return (1);
}
