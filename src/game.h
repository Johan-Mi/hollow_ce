#pragma once

#include "player.h"
#include "keys.h"

typedef struct {
	Player player;
	Keys keys;
	Keys keys_prev;
} Game;

Game Game_new();
void Game_update(Game *self);
