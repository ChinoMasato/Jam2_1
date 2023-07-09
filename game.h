#pragma once
#include"DxLib.h"

const int windowx = 800;
const int windowy = 800;

const int width = 15;
const int vertical = 8;
const int startx = 50;
const int starty = 300;
const int blockscale = (windowx - startx ) / width - (startx / width);
const int erasenum = 4;
extern int blocknum;
extern bool gameclearflag;
extern bool gameoverflag;

void initgame(void);
void updategame(void);
void drawgame(void);