#pragma once

#include "player.h"
#include "keys.h"

typedef struct {
	Player player;
	Keys keys;
} Game;

Game Game_new();
void Game_update(Game *self);
