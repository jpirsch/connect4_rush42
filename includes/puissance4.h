/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/08 13:34:24 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H
# include "libft.h"
# define IA 1
# define PLAYER 2

typedef struct	s_board
{
	int	width;
	int	height;
	int	size_winning_chain;
	int	**tab;
}		t_board;

typedef struct	s_ia
{
	int	level;
}		t_ia;

typedef struct	s_env
{
	t_board	*board;
	t_ia	*ia;
}		t_env;

/*
 * Interface
 */
int	launch_interface(t_env *e);
/*
 * Board
 */
t_board	*init_board();
int	free_board(t_board *board);
void	display(t_board *board);
void	putcoin(t_board *board, int col);
int	partie_finie(t_board *board);
/*
 * IA
 */
t_ia	*init_ia();
int	free_ia(t_ia *ia);
int	minmax(t_env *e);
#endif
