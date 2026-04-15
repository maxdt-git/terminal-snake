/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:31:28 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 17:40:43 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int	main(void)
{
	t_game	game;

	terminal_raw_mode(&game);
	game_init(&game);
	while (game.running)
	{
		game.dir = input_read_dir(game.dir);
		game.running = game_tick(&game);
		render_clear();
		render_board(&game);
		usleep(GAME_SPEED);
	}
	terminal_restore(&game);
	game_free(&game);
}
