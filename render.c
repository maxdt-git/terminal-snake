/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:13:05 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 11:27:26 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

// efface terminal et replace curseur
void	render_clear(void)
{
	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
}



void	render_board
