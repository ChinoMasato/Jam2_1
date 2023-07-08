#pragma once
#include"DxLib.h"
#include"game.h"

enum BLOCKTYPE
{
	type1,
	type2,
	type3,
	type4,
	type5
};

struct BLOCK
{
	BLOCKTYPE type;
	double x;
	double y;
	int c;
	bool enable;
	bool fill;
};

extern BLOCK block[width * vertical];

void initblock(void);
void updateblock(void);
void drawblock(void);