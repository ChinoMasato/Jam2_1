#pragma once
#include "block.h"

struct SCORE
{
	int count;
	int img;
	int gorl;
	BLOCKTYPE type;
	bool enable;
	bool ok;
	int c;
};

extern SCORE score[9];

void initscore();
void updatescore();
void drawscore();
