#include <keypadc.h>
#include "game.h"
#include "constants.h"
#include "utils.h"

Game Game_new() {
	return (Game){
			.player = Player_new(),
			.enemy = Enemy_new(),
	};
}

void update_keys(Game *game) {
	game->keys_prev = game->keys;

	kb_Scan();

	game->keys.up = kb_Data[7] & kb_Up;
	game->keys.down = kb_Data[7] & kb_Down;
	game->keys.left = kb_Data[7] & kb_Left;
	game->keys.right = kb_Data[7] & kb_Right;
	game->keys.jump = kb_Data[1] & kb_2nd;
}

void update_player(Game *game) {
	Player *player = &game->player;
	Keys *keys = &game->keys;
	Keys *keys_prev = &game->keys_prev;

	if(player->jump_time) {
		player->yvel = PLAYER_JUMP_SPEED;
	}
	player->yvel += GRAVITY;
	CLAMP_BELOW(player->yvel, MAX_YVEL);

	player->y += player->yvel;

	if((player->on_ground = player->y + PLAYER_HEIGHT > FLOOR_HEIGHT)) {
		player->y = FLOOR_HEIGHT - PLAYER_HEIGHT;
	}

	if(keys->left != keys->right) {
		if(keys->right) {
			player->xvel = PLAYER_WALK_SPEED;
			player->direction = Right;

			if(player->on_ground && player->walk_time >= 0) {
				player->walk_time++;
				if(player->walk_time > PLAYER_WALK_ANIMATION_SPEED * 3) {
					player->walk_time = 1;
				}
			} else {
				player->walk_time = 0;
			}
		} else {
			player->xvel = -PLAYER_WALK_SPEED;
			player->direction = Left;

			if(player->on_ground && player->walk_time <= 0) {
				player->walk_time--;
				if(player->walk_time < PLAYER_WALK_ANIMATION_SPEED * -3) {
					player->walk_time = -1;
				}
			} else {
				player->walk_time = 0;
			}
		}
	} else {
		player->walk_time = 0;
	}

	player->xvel *= FRICTION;
	player->x += player->xvel;

	CLAMP_ABOVE(player->x, WALL_WIDTH - PLAYER_LEFT);
	CLAMP_BELOW(player->x, LCD_WIDTH - WALL_WIDTH - PLAYER_RIGHT);

	if(keys->jump) {
		if(player->on_ground && !keys_prev->jump) {
			player->jump_time = PLAYER_MAX_JUMP_TIME;
		}

		if(player->jump_time) {
			player->jump_time--;
		}
	} else {
		player->jump_time = 0;
	}
}

void Game_update(Game *self) {
	update_keys(self);
	update_player(self);

	self->enemy.timer++;
}

void Game_render(Game *self) {
	gfx_FillScreen(1);

	gfx_RLETSprite_NoClip(left_wall_sprite, 0, 0);
	gfx_RLETSprite_NoClip(left_wall_sprite, 0, LCD_HEIGHT / 2);
	gfx_RLETSprite_NoClip(right_wall_sprite, LCD_WIDTH - 29, 0);
	gfx_RLETSprite_NoClip(right_wall_sprite, LCD_WIDTH - 29, LCD_HEIGHT / 2);

	gfx_RLETSprite(floor_sprite, 0, LCD_HEIGHT - floor_sprite_height);
	gfx_RLETSprite(
			floor_sprite, floor_sprite_width, LCD_HEIGHT - floor_sprite_height);

	Enemy_render(&self->enemy);
	Player_render(&self->player);

	gfx_SwapDraw();
}
