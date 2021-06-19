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
		uint8_t animation_index
				= (self->walk_time - 1) / PLAYER_WALK_ANIMATION_SPEED;
		if(self->direction == Right) {
			return (gfx_rletsprite_t *[]){
					player_walk_right_1_sprite,
					player_walk_right_2_sprite,
					player_walk_right_3_sprite,
			}[animation_index];
		} else {
			return (gfx_rletsprite_t *[]){
					player_walk_left_1_sprite,
					player_walk_left_2_sprite,
					player_walk_left_3_sprite,
			}[animation_index];
		}
	} else if(self->direction == Left) {
		return player_idle_left_sprite;
	} else {
		return player_idle_right_sprite;
	}
}

void Player_render(Player *self) {
	gfx_RLETSprite_NoClip(Player_sprite(self), self->x, self->y);
}
