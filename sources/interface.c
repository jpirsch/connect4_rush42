/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 01:40:37 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int     player_turn(t_env *e)
{
	char	*line;

	ft_putstr("Its your turn, in which column will you play ?\n");
	if (!(get_next_line(0, &line)))
		return (0);
	putcoin(e->board, ft_atoi(line) - 1);
	return (1);
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
		(turn == IA) ? ia_turn(e) : ft_putnbr(player_turn(e));
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
