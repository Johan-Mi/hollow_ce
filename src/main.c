#include <graphx.h>
#include <keypadc.h>
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
		Game_render(&game);
	}

	end();
	return EXIT_SUCCESS;
}

void begin() {
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
