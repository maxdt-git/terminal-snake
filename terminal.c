/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:55:57 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 11:08:35 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

// preparer le terminal
// ne pas afficher les touches tapées + ne plus attendre entrée
// prend config actuelle -> la copie pour modif -> modif et applique
void	terminal_raw_mode(t_game *game)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &game->orig_term);
	raw = game->orig_term;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// restaurer le terminal
void	terminal_restore(t_game *game)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &game->orig_term);
}
