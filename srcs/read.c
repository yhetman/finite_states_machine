/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   read.c                                                                   */
/*                                                                            */
/*   By: blukasho <blukasho@ustork.com.ua>                                    */
/*                                                                            */
/*   Created: 2020/10/28 00:28:11 by blukasho                                 */
/*   Updated: 2020/10/28 01:03:11 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"

int 				reading_file(int fd)
{
	t_finite_auto	*machine;
	char			*line;
	int				i;

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
		machine->finish_states = ft_strsplit(line, ' ');
	init_states(machine, line, fd);
	input_w1_w2(machine);
	printf("%s\n%s\n%s\n%d\n", 
			machine->alphabet[0], machine->start_states, machine->finish_states[0],machine->number_states);
	printf("%s\n", machine->w1);
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
