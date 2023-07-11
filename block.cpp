#include"block.h"
#include "cursor.h"

BLOCK block[width * vertical];

/*int mouse = 0;
bool mouseflag = false;
int mousex = 0;
int mousey = 0;
bool click = false;*/

int dire = 0;

int blockimg[5];

void initblock(void)
{
	int countrow = 0;
	int nextrow = 0;
	int R;
	for (int i = 0; i < blocknum; i++)
	{
		R = GetRand(7) + 1;
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
		if (R == 6)
		{
			block[i].type = type6;
			block[i].c = GetColor(155, 0, 0);
		}
		if (R == 7)
		{
			block[i].type = type7;
			block[i].c = GetColor(0, 155, 0);
		}
		if (R == 8)
		{
			block[i].type = type8;
			block[i].c = GetColor(0, 0, 155);
		}
		block[i].x = countrow;
		block[i].y = nextrow;
		block[i].enable = true;
		block[i].erase = false;
		block[i].no = i;
		block[i].fall = 0;
		countrow += 1;
		if (countrow == width)
		{
			countrow = 0;
			nextrow += 1;
		}
	}
	blockimg[0] = LoadGraph("peanut.png", true);
	blockimg[1] = LoadGraph("kinoko.png", true);
	blockimg[2] = LoadGraph("kabu.png", true);
	blockimg[3] = LoadGraph("sayaendo.png", true);
	blockimg[4] = LoadGraph("edamame.png", true);
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
	//カウント関数の実行
	for (int i = 0; i < width * vertical; i++){
		//チェック済みのリセット
		for (int j = 0; j < width * vertical; j++){
			block[j].checkedx = block[j].checkedy = block[j].checked = 0;
		}
		block[i].countx = block[i].county = block[i].count = 0;
		//x軸,y軸,連なる同じタイプをカウント
		block[i].countx = countx(block[i].x, block[i].y, block[i].type, block[i].countx);
		block[i].county = county(block[i].x, block[i].y, block[i].type, block[i].county);
		block[i].count = count(block[i].x, block[i].y, block[i].type, block[i].count);
	}
	//消す処理
	for (int i = 0; i < width * vertical; i++)
	{
		if (block[i].countx >= erasenum)
			erasex(block[i].x, block[i].y, block[i].type);
		if (block[i].county >= erasenum)
			erasey(block[i].x, block[i].y, block[i].type);
		if (block[i].count >= erasenum)
		{
			//erase(block[i].x, block[i].y, block[i].type);
		}
	}
	for (int i = 0; i < width * vertical; i++) 
	{
		if (block[i].erase == true) 
		{
			//block[i].enable = false;
			block[i].erase = false;
			block[i].type = type0;
			dire = 60;
		}
	}
	dire--;
	
}
void drawblock(void)
{

	for (int i = 0; i < blocknum; i++)
	{
		if (block[i].enable == true&&block[i].type!=type0)
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

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", dire);
}
int no;
int countx(int _x,int _y,BLOCKTYPE _type, int _count)
{
	for (int a = 0; a < width * vertical; a++)
	{
		if (_x == block[a].x)
		{
			if (_y == block[a].y)
			{
				no = block[a].no;
				break;
			}
		}
	}
	if ((_x < 0 )|| (_x >= width )|| block[no].checkedx ||( block[no].type != _type) || (_type == type0) || (block[no].erase == true))
		return _count;
	_count++;
	block[no].checkedx = true;

	_count = countx(_x-1, _y, _type, _count);
	_count = countx(_x+1, _y, _type, _count);
}

void erasex(int _x, int _y, BLOCKTYPE _type)
{
	for (int a = 0; a < width * vertical; a++)
	{
		if (_x == block[a].x)
		{
			if (_y == block[a].y)
			{
				no = block[a].no;
				break;
			}
		}
	}
	if ((_x < 0) || (_x >= width)|| (block[no].type != _type)|| (_type ==type0)|| (block[no].erase == true))
		return;

	block[no].erase = true;

	erasex(_x-1, _y, _type); 
	erasex(_x+1, _y, _type);
}

int county(int _x, int _y, BLOCKTYPE _type, int _count)
{
	for (int a = 0; a < width * vertical; a++)
	{
		if (_x == block[a].x)
		{
			if (_y == block[a].y)
			{
				no = block[a].no;
				break;
			}
		}
	}
	if ((_y < 0) || (_y >= vertical) || block[no].checkedy || (_type == type0) || (block[no].type != _type)|| (block[no].erase == true))
		return _count;
	_count++;
	block[no].checkedy = true;

	_count = county(_x , _y-1, _type, _count);
	_count = county(_x , _y+1, _type, _count);
}


void erasey(int _x, int _y, BLOCKTYPE _type)
{
	for (int a = 0; a < width * vertical; a++)
	{
		if (_x == block[a].x)
		{
			if (_y == block[a].y)
			{
				no = block[a].no;
				break;
			}
		}
	}
	if ((_y < 0) || (_y >= vertical) || (block[no].type != _type) || (_type == type0) || (block[no].erase == true))
		return;
	block[no].erase = true;

	erasey(_x, _y-1, _type);
	erasey(_x, _y+1, _type);
}


int count(int _x, int _y, BLOCKTYPE _type, int _count)
{
	for (int a = 0; a < width * vertical; a++)
	{
		if (_x == block[a].x)
		{
			if (_y == block[a].y)
			{
				no = block[a].no;
				break;
			}
		}
	}
	if ((_x < 0) || (_x >= width) || (_y < 0) || (_y >= vertical) || (_type == type0) || block[no].checked || (block[no].type != _type) || (block[no].erase == true))
		return _count;
	_count++;
	block[no].checked = true;

	_count = count(_x - 1, _y, _type, _count);
	_count = count(_x , _y + 1, _type, _count);
	_count = count(_x + 1, _y , _type, _count);
	_count = count(_x, _y - 1, _type, _count);
}


void erase(int _x, int _y, BLOCKTYPE _type)
{
	for (int a = 0; a < width * vertical; a++)
	{
		if (_x == block[a].x)
		{
			if (_y == block[a].y)
			{
				no = block[a].no;
				break;
			}
		}
	}
	if ((_x < 0) || (_x >= width) || (_y < 0) || (_y >= vertical) || (_type == type0) || (block[no].type != _type) || (block[no].erase == true))
		return;
	block[no].erase = true;

	erase(_x - 1, _y, _type);
	erase(_x , _y+ 1, _type); 
	erase(_x + 1, _y, _type);
	erase(_x , _y- 1, _type);
}
