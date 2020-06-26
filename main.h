#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>
#pragma comment (lib, "winmm.lib")

#define WIDTH 1280
#define HEIGHT 720

#define STAGE0 -10
#define STAGE0_STORY -9
#define STAGE9 -8
#define STAGE9_STORY -7
#define SHOPHIGHPOTION -4
#define SHOPLOWPOTION -3
#define SHOPLEVEL -2
#define SHOP -1
#define MAINSCREEN 0
#define NEWGAME 1
#define LOADGAME 2
#define CREDIT 3
#define MENU 4
#define TUTORIAL 5
#define STAGE1 6
#define STAGE1_STORY 16
#define STAGE2_STORY 7
#define STAGE2 8
#define STAGE3_STORY 9
#define STAGE3 10
#define MAP 11
#define STAGE4 12
#define STAGE5 13
#define GAMEOVER 14
#define STAGE4_STORY 15
#define STAGE8 -6
#define STAGE8_STORY -5
#define STAGE6 18
#define STAGE6_STORY 17
#define STAGE7 19
#define STAGE7_STORY 20
#define NSTAGE1 21
#define NSTAGE1_STORY 22
#define NSTAGE2 23
#define NSTAGE2_STORY 24
#define LASTSTAGE 25
#define ENDSTORY 26

void gotoxy(int, int);
void ClearCursor();
void intro();
HWND getConsoleWindowHandle();
int GetDPI(HWND);
void GetBMP(HDC, HDC, HBITMAP);
void paint(HWND, int, HBITMAP, int, int);
int be_input();
int get_input(WORD*, COORD*);
void mouseenable();
void ui(int, int, int, int, int, int, int, int, int, int);
int keyboard();
void potion1(int*, int*, int*);
void potion2(int*, int*, int*);
void stopmusic();

HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치

DWORD mode;
WORD key;
COORD pos;

int event;        // 마우스 이벤트에 이용
int x;            // 마우스의 x좌표 저장소
int y;            // 마우스의 y좌표 저장소


void gotoxy(int x, int y) { // x, y 좌표로 이동하는 함수
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void ClearCursor() { // 마우스 커서를 없애는 함수
	CONSOLE_CURSOR_INFO c;
	c.dwSize = 1;
	c.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void intro() { // 콘솔 크기 및 타이틀을 설정하는 함수
	system("cls");
	system("mode con cols=128 lines=36 | title Overlord");
}

HWND getConsoleWindowHandle() { // 이미지 관련 함수 
	WCHAR title[2048] = { 0 };
	GetConsoleTitle(title, 2048);
	HWND hWnd = FindWindow(NULL, title);
	SetConsoleTitle(title);
	return hWnd;
}


int GetDPI(HWND hWnd) { // 이미지 관련 함수 
	HANDLE user32 = GetModuleHandle(TEXT("user32"));
	FARPROC func = GetProcAddress(user32, "GetDpiForWindow");
	if (func == NULL)
		return 96;
	return ((UINT(__stdcall*)(HWND))func)(hWnd);
}

void GetBMP(HDC hdc, HDC memdc, HBITMAP image) { // 이미지 관련 함수 
	BITMAP bitmap;
	HDC bitmapDC = CreateCompatibleDC(hdc);
	GetObject(image, sizeof(bitmap), &bitmap);
	SelectObject(bitmapDC, image);
	BitBlt(memdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, bitmapDC, 0, 0, SRCCOPY);
	DeleteDC(bitmapDC);
}

void paint(HWND hWnd, int dpi, HBITMAP image, int x, int y) { // 이미지 관련 함수 
	HDC hdc = GetDC(hWnd);
	HDC memdc = CreateCompatibleDC(hdc);
	HBITMAP bitmap = CreateCompatibleBitmap(hdc, x, y);
	SelectObject(memdc, bitmap);
	GetBMP(hdc, memdc, image);
	StretchBlt(hdc, 0, 0, x, y, memdc, 0, 0, x, y, SRCCOPY);
	DeleteDC(memdc);
	DeleteObject(bitmap);
	ReleaseDC(hWnd, hdc);
}

int be_input() // 마우스 관련 함수
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int get_input(WORD* vkey, COORD* pos) // 마우스 관련 함수
{
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType) {
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;

			return MOUSE_EVENT;
		}
		break;

	}
	return 0;
}

void mouseenable() { // 마우스 입력을 활성화 하는 함수 - system 함수를 사용하면 마우스 입력이 비활성화 됨
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
}

void ui(int level, int health, int maxhealth, int gold, int potion1, int potion2, int mobhealth, int mobmaxhealth, int mob, int targetmob) { // 좌측 상단 UI에 숫자를 띄우는 함수 (레벨, 현재 체력, 최대체력,
																					// 골드 소지량, 하급 포션 소지량, 상급 포션 소지량)
	gotoxy(112, 1);
	printf("%d", level);
	gotoxy(112, 2);
	printf("%d/%d  ", health, maxhealth);
	gotoxy(112, 3);
	printf("%d", gold);
	gotoxy(112, 5);
	printf("%d    ", potion1);
	gotoxy(112, 7);
	printf("%d    ", potion2);
	gotoxy(110, 10);
	printf("%d/%d  ", mobhealth, mobmaxhealth);
	gotoxy(110, 13);
	printf("%d/%d", mob, targetmob);
}

int keyboard() { // 키보드 입력을 받는 함수
	char temp = getch();
	if (temp == '1')
		return 1;
	else if (temp == '2')
		return 2;
	else if (temp == 'm' || temp == 'M')
		return 3;
	return -1;
}

void potion1(int* maxhealth, int* health, int* potion) { // 하급 포션 사용 함수
	if (*potion >= 1) { // 포션을 1개 이상 가지고 있을 경우
		*health += 50; // 포션을 사용했으므로, 체력 회복
		*potion -= 1; // 포션 갯수에서 1 차감
		if (*health > * maxhealth) // 단, 포션을 사용해서 체력을 최대 체력 이상으로 못 넘어가게 함
			*health = *maxhealth;
	}
}

void potion2(int* maxhealth, int* health, int* potion) { // 상급 포션 사용 함수
	if (*potion >= 1) { // 포션을 1개 이상 가지고 있을 경우
		*health += 250; // 포션을 사용했으므로, 체력 회복
		*potion -= 1; // 포션 갯수에서 1 차감
		if (*health > * maxhealth) // 단, 포션을 사용해서 체력을 최대 체력 이상으로 못 넘어가게 함
			*health = *maxhealth;
	}
}

void stopmusic() { // 음악을 끄는 함수
	mciSendString("stop Music\\mainscreen.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage9.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage0.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage1.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage8.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage2.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage4.mp3", NULL, 0, NULL);
	mciSendString("stop Music\\Stage5.mp3", NULL, 0, NULL);
}