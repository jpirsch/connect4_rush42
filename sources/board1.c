/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 05:47:24 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		board_is_full(t_board *board)
{
	int i;
	int j;

	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			if (board->tab[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dir(t_board *board, int i, int j, int n)
{
	static int	dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},
							{1, -1}, {1, 0}, {1, 1}};
	int			k;
	int			player;
	int			align;

	k = 0;
	player = board->tab[i][j];
	align = 1;
	while (k < board->size_winning_chain)
	{
		if (i + k * dir[n][0] < board->height && j + k * dir[n][1] <
			board->width && i + k * dir[n][0] >= 0 && j + k * dir[n][1] >= 0)
			align += (board->tab[i + k * dir[n][0]][j + k * dir[n][1]] ==
					player) ? 1 : -1000000;
		else if (i + k * dir[n][0] > board->height || j + k * dir[n][1] >
				board->width || i + k * dir[n][0] < 0 || j + k * dir[n][1] < 0)
			break ;
		if (align == board->size_winning_chain + 1)
			return (player);
		k++;
	}
	return (0);
}

int		victoire(t_board *board)
{
	int	i;
	int	j;
	int	n;
	int	winner;

	i = -1;
	while (++i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			if (board->tab[i][j] != 0)
			{
				n = 0;
				while (n < 8)
				{
					if ((winner = check_dir(board, i, j, n)) != 0)
						return (winner);
					n++;
				}
			}
			j++;
		}
	}
	return (0);
}

int		partie_finie(t_board *board)
{
	int end_score;

	end_score = victoire(board);
	if (end_score == 1)
		return (end_score);
	end_score = board_is_full(board);
	return (end_score);
}
