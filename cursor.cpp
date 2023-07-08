#include "cursor.h"
#include "block.h"

BLOCK cursor;
BLOCK ch;
int tempx;
int tempy;
int coolx;
int cooly;
int coolch;
void initcursor()
{
	cursor.x = 0;
	cursor.y = 0;
	cursor.c = GetColor(0, 255, 0);
}
void updatecursor()
{
	if (CheckHitKey(KEY_INPUT_D) == 1 && coolx == 0)
	{
		cursor.x += 1;
		coolx = 1;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1 && coolx == 0)
	{
		cursor.x -= 1;
		coolx = 1;
	}
	if (CheckHitKey(KEY_INPUT_W) == 1 && cooly == 0)
	{
		cursor.y -= 1;
		cooly = 1;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1 && cooly == 0)
	{
		cursor.y += 1;
		cooly = 1;
	}
	if (CheckHitKey(KEY_INPUT_D) == 0 && CheckHitKey(KEY_INPUT_A) == 0)
	{
		coolx = 0;
	}
	if (CheckHitKey(KEY_INPUT_W) == 0 && CheckHitKey(KEY_INPUT_S) == 0)
	{
		cooly = 0;
	}

	//ì¸ÇÍë÷Ç¶èàóù
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && ch.enable == false && coolch == 0)
	{
		for (int i = 0; i < width*vertical; i++)
		{
			if (cursor.x == block[i].x)
			{
				if (cursor.y == block[i].y)
				{
					ch.c = i;
					ch.enable = true;
					break;
				}
			}
		}
		coolch = 1;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && ch.enable == true && coolch == 0)
	{
		for (int i = 0; i < width * vertical; i++)
		{
			if (cursor.x == block[i].x)
			{
				if (cursor.y == block[i].y)
				{
					//change(cel[ch.no], cel[i]);
					{tempx = block[i].x;
					tempy = block[i].y;
					block[i].x = block[ch.c].x;
					block[i].y = block[ch.c].y;
					block[ch.c].x = tempx;
					block[ch.c].y = tempy; }
					ch.enable = false;
					break;
				}
			}
		}
		coolch = 1;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
	{
		coolch = 0;
	}
}
void drawcursor()
{
	DrawBox(cursor.x * blockscale + startx, cursor.y * blockscale + starty, cursor.x * blockscale + startx + blockscale, cursor.y * blockscale + starty + blockscale, cursor.c, 0);
}