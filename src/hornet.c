//                           ⣀⣀⣤⠦   ⣀
//                        ⣀⡴⠟⣩⡾⠋  ⣠⡞⣿
//                     ⢀⣴⠖⠉⣠⡶⠉  ⡴⠚⠉⢸⠃
//                    ⣠⠛⠁ ⡴⠋ ⢀⣤⠞⠁ ⢀⡌
//                  ⢀⡾⠋ ⢀⡾  ⣠⠟⠁  ⢀⡾⠁
//                  ⠟  ⢀⡟ ⣤⠟⠁   ⢀⡾⠁
//                ⢀⡼   ⠘⠓⠚⠁    ⢀⡞⠁
//                ⣸⠃          ⢠⡾
//               ⢀⡏          ⡾⠃
//               ⠸⡇⣶  ⢀⣶⣶ ⢀⣴⠞
//                ⠻⣜⠃ ⠿⢿⣋⡴⠛⠁
//                ⠐⢿⣿⣿⣿⣿⣿⡷             ⢀⣀⡀
//                 ⢀⣿⣿⣿⣿⣯            ⣀⡴⠿⠿⣿
//               ⢀⣠⣾⣿⣿⣿⣿⣿⣷⣄⣀    ⢀⣀⡠⣴⡻⠽⠞⠉⠛⠁
//              ⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⢶⣯⠷⠛⠁
//            ⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧
//            ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//            ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠛⠁
//            ⣤⠶⠋⣠⠴⠞⠉⠹⣿⠁⠙⣿⠉
//        ⣠⠤⣒⣿⠔⠒⠋     ⢻⡄ ⣿⡆
//    ⢀⣠⣔⠪⠕⠋⠁         ⠈⣧ ⢸⡇
//  ⡠⠾⠛⠉               ⣿ ⢸⡇
//                     ⠹ ⠸

#include <graphx.h>
#include "gfx/gfx.h"
#include "hornet.h"
#include "constants.h"

Enemy Enemy_new() {
	return (Enemy){
			.x = 64.0,
			.y = 154.0,
			.xvel = 0.0,
			.yvel = 0.0,

			.direction = Right,

			.timer = 0,

			/* .state = ES_Idle, */
			.state = ES_Run,
	};
}

gfx_rletsprite_t *Enemy_sprite(Enemy *self) {
	switch(self->state) {
		case ES_Idle:
			if(self->direction == Left) {
				return hornet_idle_left_sprite;
			} else {
				return hornet_idle_right_sprite;
			}

		case ES_Run:
			if(self->direction == Left) {
				switch((self->timer / HORNET_RUN_ANIMATION_SPEED) % 4) {
					case 0:
					default:
						return hornet_run_left_1_sprite;
					case 1:
						return hornet_run_left_2_sprite;
					case 2:
						return hornet_run_left_3_sprite;
					case 3:
						return hornet_run_left_4_sprite;
				}
			} else {
				switch((self->timer / HORNET_RUN_ANIMATION_SPEED) % 4) {
					case 0:
					default:
						return hornet_run_right_1_sprite;
					case 1:
						return hornet_run_right_2_sprite;
					case 2:
						return hornet_run_right_3_sprite;
					case 3:
						return hornet_run_right_4_sprite;
				}
			}
	}
}

void Enemy_render(Enemy *self) {
	gfx_RLETSprite_NoClip(Enemy_sprite(self), self->x, self->y);
}
