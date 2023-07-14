#include "DxLib.h"
#include "score.h"
#include "block.h"
#include "cursor.h"

SCORE score[9];
int un[9];
int gorlnum = 30;//–Ú•WŒÂ”
int kazu = 2;//–Ú•Wí—Ş
int oknum = 0;
void initscore()
{
	oknum = 0;
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
		score[i].gorl = gorlnum;
		score[i].enable = false;
		score[i].ok = false;
		score[i].c = GetColor(0, 0, 0);
	}
	for (int i = 0; i < kazu; i++)
	{
		do {
			un[i] = GetRand(8);
		} while (score[un[i]].enable == true);
		score[un[i]].enable = true;
	}
	oknum = 0;
}
void updatescore()
{
	for (int i = 0; i < 9; i++)
	{
		if((score[i].count==score[i].gorl)&& score[i].ok==false)
		{
			score[i].ok = true;
			score[i].c = GetColor(255, 0, 0);
			oknum++;
		}
	}
	if (oknum == kazu)
	{
	gameclearflag = true;		
	}

	if (chengelimit == 0 && gameoverflag == false && gameclearflag == false)
		gameoverflag = true;
}
int Scount;
void drawscore()
{
	Scount = 9;
	for(int i = 0;i<9;i++)
	{
		if(score[i].enable==true)
		{
			Scount--;
			DrawExtendGraph(windowx/2-startx, Scount * 32, 32+ windowx / 2 - startx, Scount * 32+ 32, score[i].img, true);
			DrawExtendFormatString(32 + windowx / 2 - startx, Scount * 32, 1.8, 1.8, score[i].c, "%d/%d", score[i].count, score[i].gorl);
			
		}
	}
}