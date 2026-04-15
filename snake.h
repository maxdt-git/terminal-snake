/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:33:23 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 11:31:48 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

// tous les includes nécessaires
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <signal.h>

// définir la taille de la grille
// vitesse du jeu
# define GRID_W 40
# define GRID_H 20
# define GAME_SPEED 150000

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

#endif
