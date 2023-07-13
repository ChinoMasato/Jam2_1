#include"background.h"

int titleimg;
int tutorialimg;
int gameimg;
int gameclearimg;
int gameoverimg;
int Cimg[2];
bool draweat;
int eattime;

void initimg(void)
{
	titleimg = LoadGraph("Puzzle&Foods.png", true);
	tutorialimg = LoadGraph("tutorial.png", true);
	gameimg = LoadGraph("game.png", true);
	gameclearimg = LoadGraph("gameclear.png", true);
	gameoverimg = LoadGraph("gameover.png", true);
	Cimg[0] = LoadGraph("C1.png", true);
	Cimg[1] = LoadGraph("C2.png", true);
	draweat = false;
	eattime = 500;
}
void drawtitle(void)
{
	DrawExtendGraph(0, 0, windowx, windowy, titleimg, true);
}
void drawtutorial(void)
{
	DrawExtendGraph(0, 0, windowx, windowy, tutorialimg, true);
}
void drawgameimg(void)
{
	DrawExtendGraph(0, 0, windowx, windowy, gameimg, true);
}
void drawgameclear(void)
{
	DrawExtendGraph(0, 0, windowx, windowy, gameclearimg, true);
	DrawBox(0, 0, 100, 100, GetColor(255, 255, 255), true);

}
void drawgameover(void)
{
	DrawExtendGraph(0, 0, windowx, windowy, gameoverimg, true);
}
void drawC(void)
{
	if (draweat == false)
	{
		DrawExtendGraph(windowx / 2, windowy / 10, windowx, windowy/1.75, Cimg[0], true);
	}
	else if (draweat == true)
	{
		DrawExtendGraph(windowx / 2, windowy / 10, windowx, windowy/1.75, Cimg[1], true);
		if(eattime>0)
		{
			eattime--;
		}
	}
	if (eattime <= 0)
	{
		draweat = false;
		eattime = 500;
	}
}