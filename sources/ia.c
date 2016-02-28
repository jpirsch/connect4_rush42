/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:54:33 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 08:15:02 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_ia	*init_ia(int level)
{
	t_ia	*ia;

	if (!(ia = malloc(sizeof(t_ia))))
		return (NULL);
	ia->level = level;
	ia->move = 0;
	ia->turn = PLAYER;
	return (ia);
}

int		free_ia(t_ia *ia)
{
	(void)ia;
	return (1);
}

int		eval(t_env *e)
{
	int	score;

	if (victoire(e->board) == IA)
		score = 10000;
	if (victoire(e->board) == PLAYER)
		score = -10000;
	return (score);
}

int		minmax(t_env *e, int level)
{
	int	j;
	int	score;
	int	bestScore;

	if (level == 0 || partie_finie(e->board))
		return (eval(e));
	e->ia->turn = (e->ia->turn == IA) ? PLAYER : IA; 
	bestScore = (e->ia->turn == IA) ? -10000 : 10000; 

	j = -1;
	while (++j < e->board->width)
	{
		if (putcoin(e->board, j, e->ia->turn) == 0)
			ft_putstr("unvalid move ");
		else
		{
			score = minmax(e, level - 1);
			if (e->ia->turn == IA)
				bestScore = (score > bestScore) ? score : bestScore;
			if (e->ia->turn == PLAYER)
				bestScore = (score < bestScore) ? score : bestScore;
			e->ia->move = j;
		}
		remove_coin(e->board, j);
	}
	return (bestScore);
}
