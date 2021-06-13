#pragma once

#include "player.h"
#include "keys.h"
#include "enemy.h"

typedef struct {
	Player player;
	Keys keys;
	Keys keys_prev;
	Enemy enemy;
} Game;

Game Game_new();
void Game_update(Game *self);
void Game_render(Game *self);
