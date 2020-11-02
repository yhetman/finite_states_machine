/* ************************************************************************** */
/*                                                                            */
/*                                                        				      */
/*   input_w1_w2.c                         	              				      */
/*                                                          				  */
/*   By: yhetman <yhetman@student.unit.ua>                    				  */
/*                                                        				      */
/*   Created: 2020/10/19 18:04:00 by yhetman           				          */
/*   Updated: 2020/10/28 10:28:35 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"


bool is_alphletter(char letter, char **arr_strs)
{

	printf("%c %s\n", letter, &letter);
	while(arr_strs && *arr_strs != NULL)
	{
		if (!ft_strcmp(*arr_strs, &letter))
			return (true);
		arr_strs++;
	}
	return (false);
}

char **split_words(char *word, int len, char**alphabet)
{
	int i;
	char **letters;

	i = 0;
	if (!word)
		return (NULL);
	letters = (char **)malloc((len + 1) * sizeof(char *));
	while(word[0] != '\0')
	{
		if (!(is_alphletter(word[0], alphabet)))
				return NULL;
		letters[i] = ft_strndup(word, 1);
		i++;
		word++;
	}
	letters[i] = NULL;
	return(letters);
}


int 	input_w1_w2(t_finite_auto	*machine)
{
	char w1[10];
	char w2[10];

	printf("Enter w1: ");
	scanf("%s", w1);
	printf("Enter w2: ");
	scanf("%s", w2);
	machine->w1_len = ft_strlen(w1);
	machine->w2_len = ft_strlen(w2);
	if (!(machine->w1 = split_words(w1, machine->w1_len, machine->alphabet))
		|| !(machine->w2 = split_words(w2, machine->w2_len, machine->alphabet)))
		return(extra_error_exit("Error! Input words from different alphabet!"));
	//printf("%s\n%s\n%s\n%d\n",
	//	machine->alphabet[0], machine->start_states, machine->finish_states[0],machine->number_states);
	return(1);
}
