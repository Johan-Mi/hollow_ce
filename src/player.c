#include "player.h"

Player Player_new() {
	return (Player){
			.x = 230.0,
			.y = 0.0,
			.xvel = 0.0,
			.yvel = 0.0,
	};
}
