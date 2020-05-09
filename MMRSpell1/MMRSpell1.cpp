// MMRSpell1.cpp : 定义应用程序的入口点。
//
#include <windows.h>
#include<stdlib.h>//头文件包含rand和srand函数
#include<stdio.h>
#include<time.h>
#include "framework.h"
#include "MMRSpell1.h"
#include "MMSystem.h"

using namespace std;
#include <time.h>
#include <math.h>
#pragma comment(lib,"winmm.lib")     //里面包含 PlaySound函数 用于播放Mav格式 音频
#pragma  comment(lib,"Msimg32.lib") //TransparentBlt函数包含的库文件

#define MAX_LOADSTRING 100
#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1024
#define WINDOW_TITLEBARWIDTH 200



// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

//记忆练习游戏 相关变量

int  a[33] = { 5,10,15,22,33,2,4,6,7,1,20,21,24,14,16,3,8,30,9,29,28,12,25,13 ,17,18,11,23,19,26,27,31,32 };
int credit = 0;
/*
 srand((unsigned)time(NULL));
		   for (int i = 0; i < 33; i++) a[i] = rand() % 33;



		   for (int i = 0; i < 33; i++)
			   for (int j = i + 1; j < 33; j++)
			   {
				   while (a[i] == a[j])a[j] = rand() % 33;
			   }
		   */

int game_x, game_y;
int num = 0;
int read = 0;
bool warn = 1;




//picture resource           背景图片资源               
HBITMAP bmp_Welcome1; // welcome picture no.1
HBITMAP bmp_Bar1;
HBITMAP bmp_Fbg1;
HBITMAP bmp_Bg1;


//alpahbet                  模块一使用的 33个缅甸字母资源

HBITMAP bmp_Ab1;
HBITMAP bmp_Ab2;
HBITMAP bmp_Ab3;
HBITMAP bmp_Ab4;
HBITMAP bmp_Ab5;
HBITMAP bmp_Ab6;
HBITMAP bmp_Ab7;
HBITMAP bmp_Ab8;
HBITMAP bmp_Ab9;
HBITMAP bmp_Ab10;
HBITMAP bmp_Ab11;
HBITMAP bmp_Ab12;
HBITMAP bmp_Ab13;
HBITMAP bmp_Ab14;
HBITMAP bmp_Ab15;
HBITMAP bmp_Ab16;
HBITMAP bmp_Ab17;
HBITMAP bmp_Ab18;
HBITMAP bmp_Ab19;
HBITMAP bmp_Ab20;
HBITMAP bmp_Ab21;
HBITMAP bmp_Ab22;
HBITMAP bmp_Ab23;
HBITMAP bmp_Ab24;
HBITMAP bmp_Ab25;
HBITMAP bmp_Ab26;
HBITMAP bmp_Ab27;
HBITMAP bmp_Ab28;
HBITMAP bmp_Ab29;
HBITMAP bmp_Ab30;
HBITMAP bmp_Ab31;
HBITMAP bmp_Ab32;
HBITMAP bmp_Ab33;

//number                      模块一所使用的 10个缅甸数字资源
HBITMAP bmp_Num0;
HBITMAP bmp_Num1;
HBITMAP bmp_Num2;
HBITMAP bmp_Num3;
HBITMAP bmp_Num4;
HBITMAP bmp_Num5;
HBITMAP bmp_Num6;
HBITMAP bmp_Num7;
HBITMAP bmp_Num8;
HBITMAP bmp_Num9;

//advanced alpahbets           模块二所使用的 图片资源

HBITMAP bmp_F1;
HBITMAP bmp_F2;
HBITMAP bmp_F3;
HBITMAP bmp_F4;
HBITMAP bmp_F5;
HBITMAP bmp_F6;
HBITMAP bmp_F7;
HBITMAP bmp_F8;
HBITMAP bmp_F9;
HBITMAP bmp_F10;
HBITMAP bmp_F11;
HBITMAP bmp_F12;
HBITMAP bmp_F13;
HBITMAP bmp_F14;
HBITMAP bmp_F15;
HBITMAP bmp_F16;
HBITMAP bmp_F17;
HBITMAP bmp_F18;





//button

HBITMAP bmp_Btn1;
HBITMAP bmp_Btn2;
HBITMAP bmp_Btn3;
HBITMAP bmp_Btn4;
HBITMAP bmp_Btn5;
HBITMAP bmp_Next;
HBITMAP bmp_Next2;
HBITMAP bmp_Back;


//Game button
HBITMAP bmp_Start;
HBITMAP bmp_Restart;


//使用vector类 存储button

vector<Button*> buttons;
vector<Button*> zimu;
vector<Button*> numbers;
vector<Button*> Fzimu;

