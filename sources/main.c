/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 07:06:34 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_env	*init_env(int level)
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		return (NULL);
	e->board = init_board();
	e->ia = init_ia(level);
	return (e);
}

int		free_env(t_env *e)
{
	if (!(free_board(e->board)))
		return (0);
	if (!(free_ia(e->ia)))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		level;

	level = 3;
	if (ac != 2)
		return (0);
	else
		level = ft_atoi(av[1]);
	if (!(e = init_env(level)))
		return (-1);
	launch_interface(e);
	return (0);
}
