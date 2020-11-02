/* ************************************************************************** */
/*                                                                            */
/*                                                        				      */
/*   free.c                             	              				      */
/*                                                          				  */
/*   By: yhetman <yhetman@student.unit.ua>                    				  */
/*                                                        				      */
/*   Created: 2020/10/19 18:04:00 by yhetman           				          */
/*   Updated: 2020/10/28 10:28:35 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */


#include "finite_auto.h"


void		free_states(t_state *states)
{
	t_state *tmp;
	while (states->next)
	{
		ft_strdel(&(states->current_state));
		ft_strdel(&(states->condition));
		ft_strdel(&(states->transfer_state));
		tmp = states->next;
		free(states->next);
		states = tmp;
	}
	states = NULL;
}

int 		free_memory_before_exit(t_finite_auto *machine, int excode)
{
	ft_str_del_arr(machine->alphabet);
	ft_str_del_arr(machine->finish_states);
	ft_str_del_arr(machine->w1);
	ft_str_del_arr(machine->w2);
	ft_strdel(&(machine->start_states));
	free_states(machine->states);
	free(machine);
	return (excode);
}