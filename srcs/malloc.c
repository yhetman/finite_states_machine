/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   malloc.c                                                                 */
/*                                                                            */
/*   By: blukasho <blukasho@ustork.com.ua>                                    */
/*                                                                            */
/*   Created: 2020/10/28 00:25:50 by blukasho                                 */
/*   Updated: 2020/10/28 01:20:36 by blukasho                                 */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"

t_state				*malloc_states()
{
	t_state			*states;
	
	states = (t_state *)malloc(sizeof(t_state));
	ft_bzero(states, sizeof(t_state));
	return states;
}

t_finite_auto 			*malloc_finite_auto()
{
	t_finite_auto 		*machine;

	machine = (t_finite_auto *)malloc(sizeof(t_finite_auto));
	ft_bzero(machine, sizeof(t_finite_auto));
	return (machine);
}
