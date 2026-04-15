/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:16:49 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 17:21:24 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static void	add_node(t_game *game, int x, int y)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->x = x;
	node->y = y;
	node->next = NULL;
	if (game->head == NULL)
	{
		game->head = node;
		game->tail = node;
	}
	else
	{
		game->tail->next = node;
		game->tail = node;
	}
}

void	game_spawn_food(t_game *game)
{
	game->food_x = (rand() % (GRID_W - 2) + 2);
	game->food_y = (rand() % (GRID_H - 2) + 2);
}

void	game_init(t_game *game)
{
	game->length = 3;
	game->dir = DIR_RIGHT;
	game->score = 0;
	game->running = 1;
	game->head = NULL;
	game->tail=NULL;
	srand(time(NULL));

	// creer tete-corps-queue
	add_node(game, GRID_W / 2, GRID_H / 2);
	add_node(game, GRID_W / 2 - 1, GRID_H / 2);
	add_node(game, GRID_W / 2 - 2, GRID_H / 2);

	//placer premier nourriture
	game_spawn_food(game);
}

int	game_tick(t_game *game)
{
	int	new_x;
	int	new_y;
	t_node	*node;
	t_node	*new_head;
	t_node *prev;

	// pour les directions
	if (game->dir == DIR_RIGHT)
	{
		new_x = game->head->x + 1;
		new_y = game->head->y;
	}
	else if (game->dir == DIR_LEFT)
	{
		new_x = game->head->x - 1;
		new_y = game->head->y;
	}
	else if (game->dir == DIR_UP)
	{
		new_x = game->head->x;
		new_y = game->head->y - 1;
	}
	else
	{
		new_x = game->head->x;
		new_y = game->head->y + 1;
	}

	// pour collision mur
	if ((new_x <= 0 || new_x >= GRID_W) || (new_y <= 0 || new_y >= GRID_H))
		return (0);

	// pour collision soi-meme
	node = game->head;
	while (node != NULL)
	{
		if (node->x == new_x && node->y == new_y)
			return (0);
		node = node->next;
	}

	// ajouter maillon en tete
	new_head = malloc(sizeof(t_node));
	if (!new_head)
		return (0);
	new_head->x = new_x;
	new_head->y = new_y;
	new_head->next = game->head;
	game->head = new_head;

	// si on mange ajoute devant et supprime derrière
	if (new_x == game->food_x && new_y == game->food_y)
	{
		game->score++;
		game->length++;
		game_spawn_food(game);
	}
	else
	{
		prev = game->head;
		while (prev->next != game->tail)
			prev = prev->next;
		free(game->tail);
		game->tail = prev;
		game->tail->next = NULL;
	}
	return (1);
}

void	game_free(t_game *game)
{
	t_node	*node;
	t_node	*next;

	node = game->head;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	game->head = NULL;
	game->tail = NULL;
}
