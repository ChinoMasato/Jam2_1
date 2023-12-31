﻿#include"DxLib.h"
#include"block.h"
#include"game.h"
#include "cursor.h"
#include"background.h"
#include"score.h"

enum gamescene
{
	start,
	title,
	tutorial,
	game
};

int scene = title;
bool pushenter;
bool tutorialflag = true;
int alpha = 255;

bool bgmc=false;
bool bgmo=false;

void init(void);
void updatetitle(void);
void updatetutorial(void);
void update(void);
void draw(void);

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//ログ無効
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(windowx, windowy, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ

	init();

	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (scene == start)
		{
			init();
			scene = title;
		}
		else if (scene == title)
		{
			updatetitle();
		}
		else if (scene == tutorial)
		{
			updatetutorial();
		}
		else if (scene == game)
		{
			update();

			if (gameclearflag == true)
			{
				if (bgmc == false)
				{
					PlayMusic("tousen.mp3", DX_PLAYTYPE_BACK);
					bgmc = true;
				}
				drawgameclear();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
				{
					pushenter = true;
					bgmc = false;
					scene = start;
				}
				else if (CheckHitKey(KEY_INPUT_RETURN) == 0 )
				{
					pushenter = false;
				}
			}
			if (gameoverflag == true)
			{
				if (bgmo == false)
				{
					PlayMusic("zannense.mp3", DX_PLAYTYPE_BACK);
					bgmo = true;
				}
				drawgameover();
				if ((CheckHitKey(KEY_INPUT_RETURN) == 1) && pushenter == false)
				{
					pushenter = true;
					bgmo = false;
					scene = start;
				}
				else if (CheckHitKey(KEY_INPUT_RETURN) == 0)
				{
					pushenter = false;
				}
			}
		}
		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
void init(void)
{
	alpha = 255;
	pushenter = false;
	initgame();
	initblock();
	initscore();
	initcursor();
	initimg();
	initeffect();
	PlayMusic("Loquet_Park.mp3", DX_PLAYTYPE_LOOP);
}
void updatetitle(void)
{
	drawtitle();
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
	{
		pushenter = true;
		if (tutorialflag == true)
		{
			scene = tutorial;
			PlaySoundMem(startse, DX_PLAYTYPE_BACK);
		}
		else if (tutorialflag == false)
		{
			scene = game;
		}
	}
	else if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		pushenter = false;
	}
}
void updatetutorial(void)
{
	drawtutorial();
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
	{
		PlayMusic("There_are_days_like_that.mp3", DX_PLAYTYPE_LOOP);
		pushenter = true;
		scene = game;
		PlaySoundMem(startse, DX_PLAYTYPE_BACK);
	}
	else if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		pushenter = false;
	}
}
void update(void)
{
	updatecursor();
	updateblock();
	updatescore();
	updategame();
	updateeffect();
	draw();
}
void draw(void)
{
	drawcursor();
	if (alpha > 0)
	{
		drawgameimg();
		DrawExtendGraph(windowx / 2, windowy / 10, windowx, windowy / 1.75, Cimg[0], true);
		drawgame();
		drawblock();
		drawcursor();
		drawscore();
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		if (tutorialflag == true)
		{
			DrawExtendGraph(0, 0, windowx, windowy, tutorialimg, true);
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		alpha -= 3;
	}
	else
	{
		drawgameimg();
		drawC();
		drawgame();
		drawblock();
		drawcursor();
		drawscore();
		draweffect();
	}
}