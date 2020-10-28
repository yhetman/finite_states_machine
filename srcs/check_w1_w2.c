/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_w1_w2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/26 02:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"


/*

        //reverse auto
        Integer[][] reverseAuto = new Integer[stateCount][alphabet.size()];
        for (Integer[] ints : reverseAuto) {
            for (Integer i : ints)
                i = null;
        }
        for (int i = 0; i < stateCount; ++i)
            for (int j = 0; j < alphabet.size(); ++j) {
                if (auto[i][j] != null)
                    reverseAuto[auto[i][j]][j] = i;
            }

        //check w2
        List<Integer> finalW2 = new ArrayList<>();
        for (int f : F) {
            Integer currentState2 = f;
            for (int j = w2.length - 1; j >= 0; --j) {
                currentState2 = reverseAuto[currentState2][alphabet.indexOf(w2[j])];
                if (currentState2 == null)
                    break;
            }
            if (currentState2 != null) {
                finalW2.add(currentState2);
            }
        }
        return finalW2;
   */

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

char **check_w2(t_finite_auto *machine)
{

	t_state *states;
	char	**finishes, **final_arr;
	char	*current_state;
	int 	j;

	finishes = machine->finish_states;
	states = machine->states;
	while(finishes && *finishes != NULL)
	{
		current_state = *finishes;
		for (j = ft_strlen(machine->w2); j >= 0; --j)
		{
			while (states && states->next)
			{
				if (ft_strcmp(states->transfer_state, current_state)
					&& ft_strcmp(states->condition, machine->w2))
					current_state = states->current_state;
				states = states->next;
			}
			if (!current_state)
				break;
		}
		if (current_state)
			{printf("%s\n", current_state);
						final_arr = add_string(final_arr, current_state);}
		finishes++;
	}
	return(final_arr);
}

char *check_w1(t_finite_auto *machine)
{
	t_state *states;
	char	*to_state;

	to_state = NULL;
	states = machine->states;
	while (states && states->next)
	{
		if (ft_strcmp(states->current_state, machine->current_state)
			&& ft_strcmp(states->condition, machine->w1))
			to_state = states->transfer_state;
		states = states->next;
	}
	return(to_state);
}


int input_w1_w2(t_finite_auto	*machine)
{
	char w1[10];
	char w2[10];

	printf("Enter w1: ");
	scanf("%s", w1);
	printf("Enter w2: ");
	scanf("%s", w2);
	if(!is_alphabetic(w1, machine->alphabet) || !is_alphabetic(w2, machine->alphabet))
		return(0);
	machine->w1 = ft_strdup(w1);
	machine->w2 = ft_strdup(w2);
	return(1);
}
