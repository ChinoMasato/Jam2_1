#pragma once
#include"DxLib.h"


const int width = 10;
const int vertical = 8;
const int blockscale = 50;
const int startx = 50;
const int starty = 300;
const int erasenum = 4;
extern int blocknum;
extern bool gameclearflag;
extern bool gameoverflag;

void initgame(void);
void updategame(void);
void drawgame(void);