Stage* currentStage = NULL;
bool GameStart = 0;

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此处放置代码。


	// 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MMRSPELL1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MMRSPELL1));

	MSG msg;

	// 主消息循环:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;  //MAKEINTRESOURCEW(IDC_MMRSPELL1); 选择是否启用菜单栏
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindow(szWindowClass, szTitle,
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH + WINDOW_TITLEBARWIDTH,
		WINDOW_HEIGHT + 39,
		nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		InitProgram(hWnd, wParam, lParam);
		break;
		/*  case WM_COMMAND:
		 {
			 int wmId = LOWORD(wParam);
			 // 主窗口上方菜单栏，为了美观取消使用
			switch (wmId)
			 {
			 case IDM_ABOUT:
				 DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				 break;
			 case IDM_EXIT:
				 DestroyWindow(hWnd);
				 break;
			 default:
				 return DefWindowProc(hWnd, message, wParam, lParam);
			 }
		 }
		 break;*/
	case WM_KEYDOWN:
	{
		if (wParam == VK_SPACE || currentStage->stageID == 10)                            //记忆练习模块
		{
			SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
			GameStart = 1;
			MessageBox(NULL, TEXT("根据读音点击字母，点击正确将字母消除,全部消除完便胜利"), TEXT("OK"), MB_OK);

		}
	}
	break;
	case WM_LBUTTONDOWN:
		LButtonDown(hWnd, wParam, lParam);
		break;
	case WM_PAINT:
	{
		Paint(hWnd);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		// 定时器事件     用于实现记忆练习游戏， 可在此扩展 TIMERUPDATE扩展更多小游戏
	{
		if (currentStage->stageID == 10 && GameStart == 1)
		{
			TimerUpdate(hWnd, wParam, lParam);
		}
	}
	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



void InitProgram(HWND hWnd, WPARAM wParam, LPARAM lParam)
{


	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = 1;

	//资源载入内存



//背景资源
	bmp_Welcome1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WELCOME1));
	bmp_Bar1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BAR1));
	bmp_Bg1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BACKGROUND1));
	bmp_Fbg1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_FBG1));


	bmp_Start = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_START));
	bmp_Restart = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RESTART));



	//使用 Button成员函数CreateButton  实例button 并利用Vector 存储
	//Menu Button 模块按钮


	bmp_Btn1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BTN1));
	bmp_Btn2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BTN2));
	bmp_Btn3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BTN3));
	bmp_Btn4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BTN4));
	bmp_Btn5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BTN5));



	Button* FirstButton = CreateButton(BUTTON_BASIC, bmp_Btn1, 180, 90, 10, 125);
	buttons.push_back(FirstButton);
	Button* SecondButton = CreateButton(BUTTON_BASIC2, bmp_Btn2, 180, 90, 10, 125 + 100 * 1);
	buttons.push_back(SecondButton);
	Button* ThirdButton = CreateButton(BUTTON_BASIC3, bmp_Btn3, 180, 90, 10, 125 + 100 * 2);
	buttons.push_back(ThirdButton);
	Button* FourthButton = CreateButton(BUTTON_BASIC4, bmp_Btn4, 180, 90, 10, 125 + 100 * 3);
	buttons.push_back(FourthButton);
	Button* FifthButton = CreateButton(BUTTON_BASIC5, bmp_Btn5, 180, 90, 10, 125 + 100 * 4);
	buttons.push_back(FifthButton);


	//Arrow Button  箭头按钮

	bmp_Next = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NEXT));
	bmp_Back = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BACK));
	bmp_Next2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NEXT2));



	Button* NextButton = CreateButton(BUTTON_NEXT1, bmp_Next, 180, 89, 1000, 650);
	buttons.push_back(NextButton);
	Button* BackButton = CreateButton(BUTTON_BACK1, bmp_Back, 180, 89, 800, 650);
	buttons.push_back(BackButton);
	Button* NextButton2 = CreateButton(BUTTON_NEXT2, bmp_Next2, 180, 89, 1080, 685);
	buttons.push_back(NextButton2);

	//Alphabet Buttons 字母按钮

	bmp_Ab1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB1));
	bmp_Ab2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB2));
	bmp_Ab3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB3));
	bmp_Ab4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB4));
	bmp_Ab5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB5));
	bmp_Ab6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB6));
	bmp_Ab7 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB7));
	bmp_Ab8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB8));
	bmp_Ab9 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB9));
	bmp_Ab10 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB10));
	bmp_Ab11 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB11));
	bmp_Ab12 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AB12));
	bmp_Ab13 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP13));
	bmp_Ab14 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP14));
	bmp_Ab15 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP15));
	bmp_Ab16 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP16));
	bmp_Ab17 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP17));
	bmp_Ab18 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP18));
	bmp_Ab19 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP19));
	bmp_Ab20 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP20));
	bmp_Ab21 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP21));
	bmp_Ab22 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP22));
	bmp_Ab23 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP23));
	bmp_Ab24 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP24));
	bmp_Ab25 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP25));
	bmp_Ab26 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP26));
	bmp_Ab27 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP27));
	bmp_Ab28 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP28));
	bmp_Ab29 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP29));
	bmp_Ab30 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP30));
	bmp_Ab31 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP31));
	bmp_Ab32 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP32));
	bmp_Ab33 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP33));

	Button* Ab1 = CreateButton(BUTTON_AB1, bmp_Ab1, 160, 110, 0, 0);
	zimu.push_back(Ab1);
	Button* Ab2 = CreateButton(BUTTON_AB2, bmp_Ab2, 160, 110, 0, 0);
	zimu.push_back(Ab2);
	Button* Ab3 = CreateButton(BUTTON_AB3, bmp_Ab3, 160, 110, 0, 0);
	zimu.push_back(Ab3);
	Button* Ab4 = CreateButton(BUTTON_AB4, bmp_Ab4, 160, 110, 0, 0);
	zimu.push_back(Ab4);
	Button* Ab5 = CreateButton(BUTTON_AB5, bmp_Ab5, 160, 110, 0, 0);
	zimu.push_back(Ab5);
	Button* Ab6 = CreateButton(BUTTON_AB6, bmp_Ab6, 160, 110, 0, 0);
	zimu.push_back(Ab6);
	Button* Ab7 = CreateButton(BUTTON_AB7, bmp_Ab7, 160, 110, 0, 0);
	zimu.push_back(Ab7);
	Button* Ab8 = CreateButton(BUTTON_AB8, bmp_Ab8, 160, 110, 0, 0);
	zimu.push_back(Ab8);
	Button* Ab9 = CreateButton(BUTTON_AB9, bmp_Ab9, 160, 110, 0, 0);
	zimu.push_back(Ab9);
	Button* Ab10 = CreateButton(BUTTON_AB10, bmp_Ab10, 160, 110, 0, 0);
	zimu.push_back(Ab10);
	Button* Ab11 = CreateButton(BUTTON_AB11, bmp_Ab11, 160, 110, 0, 0);
	zimu.push_back(Ab11);
	Button* Ab12 = CreateButton(BUTTON_AB12, bmp_Ab12, 160, 110, 0, 0);
	zimu.push_back(Ab12);
	Button* Ab13 = CreateButton(BUTTON_AB13, bmp_Ab13, 160, 110, 0, 0);
	zimu.push_back(Ab13);
	Button* Ab14 = CreateButton(BUTTON_AB14, bmp_Ab14, 160, 110, 0, 0);
	zimu.push_back(Ab14);
	Button* Ab15 = CreateButton(BUTTON_AB15, bmp_Ab15, 160, 110, 0, 0);
	zimu.push_back(Ab15);
	Button* Ab16 = CreateButton(BUTTON_AB16, bmp_Ab16, 160, 110, 0, 0);
	zimu.push_back(Ab16);
	Button* Ab17 = CreateButton(BUTTON_AB17, bmp_Ab17, 160, 110, 0, 0);
	zimu.push_back(Ab17);
	Button* Ab18 = CreateButton(BUTTON_AB18, bmp_Ab18, 160, 110, 0, 0);
	zimu.push_back(Ab18);
	Button* Ab19 = CreateButton(BUTTON_AB19, bmp_Ab19, 160, 110, 0, 0);
	zimu.push_back(Ab19);
	Button* Ab20 = CreateButton(BUTTON_AB20, bmp_Ab20, 160, 110, 0, 0);
	zimu.push_back(Ab20);
	Button* Ab21 = CreateButton(BUTTON_AB21, bmp_Ab21, 160, 110, 0, 0);
	zimu.push_back(Ab21);
	Button* Ab22 = CreateButton(BUTTON_AB22, bmp_Ab22, 160, 110, 0, 0);
	zimu.push_back(Ab22);
	Button* Ab23 = CreateButton(BUTTON_AB23, bmp_Ab23, 160, 110, 0, 0);
	zimu.push_back(Ab23);
	Button* Ab24 = CreateButton(BUTTON_AB24, bmp_Ab24, 160, 110, 0, 0);
	zimu.push_back(Ab24);
	Button* Ab25 = CreateButton(BUTTON_AB25, bmp_Ab25, 160, 110, 0, 0);
	zimu.push_back(Ab25);
	Button* Ab26 = CreateButton(BUTTON_AB26, bmp_Ab26, 160, 110, 0, 0);
	zimu.push_back(Ab26);
	Button* Ab27 = CreateButton(BUTTON_AB27, bmp_Ab27, 160, 110, 0, 0);
	zimu.push_back(Ab27);
	Button* Ab28 = CreateButton(BUTTON_AB28, bmp_Ab28, 160, 110, 0, 0);
	zimu.push_back(Ab28);
	Button* Ab29 = CreateButton(BUTTON_AB29, bmp_Ab29, 160, 110, 0, 0);
	zimu.push_back(Ab29);
	Button* Ab30 = CreateButton(BUTTON_AB30, bmp_Ab30, 160, 110, 0, 0);
	zimu.push_back(Ab30);
	Button* Ab31 = CreateButton(BUTTON_AB31, bmp_Ab31, 160, 110, 0, 0);
	zimu.push_back(Ab31);
	Button* Ab32 = CreateButton(BUTTON_AB32, bmp_Ab32, 160, 110, 0, 0);
	zimu.push_back(Ab32);
	Button* Ab33 = CreateButton(BUTTON_AB33, bmp_Ab33, 160, 110, 0, 0);
	zimu.push_back(Ab33);

	//偏旁模块按钮

	bmp_F1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F1));
	bmp_F2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F2));
	bmp_F3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F3));
	bmp_F4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F4));
	bmp_F5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F5));
	bmp_F6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F6));
	bmp_F7 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F7));
	bmp_F8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F8));
	bmp_F9 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F9));
	bmp_F10 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F10));
	bmp_F11 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F11));
	bmp_F12 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F12));
	bmp_F13 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F13));
	bmp_F14 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F14));
	bmp_F15 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F15));
	bmp_F16 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F16));
	bmp_F17 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F17));
	bmp_F18 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_F18));

	Button* F1 = CreateButton(BUTTON_F1, bmp_F1, 480, 110, 200, 0);            //F-2             用在stage
	Fzimu.push_back(F1);
	Button* F2 = CreateButton(BUTTON_F2, bmp_F2, 480, 110, 680, 0);
	Fzimu.push_back(F2);
	Button* F3 = CreateButton(BUTTON_F3, bmp_F3, 480, 110, 200, 110);
	Fzimu.push_back(F3);
	Button* F4 = CreateButton(BUTTON_F4, bmp_F4, 480, 110, 680, 110);
	Fzimu.push_back(F4);
	Button* F5 = CreateButton(BUTTON_F5, bmp_F5, 480, 110, 200, 220);
	Fzimu.push_back(F5);
	Button* F6 = CreateButton(BUTTON_F6, bmp_F6, 480, 110, 680, 220);
	Fzimu.push_back(F6);
	Button* F7 = CreateButton(BUTTON_F7, bmp_F7, 480, 110, 200, 0);            //F-3
	Fzimu.push_back(F7);
	Button* F8 = CreateButton(BUTTON_F8, bmp_F8, 480, 110, 680, 0);
	Fzimu.push_back(F8);
	Button* F9 = CreateButton(BUTTON_F9, bmp_F9, 480, 110, 200, 110);
	Fzimu.push_back(F9);
	Button* F10 = CreateButton(BUTTON_F10, bmp_F10, 480, 110, 680, 110);
	Fzimu.push_back(F10);
	Button* F11 = CreateButton(BUTTON_F11, bmp_F11, 480, 110, 200, 220);
	Fzimu.push_back(F11);
	Button* F12 = CreateButton(BUTTON_F12, bmp_F12, 480, 110, 200, 0);              //F-4
	Fzimu.push_back(F12);
	Button* F13 = CreateButton(BUTTON_F13, bmp_F13, 480, 110, 680, 0);
	Fzimu.push_back(F13);
	Button* F14 = CreateButton(BUTTON_F14, bmp_F14, 480, 110, 200, 110);
	Fzimu.push_back(F14);
	Button* F15 = CreateButton(BUTTON_F15, bmp_F15, 480, 110, 680, 110);
	Fzimu.push_back(F15);
	Button* F16 = CreateButton(BUTTON_F16, bmp_F16, 480, 110, 200, 220);
	Fzimu.push_back(F16);
	Button* F17 = CreateButton(BUTTON_F17, bmp_F17, 480, 110, 680, 220);
	Fzimu.push_back(F17);
	Button* F18 = CreateButton(BUTTON_F18, bmp_F18, 480, 110, 200, 330);
	Fzimu.push_back(F18);





	//number buttons数字按钮




	bmp_Num0 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM0));
	bmp_Num1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM1));
	bmp_Num2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM2));
	bmp_Num3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM3));
	bmp_Num4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM4));
	bmp_Num5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM5));
	bmp_Num6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM6));
	bmp_Num7 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM7));
	bmp_Num8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM8));
	bmp_Num9 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM9));

	Button* Num0 = CreateButton(BUTTON_NUM0, bmp_Num0, 160, 110, 0, 0);
	numbers.push_back(Num0);
	Button* Num1 = CreateButton(BUTTON_NUM1, bmp_Num1, 160, 110, 0, 0);
	numbers.push_back(Num1);
	Button* Num2 = CreateButton(BUTTON_NUM2, bmp_Num2, 160, 110, 0, 0);
	numbers.push_back(Num2);
	Button* Num3 = CreateButton(BUTTON_NUM3, bmp_Num3, 160, 110, 0, 0);
	numbers.push_back(Num3);
	Button* Num4 = CreateButton(BUTTON_NUM4, bmp_Num4, 160, 110, 0, 0);
	numbers.push_back(Num4);
	Button* Num5 = CreateButton(BUTTON_NUM5, bmp_Num5, 160, 110, 0, 0);
	numbers.push_back(Num5);
	Button* Num6 = CreateButton(BUTTON_NUM6, bmp_Num6, 160, 110, 0, 0);
	numbers.push_back(Num6);
	Button* Num7 = CreateButton(BUTTON_NUM7, bmp_Num7, 160, 110, 0, 0);
	numbers.push_back(Num7);
	Button* Num8 = CreateButton(BUTTON_NUM8, bmp_Num8, 160, 110, 0, 0);
	numbers.push_back(Num8);
	Button* Num9 = CreateButton(BUTTON_NUM9, bmp_Num9, 160, 110, 0, 0);
	numbers.push_back(Num9);



	// initial the position of alphabet and numbers
	int num = 0;
	for (int i = 0; i < zimu.size(); i++)
	{
		if (i % 5 == 0)num = 0;
		Button* button = zimu[i];
		button->visible = true;

		button->x = 200 + button->x + num * button->width;
		button->y = button->y + (i / 5) * button->height;

		if (i < numbers.size())
		{
			Button* button2 = numbers[i];
			button2->visible = true;

			button2->x = 200 + button2->x + num * button2->width;
			button2->y = button2->y + (i / 5) * button2->height;


		}



		num++;
	}



}






