#include"block.h"

BLOCK block[width * vertical];

int mouse = 0;
bool mouseflag = false;
int mousex = 0;
int mousey = 0;

void initblock(void)
{
	int countrow = 0;
	int nextrow = 0;
	int R;
	for (int i = 0; i < blocknum; i++)
	{
		if (countrow == width)
		{
			countrow = 0;
			nextrow += 1;
		}
		countrow += 1;
		R = GetRand(4) + 1;
		if (R == 1)
		{
			block[i].type = type1;
			block[i].c = GetColor(255, 255, 255);
		}
		if (R == 2)
		{
			block[i].type = type2;
			block[i].c = GetColor(0, 255, 255);
		}
		if (R == 3)
		{
			block[i].type = type3;
			block[i].c = GetColor(255, 0, 255);
		}
		if (R == 4)
		{
			block[i].type = type4;
			block[i].c = GetColor(255, 255, 0);
		}
		if (R == 5)
		{
			block[i].type = type5;
			block[i].c = GetColor(100, 100, 100);
		}
		block[i].x = countrow;
		block[i].y = nextrow;
		block[i].enable = true;
		block[i].fill = true;
	}
}
void updateblock(void)
{
	mouse = GetMouseInput();
	if (mouse & MOUSE_INPUT_LEFT)
	{
		mouseflag = true;
		GetMousePoint(&mousex, &mousey);
	}
	if (mouse & MOUSE_INPUT_RIGHT)
	{
		mouseflag = false;
	}
}
void drawblock(void)
{
	if (mouseflag == true)
	{
		DrawBox(mousex - 25, mousey - 25, mousex + 25, mousey + 25, 0xffffff, TRUE);
	}
	for (int i = 0; i < blocknum; i++)
	{
		if (block[i].enable == true)
		{
			DrawBox(block[i].x * blockscale + 100, block[i].y * blockscale + 100, block[i].x * blockscale + 100 + blockscale, block[i].y * blockscale + 100 + blockscale, block[i].c, block[i].fill);
		}
	}
}