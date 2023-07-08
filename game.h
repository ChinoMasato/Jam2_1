#pragma once
#include"DxLib.h"


const int width = 10;
const int vertical = 8;
const int blockscale = 25;
const int startx = 50;
const int starty = 50;
extern int blocknum;

void initgame(void);
void updategame(void);
void drawgame(void);