#include <tice.h>
#include <graphx.h>
#include <stdlib.h>
#include "gfx/gfx.h"
#include "player.h"

#define FLOOR_HEIGHT (LCD_HEIGHT - floor_sprite_height)

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

	player.x = 0;
	player.y = 0;
}

void end() {
	gfx_End();
}

bool step() {
	player.x++;
	player.y++;

	return !os_GetCSC();
}

void draw() {
	gfx_FillScreen(50);

	gfx_TransparentSprite(floor_sprite, 0, FLOOR_HEIGHT);
	gfx_TransparentSprite(floor_sprite, floor_sprite_width, FLOOR_HEIGHT);
	gfx_TransparentSprite(player_sprite, player.x, player.y);

	gfx_SwapDraw();
}
