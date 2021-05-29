#pragma once

#include <tice.h>
#include "gfx/gfx.h"

#define GRAVITY 1.4
#define MAX_YVEL 15
#define FRICTION 0.1

#define FLOOR_HEIGHT (LCD_HEIGHT - floor_sprite_height)
#define WALL_WIDTH (left_wall_sprite_width - 4)

#define PLAYER_HEIGHT 45
#define PLAYER_WIDTH 18
#define PLAYER_LEFT 15
#define PLAYER_RIGHT (PLAYER_LEFT + PLAYER_WIDTH)
#define PLAYER_WALK_SPEED 50
#define PLAYER_JUMP_SPEED -10
#define PLAYER_MAX_JUMP_TIME 11
