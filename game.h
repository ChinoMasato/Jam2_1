#pragma once
#include"DxLib.h"
#include"effect.h"

const int windowx = 600;
const int windowy = 800;

const int width = 10;
const int vertical = 10;
const int startx = 50;
const int starty = 300;
const int blockscale = (windowx - startx ) / width - (startx / width);
const int erasenum = 3;
extern int ready;
extern int blocknum;
extern bool gameclearflag;
extern bool gameoverflag;


void initgame(void);
void updategame(void);
void drawgame(void);
