/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:33:23 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 17:46:18 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

// tous les includes necessaires
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <time.h>

// définir la taille de la grille
// vitesse du jeu
# define GRID_W 40
# define GRID_H 20
# define GAME_SPEED 75000

// voir les directions
typedef enum e_dir
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
}	t_dir;

// maillon de la chaine/snake
typedef struct s_node
{
	int	x;
	int	y;
	struct s_node	*next;
}	t_node;

// tout ce dont a besoin le jeu
// position tete/queue - taille - direction - position food
// score - en jeu/fini
typedef struct s_game
{
	t_node *head;
	t_node *tail;
	int	length;
	t_dir dir;
	int	food_x;
	int	food_y;
	int	score;
	int running;
	struct termios orig_term;
}	t_game;

// variable globale
extern t_game	g_game;

// fonctions utilisees
// terminal.c
void	terminal_raw_mode(t_game *game);
void	terminal_restore(t_game *game);

// render.c
void	render_clear(void);
void	render_board(t_game *game);

// game.c
void	game_init(t_game *game);
void	game_spawn_food(t_game *game);
int		game_tick(t_game *game);
void	game_free(t_game *game);

// input.c
t_dir	input_read_dir(t_dir current);

// utils.c
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);

#endif
