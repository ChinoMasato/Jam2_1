#pragma once
#include"DxLib.h"
#include"game.h"
const int effectnum = 100;
extern int img[10];

struct effect
{
	double x;
	double y;
	double animeno = 0;
	int maxanimeno = 0;
	bool enable = false;
};
extern effect eff[effectnum];
extern int blockse;

void initeffect(void);
void updateeffect(void);
void draweffect(void);
