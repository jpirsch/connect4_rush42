/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 00:31:35 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	player_turn(t_env *e)
{
	char	buf[1];
	int	ret;

	ft_putstr("Its your turn, in which column will you play ?\n");
	ret = read(0, buf, 1);
	if (ret != 1)
		return ;
	buf[ret] = 0;
	putcoin(e->board, ft_atoi(buf));
}

void	ia_turn(t_env *e)
{
	int	move;

	ft_putstr("IA plays :\n");
	move = minmax(e);
	putcoin(e->board, move);
}

int	launch_interface(t_env *e)
{
	int	score;
	int	turn;

	turn = IA;
	while (!(score = partie_finie(e->board)))
	{
		display(e->board);
		(turn == IA) ? ia_turn(e) : player_turn(e);
		turn = (turn == IA) ? PLAYER : IA;
	}
	display(e->board);
	if (score == IA)
		ft_putstr("The IA wins the game !");
	else if (score == PLAYER)
		ft_putstr("The player wins the game !");
	else
		ft_putstr("It's a draw...");
	return (1);
}
