/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   init.c                                                                   */
/*                                                                            */
/*   By: blukasho <blukasho@ustork.com.ua>                                    */
/*                                                                            */
/*   Created: 2020/10/28 00:51:44 by blukasho                                 */
/*   Updated: 2020/10/28 01:03:47 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#include <finite_auto.h>

t_state 		*parse_line_to_state(char *line)
{
	t_state 	*state;
	char 		**parts;

	state = malloc_states();
	parts = ft_strsplit(line, ' ');
	state->current_state = parts[0];
	state->condition = parts[1];
	state->transfer_state = parts[2];
	return (state);
}

int 			init_states(t_finite_auto *machine, char *line, int fd)
{
	int			i;
	t_state		*new_state;

	i = 0;
	while(i < machine->number_states)
	{
		get_next_line(fd, &line);
		if ((new_state = parse_line_to_state(line)))
		{
			new_state->next = machine->states;
			machine->states = new_state;
		}
		i++;
	}
	return (1);
}
