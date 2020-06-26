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

HANDLE COUT = 0;    // �ܼ� ��� ��ġ
HANDLE CIN = 0;        // �ܼ� �Է� ��ġ

DWORD mode;
WORD key;
COORD pos;

int event;        // ���콺 �̺�Ʈ�� �̿�
int x;            // ���콺�� x��ǥ �����
int y;            // ���콺�� y��ǥ �����


void gotoxy(int x, int y) { // x, y ��ǥ�� �̵��ϴ� �Լ�
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void ClearCursor() { // ���콺 Ŀ���� ���ִ� �Լ�
	CONSOLE_CURSOR_INFO c;
	c.dwSize = 1;
	c.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void intro() { // �ܼ� ũ�� �� Ÿ��Ʋ�� �����ϴ� �Լ�
	system("cls");
	system("mode con cols=128 lines=36 | title Overlord");
}

HWND getConsoleWindowHandle() { // �̹��� ���� �Լ� 
	WCHAR title[2048] = { 0 };
	GetConsoleTitle(title, 2048);
	HWND hWnd = FindWindow(NULL, title);
	SetConsoleTitle(title);
	return hWnd;
}


int GetDPI(HWND hWnd) { // �̹��� ���� �Լ� 
	HANDLE user32 = GetModuleHandle(TEXT("user32"));
	FARPROC func = GetProcAddress(user32, "GetDpiForWindow");
	if (func == NULL)
		return 96;
	return ((UINT(__stdcall*)(HWND))func)(hWnd);
}

void GetBMP(HDC hdc, HDC memdc, HBITMAP image) { // �̹��� ���� �Լ� 
	BITMAP bitmap;
	HDC bitmapDC = CreateCompatibleDC(hdc);
	GetObject(image, sizeof(bitmap), &bitmap);
	SelectObject(bitmapDC, image);
	BitBlt(memdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, bitmapDC, 0, 0, SRCCOPY);
	DeleteDC(bitmapDC);
}

void paint(HWND hWnd, int dpi, HBITMAP image, int x, int y) { // �̹��� ���� �Լ� 
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

int be_input() // ���콺 ���� �Լ�
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int get_input(WORD* vkey, COORD* pos) // ���콺 ���� �Լ�
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

void mouseenable() { // ���콺 �Է��� Ȱ��ȭ �ϴ� �Լ� - system �Լ��� ����ϸ� ���콺 �Է��� ��Ȱ��ȭ ��
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
}

void ui(int level, int health, int maxhealth, int gold, int potion1, int potion2, int mobhealth, int mobmaxhealth, int mob, int targetmob) { // ���� ��� UI�� ���ڸ� ���� �Լ� (����, ���� ü��, �ִ�ü��,
																					// ��� ������, �ϱ� ���� ������, ��� ���� ������)
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

int keyboard() { // Ű���� �Է��� �޴� �Լ�
	char temp = getch();
	if (temp == '1')
		return 1;
	else if (temp == '2')
		return 2;
	else if (temp == 'm' || temp == 'M')
		return 3;
	return -1;
}

void potion1(int* maxhealth, int* health, int* potion) { // �ϱ� ���� ��� �Լ�
	if (*potion >= 1) { // ������ 1�� �̻� ������ ���� ���
		*health += 50; // ������ ��������Ƿ�, ü�� ȸ��
		*potion -= 1; // ���� �������� 1 ����
		if (*health > * maxhealth) // ��, ������ ����ؼ� ü���� �ִ� ü�� �̻����� �� �Ѿ�� ��
			*health = *maxhealth;
	}
}

void potion2(int* maxhealth, int* health, int* potion) { // ��� ���� ��� �Լ�
	if (*potion >= 1) { // ������ 1�� �̻� ������ ���� ���
		*health += 250; // ������ ��������Ƿ�, ü�� ȸ��
		*potion -= 1; // ���� �������� 1 ����
		if (*health > * maxhealth) // ��, ������ ����ؼ� ü���� �ִ� ü�� �̻����� �� �Ѿ�� ��
			*health = *maxhealth;
	}
}

void stopmusic() { // ������ ���� �Լ�
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