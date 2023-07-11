#include"background.h"

int titleimg;
int tutorialimg;
int gameimg;
int gameclearimg;
int gameoverimg;

void initimg(void)
{
	titleimg = LoadGraph("title.png", true);
	tutorialimg = LoadGraph("tutorial.png", true);
	gameimg = LoadGraph("game.png", true);
	gameclearimg = LoadGraph("gameclear.png", true);
	gameoverimg = LoadGraph("gameover.png", true);
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
}
void drawgameover(void)
{
	DrawExtendGraph(0, 0, windowx, windowy, gameoverimg, true);
}