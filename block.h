#pragma once
#include"DxLib.h"
#include"game.h"

enum BLOCKTYPE
{
	type0,
	type1,
	type2,
	type3,
	type4,
	type5,
	type6,
	type7,
	type8,
	type9
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
	bool erase;
	int fall;
};

extern BLOCK block[width * vertical];
extern int blockimg[9];
extern int dire;
extern int blockoutse;

void initblock(void);
void updateblock(void);
void drawblock(void);
int countx(int _x, int _y, BLOCKTYPE _type, int _count);
int county(int _x, int _y, BLOCKTYPE _type, int _count);
int count(int _x, int _y, BLOCKTYPE _type, int _count);
void erasex(int _x, int _y, BLOCKTYPE _type);
void erasey(int _x, int _y, BLOCKTYPE _type);
void erase(int _x, int _y, BLOCKTYPE _type);
void blockbreak(BLOCK blo);