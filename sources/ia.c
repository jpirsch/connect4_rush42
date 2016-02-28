/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:54:33 by jpirsch           #+#    #+#             */
/*   Updated: 2016/02/28 05:54:43 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_ia	*init_ia()
{
	t_ia	*ia;

	if (!(ia = malloc(sizeof(t_ia))))
		return (NULL);
	return (ia);
}

int		free_ia(t_ia *ia)
{
	(void)ia;
	return (1);
}

int		minmax(t_env *e)
{
	return (e->board->width - 1);
}
