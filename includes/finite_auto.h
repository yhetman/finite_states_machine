/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finite_auto.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/28 00:31:01 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINITE_AUTO_H
# define FINITE_AUTO_H

# include <fcntl.h>
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
	char				*start_states;
	char				**finish_states;
	char				*w1;
	char				*w2;
	t_state 			*states;
}						t_finite_auto;


int 					reading_file(int fd);
static t_state 			*malloc_states();
static t_finite_auto 	*malloc_finite_auto()

#endif