void Paint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	// TODO: 在此处添加使用 hdc 的任何绘图代码...
	HDC hdc_loadBmp = CreateCompatibleDC(hdc);

	if (currentStage->stageID == 1)       // stage1 主页
	{
		SelectObject(hdc_loadBmp, bmp_Welcome1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	}
	else if (currentStage->stageID == 2)  // A-1           stage2 字母模块-字母页面
	{
		SelectObject(hdc_loadBmp, bmp_Bg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

		for (int i = 0; i < zimu.size(); i++)
		{

			Button* button = zimu[i];

			SelectObject(hdc_loadBmp, button->img);
			BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);


		}
	}
	else if (currentStage->stageID == 3) // A-2           stage3 字母模块-数字页面
	{
		SelectObject(hdc_loadBmp, bmp_Bg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

		for (int i = 0; i < numbers.size(); i++)
		{

			Button* button = numbers[i];

			SelectObject(hdc_loadBmp, button->img);
			BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);


		}

	}
	else if (currentStage->stageID == 4) //F-1                stage4 偏旁模块-常用偏旁说明
	{
		SelectObject(hdc_loadBmp, bmp_Fbg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	}

	else if (currentStage->stageID == 5) // F-2               stage5 偏旁模块2
	{

		SelectObject(hdc_loadBmp, bmp_Bg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
		for (int i = 0; i < 6; i++)
		{

			Button* button = Fzimu[i];

			SelectObject(hdc_loadBmp, button->img);
			BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);


		}

	}
	else if (currentStage->stageID == 6) // F-3             stage6 偏旁模块3
	{

		SelectObject(hdc_loadBmp, bmp_Bg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
		for (int i = 6; i < 11; i++)
		{

			Button* button = Fzimu[i];

			SelectObject(hdc_loadBmp, button->img);
			BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);


		}

	}
	else if (currentStage->stageID == 7) // F-4          stage7 偏旁模块4
	{

		SelectObject(hdc_loadBmp, bmp_Bg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
		for (int i = 11; i < 18; i++)
		{

			Button* button = Fzimu[i];

			SelectObject(hdc_loadBmp, button->img);
			BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);


		}

	}
	else if (currentStage->stageID == 10) // game             stage10 练习游戏模块

	{
		SelectObject(hdc_loadBmp, bmp_Bg1);
		BitBlt(hdc, 200, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

		SelectObject(hdc_loadBmp, bmp_Start);
		TransparentBlt(hdc, 1000, 650, 212, 76, hdc_loadBmp, 0, 0, 212, 76, RGB(255, 255, 255));

		for (int i = 0; i < zimu.size(); i++)
		{

			Button* button = zimu[i];

			SelectObject(hdc_loadBmp, button->img);
			if (button->visible)
				BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);


		}
	}




	SelectObject(hdc_loadBmp, bmp_Bar1);
	BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);


	//forever paint 模块按钮和箭头绘制

	for (int i = 0; i < buttons.size(); i++)
	{
		if (i < 5) {
			Button* button = buttons[i];
			button->visible = true;
			SelectObject(hdc_loadBmp, button->img);
			BitBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, SRCCOPY);
		}
		else if (i == 5)  // paint next arrow
		{
			if (currentStage->stageID == 2 || currentStage->stageID == 4 || currentStage->stageID == 5 || currentStage->stageID == 6) {
				Button* button = buttons[i];
				button->visible = true;
				SelectObject(hdc_loadBmp, bmp_Next);
				TransparentBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, 160, 89, RGB(255, 255, 255));
			}
		}
		else if (i == 6)  // paint back arrow
		{
			if (currentStage->stageID == 3 || currentStage->stageID == 5 || currentStage->stageID == 6 || currentStage->stageID == 7) {
				Button* button = buttons[i];
				button->visible = true;
				SelectObject(hdc_loadBmp, bmp_Back);
				TransparentBlt(hdc, button->x, button->y, button->width, button->height, hdc_loadBmp, 0, 0, 160, 89, RGB(255, 255, 255));
			}
		}
		else if (i == 7)  // paint back arrow
		{
			if (currentStage->stageID == 1 || currentStage->stageID == 101 || currentStage->stageID == 102) {
				Button* button = buttons[i];
				button->visible = true;
				SelectObject(hdc_loadBmp, bmp_Next2);
				TransparentBlt(hdc, 1080, 685, button->width, button->height, hdc_loadBmp, 0, 0, 160, 89, RGB(255, 255, 255));
			}
		}

	}




	// 回收资源所占的内存（非常重要）

	DeleteDC(hdc_loadBmp);

	// 结束绘制





	EndPaint(hWnd, &ps);
}

