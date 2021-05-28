#pragma once

#include "player.h"

typedef struct {
	Player player;
} Game;

Game Game_new();
void Game_update(Game *self);
