#include <graphx.h>
#include <stdlib.h>
#include "constants.h"
#include "player.h"

void begin();
void end();
bool step();
void draw();

Player player;

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

	player = Player_new();
}

void end() {
	gfx_End();
}

bool step() {
	Player_update(&player);

	return !os_GetCSC();
}

void draw() {
	gfx_FillScreen(50);

	gfx_TransparentSprite_NoClip(left_wall_sprite, 0, 0);
	gfx_TransparentSprite_NoClip(left_wall_sprite, 0, LCD_HEIGHT / 2);
	gfx_TransparentSprite_NoClip(right_wall_sprite, LCD_WIDTH - 29, 0);
	gfx_TransparentSprite_NoClip(
			right_wall_sprite, LCD_WIDTH - 29, LCD_HEIGHT / 2);

	gfx_TransparentSprite(floor_sprite, 0, FLOOR_HEIGHT);
	gfx_TransparentSprite(floor_sprite, floor_sprite_width, FLOOR_HEIGHT);

	gfx_TransparentSprite(player_sprite, player.x, player.y);

	gfx_SwapDraw();
}
