#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	float x;
	float y;
	float xvel;
	float yvel;

	bool on_ground;
} Player;

Player Player_new();
