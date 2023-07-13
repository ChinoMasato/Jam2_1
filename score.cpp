#include "DxLib.h"
#include "score.h"
#include "block.h"

SCORE score[9];
int un;
void initscore()
{
	for (int i = 0; i < 9; i++)
	{
		score[i].count = 0;
		if ((i + 1) == 1)
			score[i].type = type1;
		if ((i + 1) == 2)
			score[i].type = type2;
		if ((i + 1) == 3)
			score[i].type = type3;
		if ((i + 1) == 4)
			score[i].type = type4;
		if ((i + 1) == 5)
			score[i].type = type5;
		if ((i + 1) == 6)
			score[i].type = type6;
		if ((i + 1) == 7)
			score[i].type = type7;
		if ((i + 1) == 8)
			score[i].type = type8;
		if ((i + 1) == 9)
			score[i].type = type9;
		score[i].img = blockimg[i];
		score[i].gorl = 30;
		score[i].enable = false;
		score[i].c = GetColor(0, 0, 0);
	}

	score[un].enable = true;
}
void updatescore()
{
	for (int i = 0; i < 9; i++)
	{
		if(score[i].count==score[i].gorl&& score[i].ok==false)
		{
			score[i].ok = true;
			score[i].c = GetColor(255, 0, 0);
		}
	}
}
int Scount = 0;
void drawscore()
{
	Scount = 0;
	for(int i = 0;i<9;i++)
	{
		if(score[i].enable==true)
		{
			DrawExtendGraph(0, Scount * 32, 32, Scount * 32+32, score[i].img, true);
			DrawExtendFormatString(32, Scount * 32, 1.7, 1.7, GetColor(0, 0, 0), "%d/%d", score[i].count, score[i].gorl);
			Scount++;
		}
	}
}