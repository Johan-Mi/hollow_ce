#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <graphx.h>
#include "gfx/gfx.h"
#include "direction.h"

typedef struct {
	float x;
	float y;
	float xvel;
	float yvel;

	LeftRight direction;

	bool on_ground;

	unsigned jump_time;
	int8_t walk_time;
} Player;

Player Player_new();

gfx_rletsprite_t *Player_sprite(Player *self);
