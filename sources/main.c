/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/08 13:34:24 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_env	*init_env()
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		return (NULL);
	e->board = init_board();
	return (e);
}

int	free_env(t_env *e)
{
	if (!(free_board(e->board)))
		return (0);
	if (!(free_ia(e->ia)))
		return (0);
	return (1);
}

int main(void)//int ac, char **av)
{
	t_env	*e;

	if (!(e = init_env()))
		return (-1);
	launch_interface(e);
	return (0);
}
