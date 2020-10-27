/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
