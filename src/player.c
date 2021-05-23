#include "player.h"
#include "constants.h"

Player Player_new() {
	return (Player){
			.x = 0.0,
			.y = 0.0,
			.xvel = 0.0,
			.yvel = 0.0,
	};
}

void Player_update(Player *player) {
	player->x += player->xvel;

	player->yvel += GRAVITY;
	if(player->yvel > MAX_YVEL) {
		player->yvel = MAX_YVEL;
	}

	player->y += player->yvel;

	if(player->y + PLAYER_HEIGHT > FLOOR_HEIGHT) {
		player->y = FLOOR_HEIGHT - PLAYER_HEIGHT;
	}
}
