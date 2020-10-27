/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finite_auto.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2020/10/26 02:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FINITE_AUTO_H
# define FINITE_AUTO_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct 	s_state
{
	char		*current_state;
	char		*condition;
	bool 		finish;
	bool		start;
	s_state		*transfer_state;
}				t_state;

typedef struct 	s_finite_auto
{
	char		**alphabet;
	int			number_states;
	char		**start_states;
	char		**finish_states;
	char		*w1;
	char		*w2;
	t_state 	*states;
}				t_finite_auto;

#endif FINITE_AUTO_H