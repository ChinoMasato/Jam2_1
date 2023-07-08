#include"block.h"
#include "cursor.h"

BLOCK block[width * vertical];

/*int mouse = 0;
bool mouseflag = false;
int mousex = 0;
int mousey = 0;
bool click = false;*/

int blockimg[5];

void initblock(void)
{
	int countrow = 0;
	int nextrow = 0;
	int R;
	for (int i = 0; i < blocknum; i++)
	{
		R = GetRand(4) + 1;
		if (R == 1)
		{
			block[i].type = type1;
			block[i].c = GetColor(255, 255, 255);
		}
		if (R == 2)
		{
			block[i].type = type2;
			block[i].c = GetColor(255, 255, 0);
		}
		if (R == 3)
		{
			block[i].type = type3;
			block[i].c = GetColor(255, 0, 255);
		}
		if (R == 4)
		{
			block[i].type = type4;
			block[i].c = GetColor(0, 255, 255);
		}
		if (R == 5)
		{
			block[i].type = type5;
			block[i].c = GetColor(255, 0, 0);
		}
		block[i].x = countrow;
		block[i].y = nextrow;
		block[i].enable = true;
		countrow += 1;
		if (countrow == width)
		{
			countrow = 0;
			nextrow += 1;
		}
	}
	blockimg[0] = LoadGraph("block1.png", true);
	blockimg[1] = LoadGraph("", true);
	blockimg[2] = LoadGraph("", true);
	blockimg[3] = LoadGraph("", true);
	blockimg[4] = LoadGraph("", true);
}
void updateblock(void)
{
	/*mouse = GetMouseInput();
	if ((mouse & MOUSE_INPUT_LEFT) != 0)
	{
		if (click == false)
		{
			click = true;
			mouseflag = true;
			GetMousePoint(&mousex, &mousey);
		}
	}
	else
	{
		click = false;
	}
	if (mouse & MOUSE_INPUT_RIGHT)
	{
		mouseflag = false;
	}*/
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
			SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
			DrawBox(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, block[i].c, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
			DrawBox(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, block[i].c, false);
			if (block[i].type == type1)
			{
				DrawExtendGraph(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, blockimg[0], true);
			}
			else if (block[i].type == type2)
			{
				DrawExtendGraph(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, blockimg[1], true);
			}
			else if (block[i].type == type3)
			{
				DrawExtendGraph(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, blockimg[2], true);
			}
			else if (block[i].type == type4)
			{
				DrawExtendGraph(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, blockimg[3], true);
			}
			else if (block[i].type == type5)
			{
				DrawExtendGraph(block[i].x * blockscale + startx, block[i].y * blockscale + starty, block[i].x * blockscale + blockscale + startx, block[i].y * blockscale + blockscale + starty, blockimg[4], true);
			}
		}
	}
}