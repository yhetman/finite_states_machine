/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/28 00:28:36 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"
#include "libft/includes/libft.h"
#include <fcntl.h>
#include <stdbool.h>

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
	machine->states = malloc_states();
	return (machine);
}

bool is_alphabetic(char *str, char**arr_strs)
{
	while(arr_strs != NULL)
	{
		if (ft_strcmp(*arr_strs, str))
			return (true);
		*arr_strs++;
	}
	return (false);
}

t_state *parse_line_to_state(char *line, char **alphabet)
{
	t_state *state;
	char **parts;

	state = malloc_states();
	parts = ft_strsplit(line, ' ');
	state->current_state = parts[0];
	if(is_alphabetic(parts[1], alphabet))
		state->condition = parts[1];
	state->transfer_state = parts[2];
	return (state);
}


int 	init_states(t_finite_auto	*machine, char		*line, int fd)
{
	int			i;
	t_state	*new_state;

	i = 0;
	while(i < machine->number_states && (get_next_line(fd, &line)))
	{
		if (new_state = parse_line_to_state(line, machine->alphabet))
		{
			new_state->next = machine->states;
			machine->states = new_state;
			printf("%s %s %s\n", machine->states->current_state, machine->states->condition, machine->states->transfer_state);
		}
		i++;
	}
	return (1);
}

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

char *check_w2(t_finite_auto *machine)
{

}

char *check_w1(t_finite_auto *machine)
{
	t_state *states;
	char	*to_state;

	to_state = NULL;
	states = machine->states;
	while (states && states->next)
	{
		if (strcmp(states->current_state, machine->current_state)
			&& strcmp(states->condition, "a"))
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
		ft_strcpy(machine->w1, w1);
	printf("Enter w2: ");
	scanf("%s", w2);
	if(!is_alphabetic(w1, machine->alphabet) || !is_alphabetic(w2, machine->alphabet))
		return(0);
	//machine->w2 = w2;
	return(1);
}

int 		reading_file(int fd)
{
	t_finite_auto	*machine;
	char		*line;
	char		**fin;
	int          i;

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
