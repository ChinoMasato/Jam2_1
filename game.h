#pragma once
#include"DxLib.h"


const int width = 10;
const int vertical = 8;
const int blockscale = 25;
const int startmovex = 50;
const int startmovey = 50;
extern int blocknum;

void initgame(void);
void updategame(void);
void drawgame(void);