#include "main.h"

struct data {
	int level; // 플레이어 레벨
	int max_health; // 플레이어 최대 체력
	int health; // 플레이어 현재 체력
	int gold; // 소지금
	int potion1; // 하급 포션 갯수
	int potion2; // 상급 포션 갯수
	int process; // 진행도
};

struct mob {
	int max_health; // 몬스터 최대 체력
	int health; // 몬스터 현재 체력
	int damage; // 몬스터 대미지
	int cooldown; // 반격 주기
	int dropgold; // 몬스터가 드랍하는 골드
	int targetmob; // 목표 몬스터 수
	int killedmob; // 죽인 몬스터 수
};

int process = MAINSCREEN; // 진행변수 

void attack(int* maxhealth, int* health, int damage, int* killedmob, int* dropgold, int* playergold) { // 유저가 몬스터를 공격하는 함수
	// (몬스터 최대체력, 몬스터 현재 체력, 대미지, 죽인 몹 카운트 변수, 몬스터가 드랍하는 골드, 플레이어 잔고)
	mciSendString("play Music\\attack.mp3", NULL, 0, NULL);
	*health -= damage; //대미지를 입힘
	if (*health <= 0) { // 체력이 0 이하일 경우 몬스터를 죽임
		*killedmob += 1;
		*playergold += *dropgold;
		*health = *maxhealth;
	}
	return;
}

