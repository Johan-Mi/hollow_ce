#include <keypadc.h>
#include "game.h"
#include "constants.h"
#include "utils.h"

Game Game_new() {
	return (Game){
			.player = Player_new(),
	};
}

void update_keys(Game *game) {
	kb_Scan();

	game->keys.up = kb_Data[7] & kb_Up;
	game->keys.down = kb_Data[7] & kb_Down;
	game->keys.left = kb_Data[7] & kb_Left;
	game->keys.right = kb_Data[7] & kb_Right;
}

void update_player(Game *game) {
	Player *player = &game->player;

	player->yvel += GRAVITY;
	CLAMP_BELOW(player->yvel, MAX_YVEL);

	player->y += player->yvel;

	if((player->on_ground = player->y + PLAYER_HEIGHT > FLOOR_HEIGHT)) {
		player->y = FLOOR_HEIGHT - PLAYER_HEIGHT;

		if(game->keys.left != game->keys.right) {
			if(game->keys.right) {
				player->xvel = PLAYER_WALK_SPEED;
			} else {
				player->xvel = -PLAYER_WALK_SPEED;
			}
		}

		player->xvel *= GROUND_FRICTION;
	}

	player->x += player->xvel;

	CLAMP_ABOVE(player->x, WALL_WIDTH - PLAYER_LEFT);
	CLAMP_BELOW(player->x, LCD_WIDTH - WALL_WIDTH - PLAYER_RIGHT);
}

void Game_update(Game *self) {
	update_keys(self);
	update_player(self);
}
