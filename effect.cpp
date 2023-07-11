#include"effect.h"

effect eff[effectnum];
int img[10];

void initeffect(void)
{
	img[0] = LoadGraph("effect_1.png", true);
	img[1] = LoadGraph("effect_2.png", true);
	img[2] = LoadGraph("effect_3.png", true);
	img[3] = LoadGraph("effect_4.png", true);
	img[4] = LoadGraph("effect_5.png", true);
	img[5] = LoadGraph("effect_6.png", true);
	img[6] = LoadGraph("effect_7.png", true);
}
void updateeffect(void)
{
	for (int i = 0; i < effectnum; i++)
	{
		if (eff[i].enable == true)
		{
			eff[i].animeno = eff[i].animeno + 0.1;
			if ((int)(eff[i].animeno) > 7)
			{
				eff[i].enable = false;
			}
		}
	}
}
void draweffect(void)
{
	for (int i = 0; i < effectnum; i++)
	{
		if (eff[i].enable == true)
		{
			int no = eff[i].animeno;
			DrawExtendGraph(eff[i].x * blockscale + startx - 10, eff[i].y * blockscale + starty - 10, eff[i].x * blockscale + blockscale + startx + 10, eff[i].y * blockscale + blockscale + starty + 10, img[no], true);
		}
	}
}
