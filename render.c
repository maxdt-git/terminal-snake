/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:13:05 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 16:15:59 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

// efface terminal et replace curseur
void	render_clear(void)
{
	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
}

// faire bouger le curseur
static void	move_cursor(int y, int x)
{
	write(1, "\033[", 2);
	ft_putnbr_fd(y, 1);
	write(1, ";", 1);
	ft_putnbr_fd(x, 1);
	write(1, "H", 1);
}

void	render_board(t_game *game)
{
	int	x;
	int	y;
	t_node	*node;

	// boucles pour creer les murs
	x = 1;
	while (x <= GRID_W)
	{
		move_cursor(1, x);
		write(1, "#", 1);
		move_cursor(GRID_H, x);
		write(1, "#", 1);
		x++;
	}
	y = 1;
	while (y <= GRID_H)
	{
		move_cursor(y, 1);
		write(1, "#", 1);
		move_cursor(y, GRID_W);
		write(1, "#", 1);
		y++;
	}

	// nourriture
	move_cursor(game->food_y, game->food_x);
	write(1, "*", 1);

	// le serpent
	node = game->head;
	while (node != NULL)
	{
		move_cursor(node->y, node->x);
		write(1, "O", 1);
		node = node->next;
	}
}
