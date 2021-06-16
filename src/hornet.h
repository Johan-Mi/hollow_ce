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

#pragma once

#include <stdint.h>
#include "direction.h"

typedef enum {
	ES_Idle,
	ES_Run,
} __attribute__((packed)) EnemyState;

typedef struct {
	float x;
	float y;
	float xvel;
	float yvel;

	LeftRight direction;

	int timer;

	EnemyState state;
} Enemy;

Enemy Enemy_new();
void Enemy_render(Enemy *self);
