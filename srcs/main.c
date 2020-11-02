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
