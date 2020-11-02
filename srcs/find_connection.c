/* ************************************************************************** */
/*                                                                            */
/*                                                        				      */
/*   find_connection.c                         	              				      */
/*                                                          				  */
/*   By: yhetman <yhetman@student.unit.ua>                    				  */
/*                                                        				      */
/*   Created: 2020/10/19 18:04:00 by yhetman           				          */
/*   Updated: 2020/10/28 10:28:35 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#include "finite_auto.h"
/*
ublic static boolean IsRoute(Integer auto[][],int v1,int v2,List<Integer> visited){
        if(v1==v2)
            return true;
        List<Integer> list=new ArrayList();
        for(int i=0;i<auto[v1].length;++i)
            if(auto[v1][i]!=null)
                list.add(auto[v1][i]);
        if(list.contains(v2))
            return true;
        visited.add(v1);
        for (Integer v:list)
            if(!visited.contains(v))
        return IsRoute(auto,v,v2,visited);
        return false;
    }

*/
//char   **add_string(char **final_arr, char *current_state)


char    **find_all(char *val1, t_state *states)
{
    t_state *tmp;
    char    **list;

    tmp = states;
    list = (char **)malloc((2)*sizeof(char*));
    while (tmp && tmp->next)
    {
        if (!ft_strcmp(tmp->current_state, val1))
            list = add_string(list, tmp->transfer_state);
        tmp = tmp->next;
    }
    return(list);
}

bool    isContained(char **visited, char *value)
{
    int     i;

    i = -1;
    while (visited && visited[++i] != NULL)
        if(!ft_strcmp(visited[i], value))
            return (true);
    return (false);
}

bool 	isConnected(t_state *states, char *val1, char *val2, char** visited)
{
	char **sequence;
    int i, j;

    i = 0;
	if (!ft_strcmp(val1, val2)) 
		return true;
    sequence = find_all(val1, states);
    while (sequence && sequence[i] != NULL)
    {
        if (!ft_strcmp(sequence[i], val2))
            return (true);
        i++;
    }
    visited = add_string(visited, val1);
    for (j = 0; j < i; j++)
        if (!isContained(visited, sequence[j]))
            isConnected(states, sequence[j], val2, visited);
	return (false);

}

int		find_connection(t_finite_auto	*machine, char **final_arr)
{
	int 	i;
    char    **visited;

    visited = (char **)malloc((2)*sizeof(char*));
	for ( i = machine->number_finish - 1; i >= 0 ; i--)
    {
		if (isConnected(machine->states, machine->current_state, final_arr[i], visited))
        {
            printf("Path is recognized!\n");
            return (1);
        }
    }
	return(0);
}