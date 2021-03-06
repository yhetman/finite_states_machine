/* ************************************************************************** */
/*                                                                            */
/*                                                        				      */
/*   finite_auto.h                         	              				      */
/*                                                          				  */
/*   By: yhetman <yhetman@student.unit.ua>                    				  */
/*                                                        				      */
/*   Created: 2020/10/19 18:04:00 by yhetman           				          */
/*   Updated: 2020/10/28 10:28:35 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINITE_AUTO_H
# define FINITE_AUTO_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct 			s_state
{
	char				*current_state;
	char				*condition;
	char				*transfer_state;
	struct s_state		*next;
}						t_state;


typedef struct 			s_finite_auto
{
	char				*current_state;
	char				**alphabet;
	int					number_states;
	int					number_finish;
	char				*start_states;
	char				**finish_states;
	char				**w1;
	char				**w2;
	unsigned int 		w1_len;
	unsigned int 		w2_len;
	t_state 			*states;
}						t_finite_auto;


int 					reading_file(int fd);
t_state 				*malloc_states();
t_finite_auto 			*malloc_finite_auto();
int 					init_states(t_finite_auto	*machine, char	*line, int fd);
t_state 				*parse_line_to_state(char *line, char **alphabet);
bool 					is_alphabetic(char *str, char**arr_strs);
bool					is_alphletter(char letter, char **arr_strs);
char 					**split_words(char *word, int len, char**alphabet);
int 					extra_error_exit(char *str);
char 					**check_w2(t_finite_auto *machine);
char 					*check_w1(t_finite_auto *machine);
int 					input_w1_w2(t_finite_auto	*machine);
int						find_connection(t_finite_auto	*machine, char **final_arr);
char					**add_string(char **final_arr, char *current_state);
int						check_w1_w2(t_finite_auto *machine);
int 					free_memory_before_exit(t_finite_auto *machine, int excode);
void					free_states(t_state *states);
#endif
