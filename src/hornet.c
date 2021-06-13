#include <graphx.h>
#include "gfx/gfx.h"
#include "hornet.h"

Enemy Enemy_new() {
	return (Enemy){
			.x = 64.0,
			.y = 154.0,
			.xvel = 0.0,
			.yvel = 0.0,

			.direction = Right,

			.timer = 0,

			.state = ES_Idle,
	};
}

gfx_rletsprite_t *Enemy_sprite(Enemy *self) {
	if(self->direction == Left) {
		return hornet_idle_left_sprite;
	} else {
		return hornet_idle_right_sprite;
	}
}

void Enemy_render(Enemy *self) {
	gfx_RLETSprite_NoClip(Enemy_sprite(self), self->x, self->y);
}
