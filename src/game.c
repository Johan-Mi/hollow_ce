#include "game.h"
#include "constants.h"

Game Game_new() {
	return (Game){
			.player = Player_new(),
	};
}

void update_player(Game *game) {
	Player *player = &game->player;

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

void Game_update(Game *self) {
	update_player(self);
}
