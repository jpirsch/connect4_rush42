/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 00:16:40 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_board	*init_board()
{
	t_board	*board;
	int	i;
	int	j;

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
	ft_putstr("col : ");
	ft_putnbr(col);
	while (i < board->height && board->tab[i][col] == 0)
        ft_putstr(" da ");
        ft_putnbr(i);
		i++;
    ft_putstr("here\n");
	board->tab[i - 1][col] = 1;
}

int	partie_finie(t_board *board)
{
	int	end;

	end = board->width;
	end = 0;
	return (end);
}
