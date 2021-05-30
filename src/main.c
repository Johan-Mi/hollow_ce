#include <graphx.h>
#include <keypadc.h>
#include <stdlib.h>
#include "constants.h"
#include "game.h"

void begin();
void end();
bool step();
void draw();

Game game;

int main() {
	begin();

	while(step()) {
		draw();
	}

	end();
	return EXIT_SUCCESS;
}

void begin() {
	os_ClrHome();
	gfx_Begin();
	gfx_SetDrawBuffer();

	gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);

	game = Game_new();
}

void end() {
	gfx_End();
}

bool step() {
	Game_update(&game);

	return !(kb_Data[6] & kb_Clear);
}

void draw() {
	Player *player = &game.player;

	gfx_FillScreen(50);

	gfx_RLETSprite_NoClip(left_wall_sprite, 0, 0);
	gfx_RLETSprite_NoClip(left_wall_sprite, 0, LCD_HEIGHT / 2);
	gfx_RLETSprite_NoClip(right_wall_sprite, LCD_WIDTH - 29, 0);
	gfx_RLETSprite_NoClip(right_wall_sprite, LCD_WIDTH - 29, LCD_HEIGHT / 2);

	gfx_RLETSprite(floor_sprite, 0, FLOOR_HEIGHT);
	gfx_RLETSprite(floor_sprite, floor_sprite_width, FLOOR_HEIGHT);

	gfx_RLETSprite(Player_sprite(player), player->x, player->y);

	gfx_SwapDraw();
}
