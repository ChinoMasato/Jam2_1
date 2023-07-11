#include"game.h"
#include "block.h"

int blocknum;
bool gameclearflag;
bool gameoverflag;

void initgame(void)
{
	blocknum = width * vertical;
	gameclearflag = false;
	gameoverflag = false;
}
int score = 0;
int tempx2;
int tempy2;
int R2;
int ready = 15;
void updategame(void)
{
	if (dire <= 0|| ready >0)
	{
		for (int i = 0; i < blocknum; i++)
		{
			if (block[i].type == type0)
			{
				for (int j = 0; j < blocknum; j++)
				{
					if (block[i].x == block[j].x)
					{
						if (block[i].y > block[j].y)
						{
							block[j].y++;
							//break;
						}
					}
				}
				//block[i].type = block[i].types;
				R2 = GetRand(7) + 1;
				if (R2 == 1)
				{
					block[i].type = type1;
					block[i].c = GetColor(255, 255, 255);
				}
				if (R2 == 2)
				{
					block[i].type = type2;
					block[i].c = GetColor(255, 255, 0);
				}
				if (R2 == 3)
				{
					block[i].type = type3;
					block[i].c = GetColor(255, 0, 255);
				}
				if (R2 == 4)
				{
					block[i].type = type4;
					block[i].c = GetColor(0, 255, 255);
				}
				if (R2 == 5)
				{
					block[i].type = type5;
					block[i].c = GetColor(255, 0, 0);
				}
				if (R2 == 6)
				{
					block[i].type = type6;
					block[i].c = GetColor(155, 0, 0);
				}
				if (R2 == 7)
				{
					block[i].type = type7;
					block[i].c = GetColor(0, 155, 0);
				}
				if (R2 == 8)
				{
					block[i].type = type8;
					block[i].c = GetColor(0, 0, 155);
				}
				if(ready<=0)
				score += 100;
				block[i].y = 0;
			}
		}
	}
	ready--;
}
void drawgame(void)
{
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", score);
}