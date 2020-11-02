/* ************************************************************************** */
/*                                                                            */
/*                                                        				      */
/*   check_w1_w2.c                         	              				      */
/*                                                          				  */
/*   By: yhetman <yhetman@student.unit.ua>                    				  */
/*                                                        				      */
/*   Created: 2020/10/19 18:04:00 by yhetman           				          */
/*   Updated: 2020/10/28 10:28:35 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"


char	**add_string(char **final_arr, char *current_state)
{
	int 	i;
	char	**new_arr;
	char	*new_str;

	i = 0;
	while(final_arr[i] != NULL)
		i++;

	new_arr = (char**)realloc(final_arr, (i + 2) * sizeof (char*));
	if (!new_arr)
		return (final_arr);
	if (!(new_str = ft_strdup(current_state)))
		return(new_arr);
	new_arr[i++] = new_str;
	new_arr[i] = NULL;
	return (new_arr);


}

char	*check_states(t_state *states, char *letter, char *current_state)
{
	char	*new_state;

	new_state = NULL;
	while (states && states->next)
	{
		if (!(ft_strcmp(states->transfer_state, current_state))
			&& !(ft_strcmp(states->condition, letter)))
		{
			printf("%s\n", current_state);
			new_state = states->current_state;
			break; 
		}
		states = states->next;
	}
	return (new_state);

}

char **check_w2(t_finite_auto *machine)
{

	t_state *states;
	char	**finishes, **final_arr;
	char	*current_state, *new_state;
	int 	j, i;

	new_state = NULL;
	i = 0;
	final_arr = (char **)malloc((machine->number_finish + 1)*sizeof(char*));
	finishes = machine->finish_states;
	while(finishes[i] != NULL)
	{
		current_state = finishes[i];
		for (j = machine->w2_len - 1; j >= 0; --j)
		{
			states = machine->states;

			if (!(new_state = check_states(states, machine->w2[j], current_state)))
				break ;
			else
				current_state = new_state;
		}
		if (new_state)
			final_arr = add_string(final_arr, current_state);
		i++;
	}
	return(final_arr);
}

char	*check_w1(t_finite_auto *machine)
{
	t_state 		*states;
	char			*to_state;
	unsigned int 	i;

	to_state = machine->current_state;
	for (i = 0; i < machine->w1_len; i++)
	{
		states = machine->states;
		while (states && states->next)
		{
			if (!(ft_strcmp(states->current_state, to_state))
				&& !(ft_strcmp(states->condition, machine->w1[i])))
			{
				printf("%s - %s\n", machine->w1[i], to_state);
				to_state = states->transfer_state;
				break;
			}
			states = states->next;
		}
	}
	return(to_state);
}


int		check_w1_w2(t_finite_auto *machine)
{
	char **fin;

	if (!(machine->current_state = check_w1(machine)))
		return(extra_error_exit("Can't recognize any path for w1"));
	printf("%s\n", machine->current_state);
	fin = check_w2(machine);
	if (*fin == NULL)
		return(extra_error_exit("Can't recognize any path for w2"));
	printf("final for w2 : %s\n", fin[0]);
	if(!find_connection(machine, fin))
		return(extra_error_exit("Can't recognize any path"));
	return (1);
}