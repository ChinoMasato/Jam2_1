#include "cursor.h"
#include "block.h"
#include"score.h"


BLOCK cursor;
BLOCK ch;
int tempx;
int tempy;
int coolx;
int cooly;
int coolch;

int chengelimit = 100;
int chengelimits = chengelimit;

//mouse
int mouse = 0;
int mousex = 0;
int mousey = 0;
bool click = false;
int mouseenab = 1;
int mousech = 1;
void initcursor()
{
	chengelimit = 50;
	cursor.x = 0;
	cursor.y = 0;
	cursor.c = GetColor(0, 255, 0);
}
int clicktime = 0;
void updatecursor()
{
	//マウス操作
	mouse = GetMouseInput();
	if (mouseenab == true) 
	{	
		if ((mouse & MOUSE_INPUT_LEFT) != 0)
		{
			if (click == false)
			{
				click = true;
				GetMousePoint(&mousex, &mousey);

				mousex = (mousex - startx) / blockscale;
				mousey = (mousey - starty) / blockscale;
				cursor.x = mousex;
				cursor.y = mousey;
			}
		}
		else
		{
			click = false;
		}
	}
	
		if (mouse & MOUSE_INPUT_RIGHT&& mousech == 1)
		{
			if (mouseenab == 0)
			{
				mouseenab = 1;
				mousech = 0;
			}
			else
			{
				mouseenab = 0;
				mousech = 0;
			}
		}
		if ((mouse & MOUSE_INPUT_RIGHT) !=2)
		{
			mousech = 1;
		}

	//キーボード
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

	//入れ替え処理
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 || click == true)
	{
		change();
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 0 && click ==false)
	{
		coolch = 0;
	}

	if (chengelimit == 0&& gameoverflag ==false &&gameclearflag==false)
		gameoverflag = true;
}
void drawcursor()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155);	
	DrawBox(startx * 2 - 10, Scount * 32-5, startx * 2 + blockscale * 5+30, 32 * 9+5 , GetColor(0, 255, 155), 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 155);
	DrawBox(startx * 2 - 10, Scount * 32 - 5, startx * 2 + blockscale * 5 + 30, 32 * 9 + 5, GetColor(0, 155, 100), 0);
	DrawBox(cursor.x * blockscale + startx, cursor.y * blockscale + starty, cursor.x * blockscale + startx + blockscale, cursor.y * blockscale + starty + blockscale, cursor.c, 0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155);
	if ((ch.enable == true) && (dire % 10 <= 2))
	{
		DrawBox(ch.x * blockscale + startx, ch.y * blockscale + starty, ch.x * blockscale + startx + blockscale, ch.y * blockscale + starty + blockscale, GetColor(255, 255, 0), 1);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 155);
	DrawExtendFormatString(startx*2,32*8, 1.8, 1.8, GetColor(0,0,0), "手数:%d", chengelimit);
}

void change()
{
	if (dire <= 0)
	{
		if (ch.enable == false && coolch == 0)
		{
			for (int i = 0; i < width * vertical; i++)
			{
				if (cursor.x == block[i].x)
				{
					if (cursor.y == block[i].y)
					{
						ch = block[i];
						ch.c = i;
						ch.enable = true;
						break;
					}
				}
			}
			coolch = 1;
		}
		if (ch.enable == true && coolch == 0)
		{
			for (int i = 0; i < width * vertical; i++)
			{
				if (cursor.x == block[i].x)
				{
					if (cursor.y == block[i].y)
					{
						tempx = block[i].x;
						tempy = block[i].y;
						block[i].x = block[ch.c].x;
						block[i].y = block[ch.c].y;
						block[ch.c].x = tempx;
						block[ch.c].y = tempy;
						ch.enable = false;
						chengelimit--;
						break;
					}
				}
			}
			coolch = 1;
		}
	}
}