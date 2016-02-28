/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 07:57:14 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		error(int n, t_env *e)
{
	char	*line;
	int		i;

	while (n < 1 || n > e->board->width)
	{
		i = 0;
		ft_putstr("Enter a valid number between 1 and ");
		ft_putnbr(e->board->width);
		ft_putchar('\n');
		if (!(get_next_line(0, &line)))
			return (0);
		n = ft_atoi(line);
		while (line[i] != '\0')
		{
			if (line[i] < '0' || line[i] > '9')
				n = 0;
			i++;
		}
		if (e->board->tab[0][n - 1] != 0 && n > 0)
		{
			ft_putendl("You can't play this move. The column is full.");
			n = 0;
		}
	}
	return (n);
}

int		player_turn(t_env *e)
{
	int	n;

	n = 0;
	ft_putstr("Its your turn, in which column will you play ?\n");
	if (n < 1 || n > e->board->width)
		n = error(n, e);
	if (putcoin(e->board, n - 1, PLAYER) == 0)
		error(n, e);
	return (1);
}

void 	ia_turn(t_env *e)
{
	ft_putstr("IA plays :\n");
	minmax(e, e->ia->level);
	putcoin(e->board, e->ia->move, IA);
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
