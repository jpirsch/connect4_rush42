/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 04:31:27 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_board	*init_board(void)
{
	t_board	*board;
	int		i;
	int		j;

	if (!(board = malloc(sizeof(t_board))))
		return (NULL);
	board->width = 7;
	board->height = 6;
	board->size_winning_chain = 4;
	if (!(board->tab = malloc(sizeof(int*) * board->height)))
		return (NULL);
	i = 0;
	while (i < board->height)
	{
		if (!(board->tab[i] = malloc(sizeof(int) * board->width)))
			return (NULL);
		j = 0;
		while (j < board->width)
		{
			board->tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

int	free_board(t_board *board)
{
	(void)board;
	return (1);
}

void	display(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	ft_putchar('\n');
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			ft_putnbr(board->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	putcoin(t_board *board, int col)
{
	int i;

	i = 0;
	while (i < board->height && board->tab[i][col] == 0)
		i++;
	board->tab[i - 1][col] = 1;
}

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


int		victoire(t_board *board)
{
/*	static int	dir[8][2] = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},
							{1, 0},{1, 1}};
	int			i;
	int			j;
	int			k;
	int			n;
	int			a;
	int			b;
	int			player;
	int			align;
*/
	(void)board;
	return (0);
	/*
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 2)
		{
			if (board->tab[i][j] != 0)
			{
				n = 0;
				while (n < 8)
				{
					k = 0;
					player = board->tab[i][j];
					align = 1;
					while (k < board->size_winning_chain)
					{
						a = k*dir[n][0];
						b = k*dir[n][1];
						if (i+a < board->width && j+b < board->height && i+a >= 0 && j+b >= 0)
							align += (board->tab[i+a][j+b] == player) ? 1 : -1000000;
						else if (i+a > board->width || j+b > board->height || i+a < 0 || j+b < 0)
							k = board->size_winning_chain +1;    //Si on atteint les bords du tableau on sort
						k++;
					}
					n++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);*/
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