// 添加按钮函数 ！重要！
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;

	button->visible = false;
	return button;
}


//鼠标点击检测函数！重要！
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
				case BUTTON_BASIC:
				{
					currentStage->stageID = 2;
					// DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);

					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_BASIC2:
				{
					currentStage->stageID = 4;
					InvalidateRect(hWnd, NULL, FALSE);

				}
				break;
				case BUTTON_BASIC3:             //game stage
				{
					currentStage->stageID = 10;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_BASIC4:
				{
					DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				}
				break;
				case BUTTON_BASIC5:
				{
					currentStage->stageID = 1;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NEXT1:
				{
					if (currentStage->stageID == 2)   // A-1
						currentStage->stageID = 3;

					else if (currentStage->stageID == 4)  // F-1
						currentStage->stageID = 5;

					else if (currentStage->stageID == 5) // F-2 
						currentStage->stageID = 6;

					else if (currentStage->stageID == 6) // F-3 
						currentStage->stageID = 7;


					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NEXT2:
				{
					if (currentStage->stageID == 1)
						DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About);


					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_BACK1:
				{

					if (currentStage->stageID == 3) // A-2
						currentStage->stageID = 2;

					else if (currentStage->stageID == 5) // F-2
						currentStage->stageID = 4;

					else if (currentStage->stageID == 6) // F-3
						currentStage->stageID = 5;

					else if (currentStage->stageID == 7) // F-4
						currentStage->stageID = 6;


					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				}
			}
		}

	}

	//关于PlaySound 函数 ， 发现，wav文件路径可以写为绝对路径 即包含C:\\.... 注意多加一个斜杆 ，或者只写文件名 但必须将 wav文件与 exe 放在同一目录下
	//也在载入wav 到程序 resource中 ，改变SND_ASYNC 即可根据 资源ID调用

	if (currentStage->stageID == 2) {

		for (int i = 0; i < zimu.size(); i++)
		{
			Button* button2 = zimu[i];
			if (1)
			{
				if (button2->x <= mouseX
					&& button2->x + button2->width >= mouseX
					&& button2->y <= mouseY
					&& button2->y + button2->height >= mouseY)
				{
					switch (button2->buttonID) {
					case BUTTON_AB1: PlaySound(TEXT("New Recording 2"), NULL, SND_ASYNC); break;
					case BUTTON_AB2: PlaySound(TEXT("New Recording 3"), NULL, SND_ASYNC); break;
					case BUTTON_AB3: PlaySound(TEXT("New Recording 4"), NULL, SND_ASYNC); break;
					case BUTTON_AB4: PlaySound(TEXT("New Recording 5"), NULL, SND_ASYNC); break;
					case BUTTON_AB5: PlaySound(TEXT("New Recording 6"), NULL, SND_ASYNC); break;
					case BUTTON_AB6: PlaySound(TEXT("New Recording 7"), NULL, SND_ASYNC); break;
					case BUTTON_AB7: PlaySound(TEXT("New Recording 8"), NULL, SND_ASYNC); break;
					case BUTTON_AB8: PlaySound(TEXT("New Recording 9"), NULL, SND_ASYNC); break;
					case BUTTON_AB9: PlaySound(TEXT("New Recording 10"), NULL, SND_ASYNC); break;
					case BUTTON_AB10: PlaySound(TEXT("New Recording 11"), NULL, SND_ASYNC); break;
					case BUTTON_AB11: PlaySound(TEXT("New Recording 12"), NULL, SND_ASYNC); break;
					case BUTTON_AB12: PlaySound(TEXT("New Recording 13"), NULL, SND_ASYNC); break;
					case BUTTON_AB13: PlaySound(TEXT("New Recording 14"), NULL, SND_ASYNC); break;
					case BUTTON_AB14: PlaySound(TEXT("New Recording 15"), NULL, SND_ASYNC); break;
					case BUTTON_AB15: PlaySound(TEXT("New Recording 16"), NULL, SND_ASYNC); break;
					case BUTTON_AB16: PlaySound(TEXT("New Recording 17"), NULL, SND_ASYNC); break;
					case BUTTON_AB17: PlaySound(TEXT("New Recording 18"), NULL, SND_ASYNC); break;
					case BUTTON_AB18: PlaySound(TEXT("New Recording 19"), NULL, SND_ASYNC); break;
					case BUTTON_AB19: PlaySound(TEXT("New Recording 20"), NULL, SND_ASYNC); break;
					case BUTTON_AB20: PlaySound(TEXT("New Recording 21"), NULL, SND_ASYNC); break;
					case BUTTON_AB21: PlaySound(TEXT("New Recording 22"), NULL, SND_ASYNC); break;
					case BUTTON_AB22: PlaySound(TEXT("New Recording 23"), NULL, SND_ASYNC); break;
					case BUTTON_AB23: PlaySound(TEXT("New Recording 24"), NULL, SND_ASYNC); break;
					case BUTTON_AB24: PlaySound(TEXT("New Recording 25"), NULL, SND_ASYNC); break;
					case BUTTON_AB25: PlaySound(TEXT("New Recording 26"), NULL, SND_ASYNC); break;
					case BUTTON_AB26: PlaySound(TEXT("New Recording 27"), NULL, SND_ASYNC); break;
					case BUTTON_AB27: PlaySound(TEXT("New Recording 28"), NULL, SND_ASYNC); break;
					case BUTTON_AB28: PlaySound(TEXT("New Recording 29"), NULL, SND_ASYNC); break;
					case BUTTON_AB29: PlaySound(TEXT("New Recording 30"), NULL, SND_ASYNC); break;
					case BUTTON_AB30: PlaySound(TEXT("New Recording 31"), NULL, SND_ASYNC); break;
					case BUTTON_AB31: PlaySound(TEXT("New Recording 32"), NULL, SND_ASYNC); break;
					case BUTTON_AB32: PlaySound(TEXT("New Recording 33"), NULL, SND_ASYNC); break;
					case BUTTON_AB33: PlaySound(TEXT("New Recording 34"), NULL, SND_ASYNC); break;

					}


				}
			}
		}
	}


	if (currentStage->stageID == 3) {
		for (int i = 0; i < numbers.size(); i++)
		{
			Button* button2 = numbers[i];
			if (button2->visible)
			{
				if (button2->x <= mouseX
					&& button2->x + button2->width >= mouseX
					&& button2->y <= mouseY
					&& button2->y + button2->height >= mouseY)
				{
					switch (button2->buttonID) {
					case BUTTON_NUM1: PlaySound(TEXT("Num1"), NULL, SND_ASYNC); break;
					case BUTTON_NUM2: PlaySound(TEXT("Num2"), NULL, SND_ASYNC); break;
					case BUTTON_NUM3: PlaySound(TEXT("Num3"), NULL, SND_ASYNC); break;
					case BUTTON_NUM4: PlaySound(TEXT("Num4"), NULL, SND_ASYNC); break;
					case BUTTON_NUM5: PlaySound(TEXT("Num5"), NULL, SND_ASYNC); break;
					case BUTTON_NUM6: PlaySound(TEXT("Num6"), NULL, SND_ASYNC); break;
					case BUTTON_NUM7: PlaySound(TEXT("Num7"), NULL, SND_ASYNC); break;
					case BUTTON_NUM8: PlaySound(TEXT("Num8"), NULL, SND_ASYNC); break;
					case BUTTON_NUM9: PlaySound(TEXT("Num9"), NULL, SND_ASYNC); break;
					case BUTTON_NUM0: PlaySound(TEXT("Num0"), NULL, SND_ASYNC); break;


					}


				}
			}
		}
	}

	if (currentStage->stageID == 5) {
		for (int i = 0; i < 6; i++)
		{
			Button* button2 = Fzimu[i];

			if (button2->x <= mouseX
				&& button2->x + button2->width >= mouseX
				&& button2->y <= mouseY
				&& button2->y + button2->height >= mouseY)
			{
				switch (button2->buttonID) {
				case BUTTON_F1: PlaySound(TEXT("New Recording 35"), NULL, SND_ASYNC); break;
				case BUTTON_F2: PlaySound(TEXT("New Recording 36"), NULL, SND_ASYNC); break;
				case BUTTON_F3: PlaySound(TEXT("New Recording 37"), NULL, SND_ASYNC); break;
				case BUTTON_F4: PlaySound(TEXT("New Recording 38"), NULL, SND_ASYNC); break;
				case BUTTON_F5: PlaySound(TEXT("New Recording 39"), NULL, SND_ASYNC); break;
				case BUTTON_F6: PlaySound(TEXT("New Recording 40"), NULL, SND_ASYNC); break;


				}


			}

		}
	}
	if (currentStage->stageID == 6) {
		for (int i = 6; i < 11; i++)
		{
			Button* button2 = Fzimu[i];

			if (button2->x <= mouseX
				&& button2->x + button2->width >= mouseX
				&& button2->y <= mouseY
				&& button2->y + button2->height >= mouseY)
			{
				switch (button2->buttonID) {
				case BUTTON_F7: PlaySound(TEXT("New Recording 41"), NULL, SND_ASYNC); break;
				case BUTTON_F8: PlaySound(TEXT("New Recording 42"), NULL, SND_ASYNC); break;
				case BUTTON_F9: PlaySound(TEXT("New Recording 43"), NULL, SND_ASYNC); break;
				case BUTTON_F10: PlaySound(TEXT("New Recording 44"), NULL, SND_ASYNC); break;
				case BUTTON_F11: PlaySound(TEXT("New Recording 45"), NULL, SND_ASYNC); break;


				}


			}

		}
	}

	if (currentStage->stageID == 7) {
		for (int i = 11; i < 18; i++)
		{
			Button* button2 = Fzimu[i];

			if (button2->x <= mouseX
				&& button2->x + button2->width >= mouseX
				&& button2->y <= mouseY
				&& button2->y + button2->height >= mouseY)
			{
				switch (button2->buttonID) {
				case BUTTON_F12: PlaySound(TEXT("New Recording 46"), NULL, SND_ASYNC); break;
				case BUTTON_F13: PlaySound(TEXT("New Recording 47"), NULL, SND_ASYNC); break;
				case BUTTON_F14: PlaySound(TEXT("New Recording 48"), NULL, SND_ASYNC); break;
				case BUTTON_F15: PlaySound(TEXT("New Recording 49"), NULL, SND_ASYNC); break;
				case BUTTON_F16: PlaySound(TEXT("New Recording 50"), NULL, SND_ASYNC); break;
				case BUTTON_F17: PlaySound(TEXT("New Recording 51"), NULL, SND_ASYNC); break;
				case BUTTON_F18: PlaySound(TEXT("New Recording 52"), NULL, SND_ASYNC); break;

				}


			}

		}


	}


	if (currentStage->stageID == 10)
	{



		for (int i = 0; i < zimu.size(); i++)
		{
			Button* button2 = zimu[i];
			if (button2->visible)
			{
				if ((button2->x <= mouseX
					&& button2->x + button2->width >= mouseX
					&& button2->y <= mouseY
					&& button2->y + button2->height >= mouseY) && i + 1 == a[read])
				{

					button2->visible = 0;


					read++;
					credit++;
					GameStart = 1;
				}
			}
		}

	}


}


// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

	if (credit == 33)
	{
		GameStart = 0;
		credit = 0;
		MessageBox(NULL, TEXT("YOU WIN"), TEXT("OK"), MB_OK);
	}

	if (GameStart == 1) {


		GameStart = 0;


		switch (a[read]) {
		case 1: PlaySound(TEXT("New Recording 2"), NULL, SND_ASYNC); break;
		case 2: PlaySound(TEXT("New Recording 3"), NULL, SND_ASYNC); break;
		case 3: PlaySound(TEXT("New Recording 4"), NULL, SND_ASYNC); break;
		case 4: PlaySound(TEXT("New Recording 5"), NULL, SND_ASYNC); break;
		case 5: PlaySound(TEXT("New Recording 6"), NULL, SND_ASYNC); break;
		case 6: PlaySound(TEXT("New Recording 7"), NULL, SND_ASYNC); break;
		case 7: PlaySound(TEXT("New Recording 8"), NULL, SND_ASYNC); break;
		case 8: PlaySound(TEXT("New Recording 9"), NULL, SND_ASYNC); break;
		case 9: PlaySound(TEXT("New Recording 10"), NULL, SND_ASYNC); break;
		case 10: PlaySound(TEXT("New Recording 11"), NULL, SND_ASYNC); break;
		case 11: PlaySound(TEXT("New Recording 12"), NULL, SND_ASYNC); break;
		case 12: PlaySound(TEXT("New Recording 13"), NULL, SND_ASYNC); break;
		case 13: PlaySound(TEXT("New Recording 14"), NULL, SND_ASYNC); break;
		case 14: PlaySound(TEXT("New Recording 15"), NULL, SND_ASYNC); break;
		case 15: PlaySound(TEXT("New Recording 16"), NULL, SND_ASYNC); break;
		case 16: PlaySound(TEXT("New Recording 17"), NULL, SND_ASYNC); break;
		case 17: PlaySound(TEXT("New Recording 18"), NULL, SND_ASYNC); break;
		case 18: PlaySound(TEXT("New Recording 19"), NULL, SND_ASYNC); break;
		case 19: PlaySound(TEXT("New Recording 20"), NULL, SND_ASYNC); break;
		case 20: PlaySound(TEXT("New Recording 21"), NULL, SND_ASYNC); break;
		case 21: PlaySound(TEXT("New Recording 22"), NULL, SND_ASYNC); break;
		case 22: PlaySound(TEXT("New Recording 23"), NULL, SND_ASYNC); break;
		case 23: PlaySound(TEXT("New Recording 24"), NULL, SND_ASYNC); break;
		case 24: PlaySound(TEXT("New Recording 25"), NULL, SND_ASYNC); break;
		case 25: PlaySound(TEXT("New Recording 26"), NULL, SND_ASYNC); break;
		case 26: PlaySound(TEXT("New Recording 27"), NULL, SND_ASYNC); break;
		case 27: PlaySound(TEXT("New Recording 28"), NULL, SND_ASYNC); break;
		case 28: PlaySound(TEXT("New Recording 29"), NULL, SND_ASYNC); break;
		case 29: PlaySound(TEXT("New Recording 30"), NULL, SND_ASYNC); break;
		case 30: PlaySound(TEXT("New Recording 31"), NULL, SND_ASYNC); break;
		case 31: PlaySound(TEXT("New Recording 32"), NULL, SND_ASYNC); break;
		case 32: PlaySound(TEXT("New Recording 33"), NULL, SND_ASYNC); break;
		case 33: PlaySound(TEXT("New Recording 34"), NULL, SND_ASYNC); break;
		}

	}



	InvalidateRect(hWnd, NULL, FALSE);
}