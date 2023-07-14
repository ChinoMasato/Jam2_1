#pragma once
#include"DxLib.h"
#include"game.h"

extern int titleimg;
extern int tutorialimg;
extern bool draweat;
extern int Cimg[2];

void initimg(void);
void drawtitle(void);
void drawtutorial(void);
void drawgameimg(void);
void drawgameclear(void);
void drawgameover(void);
void drawC(void);