void counterattack(int* health, int* damage, int* cnt) { // 몬스터가 유저를 공격하는 함수
	mciSendString("play Music\\hit.mp3", NULL, 0, NULL);
	*health -= *damage; // 유저의 체력을 깎음
	*cnt = 0; // 반격주기 카운트 초기화
	if (*health <= 0) { // 체력이 0 이하가 될 경우, 유저를 죽임
		char filename[100];
		int dpi;
		HBITMAP bitmap;
		HWND hWnd = getConsoleWindowHandle();
		dpi = GetDPI(hWnd);
		sprintf(filename, "Image\\GAMEOVER.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		stopmusic();
		_getch();
		process = GAMEOVER;
		return;
	}

}

void stage1(int health, int maxhealth) { // 첫 번째 스테이지의 몬스터 이미지를 띄우는 함수
										 // 체력에 비례하여 체력바가 조정되도록 함
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\1monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\1monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\1monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\1monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\1monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\1monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\1monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\1monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\1monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\1monster9.bmp");
	else
		sprintf(filename, "Image\\1monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage2(int health, int maxhealth) { // 두 번째 스테이지의 몬스터 이미지를 띄우는 함수
										 // 체력에 비례하여 체력바가 조정되도록 함
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\2monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\2monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\2monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\2monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\2monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\2monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\2monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\2monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\2monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\2monster9.bmp");
	else
		sprintf(filename, "Image\\2monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage3(int health, int maxhealth) { // 세 번째 스테이지의 몬스터 이미지를 띄우는 함수
										 // 체력에 비례하여 체력바가 조정되도록 함
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\3monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\3monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\3monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\3monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\3monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\3monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\3monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\3monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\3monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\3monster9.bmp");
	else
		sprintf(filename, "Image\\3monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage9(int health, int maxhealth) { // -1 번째 스테이지의 몬스터 이미지를 띄우는 함수
										 // 체력에 비례하여 체력바가 조정되도록 함
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\9monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\9monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\9monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\9monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\9monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\9monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\9monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\9monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\9monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\9monster9.bmp");
	else
		sprintf(filename, "Image\\9monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage0(int health, int maxhealth) { // 0 번째 스테이지의 몬스터 이미지를 띄우는 함수
										 // 체력에 비례하여 체력바가 조정되도록 함
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\0monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\0monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\0monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\0monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\0monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\0monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\0monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\0monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\0monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\0monster9.bmp");
	else
		sprintf(filename, "Image\\0monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage8(int health, int maxhealth) { 
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\8monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\8monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\8monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\8monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\8monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\8monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\8monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\8monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\8monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\8monster9.bmp");
	else
		sprintf(filename, "Image\\8monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage6(int health, int maxhealth) { // 여섯 번째 스테이지
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\6monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\6monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\6monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\6monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\6monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\6monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\6monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\6monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\6monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\6monster9.bmp");
	else
		sprintf(filename, "Image\\6monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

void stage7(int health, int maxhealth) { // 일곱 번째 스테이지
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\7monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\7monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\7monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\7monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\7monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\7monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\7monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\7monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\7monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\7monster9.bmp");
	else
		sprintf(filename, "Image\\7monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}
void nstage1(int health, int maxhealth) { // 열한 번째 스테이지
	char filename[100];
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);
	if (maxhealth == health)
		sprintf(filename, "Image\\11monster10.bmp");
	else if (maxhealth * 0.1 >= health)
		sprintf(filename, "Image\\11monster1.bmp");
	else if (maxhealth * 0.2 >= health)
		sprintf(filename, "Image\\11monster2.bmp");
	else if (maxhealth * 0.3 >= health)
		sprintf(filename, "Image\\11monster3.bmp");
	else if (maxhealth * 0.4 >= health)
		sprintf(filename, "Image\\11monster4.bmp");
	else if (maxhealth * 0.5 >= health)
		sprintf(filename, "Image\\11monster5.bmp");
	else if (maxhealth * 0.6 >= health)
		sprintf(filename, "Image\\11monster6.bmp");
	else if (maxhealth * 0.7 >= health)
		sprintf(filename, "Image\\11monster7.bmp");
	else if (maxhealth * 0.8 >= health)
		sprintf(filename, "Image\\11monster8.bmp");
	else if (maxhealth * 0.9 >= health)
		sprintf(filename, "Image\\11monster9.bmp");
	else
		sprintf(filename, "Image\\11monster10.bmp");
	bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
}

int main() {

	struct data data = { 1, 100, 100, 0, 0, 0, 0 };
	struct mob mob;

	ClearCursor(); // 마우스 커서를 없애는 함수
	intro(); // 화면 크기 및 타이틀을 설정하는 함수
	int cnt = 0; // 카운트 변수 (반격 주기가 될 경우 플레이어에게 대미지를 입힘)
	int toggle = 0; // 상점이나 메뉴를 방문하고 왔는지 확인하는 변수 (1이면 방문하고 옴)
	int past = _time64(NULL); // 과거 시각(유닉스 타임)
	int now = _time64(NULL); // 현재 시각(유닉스 타임) - 과거 시각을 저장해두고, n초 이상 지났는지 검사할 때 사용

	CIN = GetStdHandle(STD_INPUT_HANDLE); // 마우스 변수
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(CIN, &mode); // 마우스 활성화
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	char filename[100]; // 이미지 관련
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);

	while (1) { // process 변수가 현재 진행 상황을 나타냄. (예: process가 MAINSCREEN이면 맨 처음 타이틀, STAGE1이면 첫 번째 스테이지)
		stopmusic();
		while (process == MAINSCREEN) {
			toggle = 0;
			mciSendString("play Music\\mainscreen.mp3 repeat", NULL, 0, NULL);
			Sleep(10);
			sprintf(filename, "Image\\intro.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록 함
					y = pos.Y;

					if (x >= 44 && x <= 83) {
						if (y >= 16 && y <= 19) { // 'NEW GAME'을 눌렀을 때
							process = NEWGAME;
							mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
						}
						else if (y >= 22 && y <= 24) { // 'LOAD GAME'을 눌렀을 때
							process = LOADGAME;
							mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
						}
						else if (y >= 27 && y <= 29) { // 'CREDIT'을 눌렀을 때		
							process = CREDIT;
							mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
						}
					}
				}
			}
		}

		if (process == NEWGAME) { // 'NEW GAME'을 눌렀거나 'RESET'을 눌렀을 때 (새게임 시작하기 또는 리셋 게임)
			data.level = 1;
			data.max_health = 100;
			data.health = 100;
			data.gold = 0;
			data.potion1 = 0;
			data.potion2 = 0;
			process = TUTORIAL;
			stopmusic();
		}
		else if (process == LOADGAME) { // 'LOAD GAME'을 눌렀을 때
			FILE* fp1 = fopen("save\\save.txt", "r");
			fscanf(fp1, "level: %d\nhealth: %d\nmaxhealth: %d\ngold: %d\npotion1: %d\npotion2: %d\nprocess: %d", &data.level, &data.health, &data.max_health, &data.gold, &data.potion1, &data.potion2, &process);
			fclose(fp1);
			stopmusic();
		}


		else if (process == CREDIT) { // 크레딧 화면 보여주기
			sprintf(filename, "Image\\credit.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
			process = MAINSCREEN;
		}

		else if (process == MENU) { // 메뉴 버튼을 눌렀을 때
			sprintf(filename, "Image\\menu.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y에 저장되도록 함
					y = pos.Y;

					if (x >= 44 && x <= 83) {
						if (y >= 9 && y <= 11) { // 'SAVE' 버튼을 눌렀을 때
							FILE* fp1 = fopen("Save\\save.txt", "w");
							fprintf(fp1, "level: %d\nhealth: %d\nmaxhealth: %d\ngold: %d\npotion1: %d\npotion2: %d\nprocess: %d", data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, data.process);
							fclose(fp1);
							process = MAINSCREEN;
						}
						else if (y >= 16 && y <= 19) { // 'RESET' 버튼을 눌렀을 때 (다시 하기 기능 만들기: 게임 데이터를 전부 초기화하고, 처음부터 다시 시작함)
							data.level = 1;
							data.health = 1;
							data.max_health = 1;
							data.gold = 0;
							data.potion1 = 0;
							data.potion2 = 0;
							data.process = TUTORIAL;
							FILE* fp1 = fopen("Save\\save.txt", "w");
							fprintf(fp1, "level: %d\nhealth: %d\nmaxhealth: %d\ngold: %d\npotion1: %d\npotion2: %d\nprocess: %d", data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, 0);
							fclose(fp1);
							process = NEWGAME;
						}
						else if (y >= 24 && y <= 27) { // 'SHUTDOWN' 버튼을 눌렀을 때
							system("cls");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
							sprintf(filename, "Image\\OFF.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							return 0;
						}
					}
				}
			}
		}

		else if (process == TUTORIAL) { // 튜토리얼 진행
			mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
			sprintf(filename, "Image\\tutorial1.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial2.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial3.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial4.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial5.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial6.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial7.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial8.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial9.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial10.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial11.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial12.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial13.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial14.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial15.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\tutorial16.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
			process = STAGE9_STORY;
		}
		else if (process == STAGE9_STORY) { // -1 스테이지 스토리
			mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
			sprintf(filename, "Image\\STAGE-1_1.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE-1_2.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE-1_3.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE-1_4.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T1.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T2.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T3.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T4.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T5.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T6.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T7.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T8.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T9.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T10.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T11.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T12.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T13.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T14.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T15.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\T16.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
			process = STAGE9;
		}
		else if (process == STAGE9) { // -1 번째 스테이지
		mciSendString("play Music\\Stage9.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\Stage9.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		stage9(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		stage9(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == STAGE9 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = STAGE9;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = STAGE9;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = STAGE0_STORY;
						stage9(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage9.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE0_STORY) { // 스테이지 0 스토리
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\STAGE0_1.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE0_2.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE0_3.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE0_4.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE0_5.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE0_6.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = STAGE0;
		}
		else if (process == STAGE0) { // 0번 째 스테이지
		mciSendString("play Music\\Stage0.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\Stage0.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		stage0(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		stage0(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == STAGE0 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = STAGE0;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = STAGE0;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = STAGE8_STORY;
						stage0(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage0.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE1_STORY) { // 첫 번째 스테이지 스토리
			mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
			sprintf(filename, "Image\\STAGE1_2.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_3.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_4.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_5.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_6.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_7.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_8.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_9.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_10.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_11.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_12.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_13.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE1_14.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
			process = STAGE1;
		}
		else if (process == STAGE1) { // 첫번 째 스테이지
		mciSendString("play Music\\Stage1.mp3 repeat", NULL, 0, NULL);
			if (toggle == 0) {
				FILE* fp1 = fopen("Mob\\Stage1.txt", "r");
				fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
				fclose(fp1);
				mob.killedmob = 0;
			}
			else if (toggle == 1)
				toggle = 0;
			stage1(mob.health, mob.max_health);
			ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			stage1(mob.health, mob.max_health);
			ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			while (process == STAGE1 && mob.killedmob < mob.targetmob) {
				if (_kbhit()) {
					int key = keyboard();
					if (key == 1) {
						potion1(&data.max_health, &data.health, &data.potion1);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
					else if (key == 2) {
						potion2(&data.max_health, &data.health, &data.potion2);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
					else if (key == 3) {
						data.process = process;
						process = MAP;
					}
				}
				if (be_input()) {
					if (get_input(&key, &pos) != 0) {
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						y = pos.Y;
						if (y >= 33 && y <= 35) {
							if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
								process = SHOP;
								data.process = STAGE1;
							}
							else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
								process = MENU;
								data.process = STAGE1;
							}
						}
						else {
							attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
							if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
								process = STAGE2_STORY;
							stage1(mob.health, mob.max_health);
							ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
						}
					}
				}
				Sleep(10);
				cnt++;
				if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
					counterattack(&data.health, &mob.damage, &cnt);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
			}
			mciSendString("stop Music\\Stage1.mp3", NULL, 0, NULL);
		}
		else if (process == SHOP) { // 상점 버튼을 눌렀을 경우
			// 상점 화면 띄우고 아이템 구매 클릭시 구매되는 구문
			mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
			sprintf(filename, "Image\\SHOPMAIN.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);

			while (process == SHOP) {
				sprintf(filename, "Image\\SHOPMAIN.bmp");
				bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
				if (be_input()) {
					if (get_input(&key, &pos) != 0) {
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						y = pos.Y;
						if ((x >= 102 && x <= 109) && (y >= 4 && y <= 7)) { // 광고 보기 버튼을 눌렀을 경우
							FILE* fp1 = fopen("Save\\time.txt", "r");
							fscanf(fp1, "%d", &past);
							fclose(fp1);
							now = _time64(NULL);
							if (now - past >= 30) { // 마지막으로 광고를 보고 30초가 지났을 경우
								mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
								system("start http://sunrint.hs.kr/index.do");
								mouseenable(); // system 함수를 사용하고 나면 마우스 인식이 비활성화 돼서 다시 활성화 시켜야 함
								FILE* fp1 = fopen("Save\\time.txt", "w"); // 마지막으로 광고를 본 시각을 갱신함
								fprintf(fp1, "%d", now);
								fclose(fp1);
								data.gold *= 2;
								sprintf(filename, "Image\\SHOPMAIN.bmp");
								bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
								paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							}
						}
						else if ((x >= 48 && x <= 68) && (y >= 13 && y <= 26)) { // 레벨 상점을 눌렀을 경우
							process = SHOPLEVEL;
							mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
							system("cls");
							sprintf(filename, "Image\\SHOPLEVEL.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
							printf("[ 레벨 업 ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("현재 레벨: %d → 다음 레벨: %d", data.level, data.level + 1);
							gotoxy(48, 16);
							printf("현재 공격력: %d → 다음 공격력: %d", 7 + data.level * 3, 7 + (data.level + 1) * 3);
							gotoxy(48, 17);
							printf("현재 체력: %d → 다음 체력: %d", data.max_health, data.max_health + 10);
							gotoxy(48, 19);
							printf("비용: %dGD", 25 + data.level * 25);
							gotoxy(48, 20);
							printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
							printf("[ 레벨 업 ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("현재 레벨: %d → 다음 레벨: %d", data.level, data.level + 1);
							gotoxy(48, 16);
							printf("현재 공격력: %d → 다음 공격력: %d", 7 + data.level * 3, 7 + (data.level + 1) * 3);
							gotoxy(48, 17);
							printf("현재 체력: %d → 다음 체력: %d", data.max_health, data.max_health + 10);
							gotoxy(48, 19);
							printf("비용: %dGD", 25 + data.level * 25);
							gotoxy(48, 20);
							printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
							while (process == SHOPLEVEL) {
								if (be_input()) {
									if (get_input(&key, &pos) != 0) {
										MOUSE_EVENT;
										x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
										y = pos.Y;
										if ((x >= 93 && x <= 101) && (y >= 15 || y <= 18)) { // BUY 버튼을 눌렀을 때
											if ((25 + data.level * 25) <= data.gold) { // 소지금이 필요 비용보다 높을 경우
												mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
												paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
												data.gold -= 25 + data.level * 25;
												data.level++;
												data.max_health += 10;
												data.health += 10;
												gotoxy(48, 14);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
												printf("[ 레벨 업 ]");
												gotoxy(48, 15);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
												printf("현재 레벨: %d → 다음 레벨: %d", data.level, data.level + 1);
												gotoxy(48, 16);
												printf("현재 공격력: %d → 다음 공격력: %d", 7 + data.level * 3, 7 + (data.level + 1) * 3);
												gotoxy(48, 17);
												printf("현재 체력: %d → 다음 체력: %d", data.max_health, data.max_health + 10);
												gotoxy(48, 19);
												printf("비용: %dGD", 25 + data.level * 25);
												gotoxy(48, 20);
												printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
											}
											else
												mciSendString("play Music\\error.mp3", NULL, 0, NULL);
										}
										else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // 뒤로가기 버튼을 눌렀을 때
											process = SHOP;
									}
								}
							}
						}
						else if ((x >= 77 && x <= 96) && (y >= 13 && y <= 26)) { // 하급 포션 상점을 눌렀을 경우
							mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
							process = SHOPLOWPOTION;
							system("cls");
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ 하급 포션 구매 ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP를 100만큼 회복합니다.");
							gotoxy(48, 17);
							printf("비용: %dGD", 50);
							gotoxy(48, 18);
							printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
							gotoxy(48, 19);
							printf("(현재 하급 포션 %d개를 보유하고 있습니다.)", data.potion1);
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ 하급 포션 구매 ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP를 100만큼 회복합니다.");
							gotoxy(48, 17);
							printf("비용: %dGD", 50);
							gotoxy(48, 18);
							printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
							gotoxy(48, 19);
							printf("(현재 하급 포션 %d개를 보유하고 있습니다.)", data.potion1);
							while (process == SHOPLOWPOTION) {
								if (be_input()) {
									if (get_input(&key, &pos) != 0) {
										MOUSE_EVENT;
										x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
										y = pos.Y;
										if ((x >= 93 && x <= 101) && (y >= 15 || y <= 18)) { // BUY 버튼을 눌렀을 때
											if (50 <= data.gold) { // 소지금이 필요 비용보다 높을 경우
												mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
												paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
												data.gold -= 50;
												data.potion1++;
												gotoxy(48, 14);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
												printf("[ 하급 포션 구매 ]");
												gotoxy(48, 15);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
												printf("HP를 100만큼 회복합니다.");
												gotoxy(48, 17);
												printf("비용: %dGD", 50);
												gotoxy(48, 18);
												printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
												gotoxy(48, 19);
												printf("(현재 하급 포션 %d개를 보유하고 있습니다.)", data.potion1);
											}
											else
												mciSendString("play Music\\error.mp3", NULL, 0, NULL);
										}
										else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // 뒤로가기 버튼을 눌렀을 때
											process = SHOP;
									}
								}
							}
						}
						else if ((x >= 104 && x <= 124) && (y >= 13 && y <= 26)) { // 상급 포션 상점을 눌렀을 경우
							mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
							process = SHOPHIGHPOTION;
							system("cls");
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ 상급 포션 구매 ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP를 500만큼 회복합니다.");
							gotoxy(48, 17);
							printf("비용: %dGD", 250);
							gotoxy(48, 18);
							printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
							gotoxy(48, 19);
							printf("(현재 상급 포션 %d개를 보유하고 있습니다.)", data.potion1);
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ 상급 포션 구매 ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP를 500만큼 회복합니다.");
							gotoxy(48, 17);
							printf("비용: %dGD", 250);
							gotoxy(48, 18);
							printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
							gotoxy(48, 19);
							printf("(현재 상급 포션 %d개를 보유하고 있습니다.)", data.potion2);
							while (process == SHOPHIGHPOTION) { // 상급 포션 구매창
								if (be_input()) {
									if (get_input(&key, &pos) != 0) {
										MOUSE_EVENT;
										x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
										y = pos.Y;
										if ((x >= 93 && x <= 101) && (y >= 15 || y <= 18)) { // BUY 버튼을 눌렀을 때
											if (250 <= data.gold) { // 소지금이 필요 비용보다 높을 경우
												mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
												paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
												data.gold -= 250;
												data.potion2++;
												gotoxy(48, 14);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
												printf("[ 상급 포션 구매 ]");
												gotoxy(48, 15);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
												printf("HP를 500만큼 회복합니다.");
												gotoxy(48, 17);
												printf("비용: %dGD", 250);
												gotoxy(48, 18);
												printf("(현재 %dGD를 보유하고 있습니다.)       ", data.gold);
												gotoxy(48, 19);
												printf("(현재 상급 포션 %d개를 보유하고 있습니다.)", data.potion2);
											}
											else
												mciSendString("play Music\\error.mp3", NULL, 0, NULL);
										}
										else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // 뒤로가기 버튼을 눌렀을 때
											process = SHOP;
									}
								}
							}
						}
						else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // 뒤로가기 버튼을 눌렀을 때
							process = data.process;

					}
				}
			}
			// 상점 나가기를 눌렀을 때
			toggle = 1;
		}
		else if (process == STAGE2_STORY) { // 두번 째 스테이지 스토리
			mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
			sprintf(filename, "Image\\STAGE2_1.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE2_2.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE2_3.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE2_4.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE2_5.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE2_6.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
			process = STAGE2;
		}
		else if (process == STAGE8_STORY) { // 두번 째 스테이지 스토리
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\1.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\2.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\3.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = STAGE8;
		}
		else if (process == STAGE2) { // 두 번째 스테이지
			mciSendString("play Music\\Stage2.mp3 repeat", NULL, 0, NULL);
			if (toggle == 0) {
				FILE* fp1 = fopen("Mob\\Stage2.txt", "r");
				fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
				fclose(fp1);
				mob.killedmob = 0;
			}
			else if (toggle == 1)
				toggle = 0;
			stage2(mob.health, mob.max_health);
			ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			stage2(mob.health, mob.max_health);
			ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			while (process == STAGE2 && mob.killedmob < mob.targetmob) {
				if (_kbhit()) {
					int key = keyboard();
					if (key == 1) {
						potion1(&data.max_health, &data.health, &data.potion1);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
					else if (key == 2) {
						potion2(&data.max_health, &data.health, &data.potion2);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
					else if (key == 3) {
						data.process = process;
						process = MAP;
					}
				}
				if (be_input()) {
					if (get_input(&key, &pos) != 0) {
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						y = pos.Y;
						if (y >= 33 && y <= 35) {
							if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
								process = SHOP;
								data.process = STAGE2;
							}
							else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
								process = MENU;
								data.process = STAGE2;
							}
						}
						else {
							attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
							if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
								process = STAGE3_STORY;
							stage2(mob.health, mob.max_health);
							ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
						}
					}
				}
				Sleep(10);
				cnt++;
				if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
					counterattack(&data.health, &mob.damage, &cnt);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
			}
			mciSendString("stop Music\\Stage2.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE8) { 
		mciSendString("play Music\\Stage2.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\Stage8.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		stage8(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		stage8(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == STAGE8 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = STAGE8;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = STAGE8;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = STAGE1_STORY;
						stage8(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage2.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE3_STORY) {// 세 번째 스테이지 스토리
			sprintf(filename, "Image\\STAGE3_1.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE3_2.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			sprintf(filename, "Image\\STAGE3_3.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			process = STAGE4;
		}

		else if (process == STAGE3) { // 세 번째 스테이지
			mciSendString("play Music\\Stage3.mp3 repeat", NULL, 0, NULL);
			if (toggle == 0) {
				FILE* fp1 = fopen("Mob\\Stage3.txt", "r");
				fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
				fclose(fp1);
				mob.killedmob = 0;
			}
			else if (toggle == 1)
				toggle = 0;
			stage3(mob.health, mob.max_health);
			ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			stage3(mob.health, mob.max_health);
			ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			while (process == STAGE3 && mob.killedmob < mob.targetmob) {
				if (_kbhit()) {
					int key = keyboard();
					if (key == 1) {
						potion1(&data.max_health, &data.health, &data.potion1);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
					else if (key == 2) {
						potion2(&data.max_health, &data.health, &data.potion2);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
					else if (key == 3) {
						data.process = process;
						process = MAP;
					}
				}
				if (be_input()) {
					if (get_input(&key, &pos) != 0) {
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						y = pos.Y;
						if (y >= 33 && y <= 35) {
							if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
								process = SHOP;
								data.process = STAGE3;
							}
							else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
								process = MENU;
								data.process = STAGE3;
								toggle = 1;
							}
						}
						else {
							attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
							if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
								process = STAGE3_STORY;
							stage3(mob.health, mob.max_health);
							ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
						}
					}
				}
				Sleep(10);
				cnt++;
				if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
					counterattack(&data.health, &mob.damage, &cnt);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
			}
			mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE4) { // 세 번째 스테이지
		mciSendString("play Music\\Stage4.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\Stage4.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		stage3(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		stage3(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == STAGE4 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = STAGE4;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = STAGE4;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = STAGE6_STORY;
						stage3(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE6_STORY) { // 여섯번 째 스테이지 스토리
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\STAGE6_1.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE6_2.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE6_3.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE6_4.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\STAGE6_5.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = STAGE6;
		} // 스테이지 6

		else if (process == STAGE6) { // 세 번째 스테이지
		mciSendString("play Music\\Stage4.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\Stage6.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		stage6(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		stage6(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == STAGE6 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = STAGE6;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = STAGE6;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = STAGE7_STORY;
						stage6(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
		}

		else if (process == STAGE7_STORY) { // 일곱번 째 스테이지 스토리
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\STAGE7.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = STAGE7;
		} 

		else if (process == STAGE7) { 
		mciSendString("play Music\\Stage7.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\Stage7.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		stage7(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		stage7(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == STAGE7 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = STAGE7;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = STAGE7;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = NSTAGE1_STORY;
						stage7(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage7.mp3", NULL, 0, NULL);
		}
		else if (process == NSTAGE1_STORY) { //  11번째 스테이지 스토리
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\nstage1_1.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\nstage1_2.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\nstage1_3.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\nstage1_4.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = NSTAGE1;
		}

		else if (process == NSTAGE1) { // 11 번째 스테이지
		mciSendString("play Music\\Stage11.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\NStage1.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		nstage1(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		nstage1(mob.health, mob.max_health);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == NSTAGE1 && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = NSTAGE1;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = NSTAGE1;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = NSTAGE2_STORY;
						nstage1(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage11.mp3", NULL, 0, NULL);
		}

		else if (process == NSTAGE2_STORY) { //  12번째 스테이지 스토리
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\NSTAGE2_1.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_2.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_3.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_4.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_5.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_6.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_7.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_8.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_9.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_10.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_11.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_12.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_13.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_14.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_15.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_16.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_17.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_18.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_19.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_20.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_21.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_22.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_23.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\NSTAGE2_24.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = LASTSTAGE;
		}

		else if (process == LASTSTAGE) { // 마지막 스테이지
		mciSendString("play Music\\boss.mp3 repeat", NULL, 0, NULL);
		if (toggle == 0) {
			FILE* fp1 = fopen("Mob\\boss.txt", "r");
			fscanf(fp1, "max_health: %d\nhealth: %d\ndamage: %d\ncooldown: %d\ndropgold: %d\ntargetmob: %d", &mob.max_health, &mob.health, &mob.damage, &mob.cooldown, &mob.dropgold, &mob.targetmob);
			fclose(fp1);
			mob.killedmob = 0;
		}
		else if (toggle == 1)
			toggle = 0;
		sprintf(filename, "Image\\boss.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
		while (process == LASTSTAGE && mob.killedmob < mob.targetmob) {
			if (_kbhit()) {
				int key = keyboard();
				if (key == 1) {
					potion1(&data.max_health, &data.health, &data.potion1);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 2) {
					potion2(&data.max_health, &data.health, &data.potion2);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
				else if (key == 3) {
					data.process = process;
					process = MAP;
				}
			}
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // 상점 버튼을 눌렀을 경우
							process = SHOP;
							data.process = LASTSTAGE;
						}
						else if (x >= 120 && x <= 124) { // 메뉴 버튼을 눌렀을 경우
							process = MENU;
							data.process = LASTSTAGE;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // 목표 킬 수를 도달한 경우, 다음 스테이지로 넘어감
							process = ENDSTORY;
						sprintf(filename, "Image\\boss.bmp");
						bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
						paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // 카운트가 몬스터의 반격 주기를 넘었을 경우, 몬스터가 유저를 공격 함
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\boss.mp3", NULL, 0, NULL);
		}

		else if (process == ENDSTORY) { //  엔딩
		mciSendString("play Music\\walk.mp3 repeat", NULL, 0, NULL);
		sprintf(filename, "Image\\ENDING1.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\ENDING2.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\ENDING3.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		sprintf(filename, "Image\\ENDING4.bmp");
		bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
		_getch();
		mciSendString("stop Music\\walk.mp3", NULL, 0, NULL);
		process = MAINSCREEN;
		}

		else if (process == MAP) {
		stopmusic();
			sprintf(filename, "Image\\MAP.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);

			while (process == MAP) {
				if (be_input()) {
					if (get_input(&key, &pos) != 0) {
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						y = pos.Y;
						if ((x >= 23 && x <= 33) && (y >= 26 && y <= 31)) { // 스테이지 1 버튼을 눌렀을 때
							process = STAGE9;
						}
						else if ((x = 68 && x <= 78) && (y >= 20 && y <= 24)) { // 스테이지 2 버튼을 눌렀을 때
							if (data.process >= STAGE1) // 가본 적 없는 스테이지는 m키를 이용해서 가지 못하도록 함
								process = STAGE1;
						}
						else if ((x = 62 && x <= 72) && (y >= 8 && y <= 12)) { // 스테이지 3 버튼을 눌렀을 때
							if (data.process >= STAGE2)
								process = STAGE2;
						}
						else if ((x = 78 && x <= 88) && (y >= 0 && y <= 5)) { // 스테이지 4 버튼을 눌렀을 때
							if (data.process >= STAGE6)
								process = STAGE6;
						}
						else if ((x = 110 && x <= 120) && (y >= 25 && y <= 29)) { // 스테이지 5 버튼을 눌렀을 때
							if (data.process >= STAGE5)
								process = STAGE5;
						}
					}
				}
			}
		}
		else if (process == GAMEOVER) { // 게임 오버가 됐을 경우, 다시 첫 화면으로 돌아감. (다시하기 기능)
			process = MAINSCREEN;
		}
	}
}