#include"DxLib.h"
#include"block.h"
#include"game.h"
#include "cursor.h"

enum gamescene
{
	title,
	tutorial,
	game
};

int scene = title;
bool pushenter;

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
	SetGraphMode(600, 800, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ

	init();

	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (scene == title)
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

			}
			if (gameoverflag == true)
			{

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
	pushenter = false;
	initgame();
	initblock();
	initcursor();
}
void updatetitle(void)
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1&& pushenter == false)
	{
		pushenter = true;
		scene = tutorial;
	}
}
void updatetutorial(void)
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
	{
		pushenter = true;
		scene = game;
	}
	else if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		pushenter = false;
	}
}
void update(void)
{
	updategame();
	updateblock();
	updatecursor();
	draw();
}
void draw(void)
{
	drawgame();
	drawblock();
	drawcursor();
}