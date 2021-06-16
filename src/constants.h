#pragma once

#include <tice.h>
#include "gfx/gfx.h"

#define GRAVITY 0.4
#define MAX_YVEL 7
#define FRICTION 0.1

#define FLOOR_HEIGHT (LCD_HEIGHT - floor_sprite_height + 2)
#define WALL_WIDTH (left_wall_sprite_width - 4)

#define PLAYER_HEIGHT 45
#define PLAYER_WIDTH 18
#define PLAYER_LEFT 15
#define PLAYER_RIGHT (PLAYER_LEFT + PLAYER_WIDTH)
#define PLAYER_WALK_SPEED 27
#define PLAYER_JUMP_SPEED -5
#define PLAYER_MAX_JUMP_TIME 19
#define PLAYER_WALK_ANIMATION_SPEED 6
