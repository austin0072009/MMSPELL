#pragma once

#include "resource.h"

//ID defination

#define BUTTON_BASIC 1001
#define BUTTON_BASIC2 1102
#define BUTTON_BASIC3 1103
#define BUTTON_BASIC4 1104
#define BUTTON_BASIC5 1105
#define BUTTON_NEXT1 1106
#define BUTTON_BACK1 1107
#define BUTTON_NEXT2 1108

#define BUTTON_AB1   1002
#define BUTTON_AB2   1003
#define BUTTON_AB3   1004
#define BUTTON_AB4   1005
#define BUTTON_AB5   1006
#define BUTTON_AB6   1007
#define BUTTON_AB7   1008
#define BUTTON_AB8   1009
#define BUTTON_AB9   1010
#define BUTTON_AB10  1011
#define BUTTON_AB11  1012
#define BUTTON_AB12  1013
#define BUTTON_AB13  1014
#define BUTTON_AB14  1015
#define BUTTON_AB15  1016
#define BUTTON_AB16  1017
#define BUTTON_AB17  1018
#define BUTTON_AB18  1019
#define BUTTON_AB19  1020
#define BUTTON_AB20  1021
#define BUTTON_AB21  1022
#define BUTTON_AB22  1023
#define BUTTON_AB23  1024
#define BUTTON_AB24  1025
#define BUTTON_AB25  1026
#define BUTTON_AB26  1027
#define BUTTON_AB27  1028
#define BUTTON_AB28  1029
#define BUTTON_AB29  1030
#define BUTTON_AB30  1031
#define BUTTON_AB31  1032
#define BUTTON_AB32  1033
#define BUTTON_AB33  1034

#define BUTTON_NUM0  1035
#define BUTTON_NUM1  1036
#define BUTTON_NUM2  1037
#define BUTTON_NUM3  1038
#define BUTTON_NUM4  1039
#define BUTTON_NUM5  1040
#define BUTTON_NUM6  1041
#define BUTTON_NUM7  1042
#define BUTTON_NUM8  1043
#define BUTTON_NUM9  1044

#define BUTTON_F1    1045
#define BUTTON_F2    1046
#define BUTTON_F3    1047
#define BUTTON_F4    1048
#define BUTTON_F5    1049
#define BUTTON_F6    1050
#define BUTTON_F7    1051
#define BUTTON_F8    1052
#define BUTTON_F9    1053
#define BUTTON_F10    1054
#define BUTTON_F11    1055
#define BUTTON_F12    1056
#define BUTTON_F13    1057
#define BUTTON_F14    1058
#define BUTTON_F15    1059
#define BUTTON_F16    1060
#define BUTTON_F17    1061
#define BUTTON_F18    1062

#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		500	//默认计时器刷新间隔的毫秒数



int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;


//用于场景切换
struct Stage
{
	int stageID;
	HBITMAP bg;
	int timeCountDown;
	bool timerOn;

};

//用于绘制各类按钮和图标
struct Button
{
	int buttonID;
	bool visible;
	HBITMAP img;
	int x;
	int y;
	int height;
	int width;
};

//massage dealing

void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

//初始载入资源，创建按钮
void InitProgram(HWND hWnd, WPARAM wParam, LPARAM lParam);

//绘图函数
void Paint(HWND hWnd);

//创建按钮函数，避免重复操作，节省大量工作
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);