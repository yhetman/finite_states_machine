/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   read.c                                                                   */
/*                                                                            */
/*   By: blukasho <blukasho@ustork.com.ua>                                    */
/*                                                                            */
/*   Created: 2020/10/28 00:28:11 by blukasho                                 */
/*   Updated: 2020/10/28 00:28:36 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"

int 		reading_file(int fd)
{
	t_finite_auto	*machine;
	char			*line;
	char			**fin;
	int          	i;

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
		for (i = 0; i < machine->number_finish; i++)
			fin[i] = fin[i + 1];
		machine->finish_states = fin;
		printf("%d %s\n", machine->number_finish, machine->finish_states[0]);
	}
	init_states(machine, line, fd);
	//if (!input_w1_w2(machine)): printf("Error! Input words from different alphabet!"); exit();
	if (!(machine->current_state = check_w1(machine)))
	{
		printf("Can recognize any path\n");
		exit(0);
	}
	printf("%s\n%s\n%s\n%d\n",
		machine->alphabet[0], machine->start_states, machine->finish_states[0],machine->number_states);
	return (1);
}
