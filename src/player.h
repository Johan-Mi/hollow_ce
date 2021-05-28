#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	float x;
	float y;
	float xvel;
	float yvel;
} Player;

Player Player_new();
