#include "player.h"
#include "gfx/gfx.h"
#include "constants.h"

Player Player_new() {
	return (Player){
			.x = 230.0,
			.y = 0.0,
			.xvel = 0.0,
			.yvel = 0.0,

			.direction = Left,

			.on_ground = false,

			.jump_time = 0,
			.walk_time = 0,
	};
}

gfx_rletsprite_t *Player_sprite(Player *self) {
	if(self->on_ground && self->walk_time) {
		int8_t walk_time = self->walk_time;
		if(walk_time > 0) {
			switch((walk_time - 1) / PLAYER_WALK_ANIMATION_SPEED + 1) {
				case 1:
					return player_walk_right_1_sprite;
				case 2:
					return player_walk_right_2_sprite;
				case 3:
					return player_walk_right_3_sprite;
			}
		} else {
			walk_time = -walk_time;
			switch((walk_time - 1) / PLAYER_WALK_ANIMATION_SPEED + 1) {
				case 1:
					return player_walk_left_1_sprite;
				case 2:
					return player_walk_left_2_sprite;
				case 3:
					return player_walk_left_3_sprite;
			}
		}
	} else if(self->direction == Left) {
		return player_idle_left_sprite;
	} else {
		return player_idle_right_sprite;
	}

	return player_idle_right_sprite;
}

void Player_render(Player *self) {
	gfx_RLETSprite_NoClip(Player_sprite(self), self->x, self->y);
}
