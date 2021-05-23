#pragma once

#include <stdint.h>

typedef struct {
	float x;
	float y;
	float xvel;
	float yvel;
} Player;

Player Player_new();

void Player_update(Player *player);
