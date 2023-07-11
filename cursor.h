#pragma once
#include "block.h"
extern BLOCK cursor;
extern int mouse ;
extern bool mouseflag ;
extern int mousex ;
extern int mousey ;
extern bool click ;
void initcursor();
void updatecursor();
void drawcursor();
void change();
