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
	bool checkedx;
	bool checkedy;
	bool checked;
	int countx;
	int county;
	int count;
	int no;
	int erase;
};

extern BLOCK block[width * vertical];
void initblock(void);
void updateblock(void);
void drawblock(void);
int countx(int _x, int _y, BLOCKTYPE _type, int _count);
int county(int _x, int _y, BLOCKTYPE _type, int _count);
int count(int _x, int _y, BLOCKTYPE _type, int _count);
void erasex(int _x, int _y, BLOCKTYPE _type);
void erasey(int _x, int _y, BLOCKTYPE _type);
void erase(int _x, int _y, BLOCKTYPE _type);