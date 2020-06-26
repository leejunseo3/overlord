#include "main.h"

struct data {
	int level; // �÷��̾� ����
	int max_health; // �÷��̾� �ִ� ü��
	int health; // �÷��̾� ���� ü��
	int gold; // ������
	int potion1; // �ϱ� ���� ����
	int potion2; // ��� ���� ����
	int process; // ���൵
};

struct mob {
	int max_health; // ���� �ִ� ü��
	int health; // ���� ���� ü��
	int damage; // ���� �����
	int cooldown; // �ݰ� �ֱ�
	int dropgold; // ���Ͱ� ����ϴ� ���
	int targetmob; // ��ǥ ���� ��
	int killedmob; // ���� ���� ��
};

int process = MAINSCREEN; // ���ຯ�� 

void attack(int* maxhealth, int* health, int damage, int* killedmob, int* dropgold, int* playergold) { // ������ ���͸� �����ϴ� �Լ�
	// (���� �ִ�ü��, ���� ���� ü��, �����, ���� �� ī��Ʈ ����, ���Ͱ� ����ϴ� ���, �÷��̾� �ܰ�)
	mciSendString("play Music\\attack.mp3", NULL, 0, NULL);
	*health -= damage; //������� ����
	if (*health <= 0) { // ü���� 0 ������ ��� ���͸� ����
		*killedmob += 1;
		*playergold += *dropgold;
		*health = *maxhealth;
	}
	return;
}

void counterattack(int* health, int* damage, int* cnt) { // ���Ͱ� ������ �����ϴ� �Լ�
	mciSendString("play Music\\hit.mp3", NULL, 0, NULL);
	*health -= *damage; // ������ ü���� ����
	*cnt = 0; // �ݰ��ֱ� ī��Ʈ �ʱ�ȭ
	if (*health <= 0) { // ü���� 0 ���ϰ� �� ���, ������ ����
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

void stage1(int health, int maxhealth) { // ù ��° ���������� ���� �̹����� ���� �Լ�
										 // ü�¿� ����Ͽ� ü�¹ٰ� �����ǵ��� ��
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

void stage2(int health, int maxhealth) { // �� ��° ���������� ���� �̹����� ���� �Լ�
										 // ü�¿� ����Ͽ� ü�¹ٰ� �����ǵ��� ��
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

void stage3(int health, int maxhealth) { // �� ��° ���������� ���� �̹����� ���� �Լ�
										 // ü�¿� ����Ͽ� ü�¹ٰ� �����ǵ��� ��
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

void stage9(int health, int maxhealth) { // -1 ��° ���������� ���� �̹����� ���� �Լ�
										 // ü�¿� ����Ͽ� ü�¹ٰ� �����ǵ��� ��
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

void stage0(int health, int maxhealth) { // 0 ��° ���������� ���� �̹����� ���� �Լ�
										 // ü�¿� ����Ͽ� ü�¹ٰ� �����ǵ��� ��
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

void stage6(int health, int maxhealth) { // ���� ��° ��������
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

void stage7(int health, int maxhealth) { // �ϰ� ��° ��������
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
void nstage1(int health, int maxhealth) { // ���� ��° ��������
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

	ClearCursor(); // ���콺 Ŀ���� ���ִ� �Լ�
	intro(); // ȭ�� ũ�� �� Ÿ��Ʋ�� �����ϴ� �Լ�
	int cnt = 0; // ī��Ʈ ���� (�ݰ� �ֱⰡ �� ��� �÷��̾�� ������� ����)
	int toggle = 0; // �����̳� �޴��� �湮�ϰ� �Դ��� Ȯ���ϴ� ���� (1�̸� �湮�ϰ� ��)
	int past = _time64(NULL); // ���� �ð�(���н� Ÿ��)
	int now = _time64(NULL); // ���� �ð�(���н� Ÿ��) - ���� �ð��� �����صΰ�, n�� �̻� �������� �˻��� �� ���

	CIN = GetStdHandle(STD_INPUT_HANDLE); // ���콺 ����
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(CIN, &mode); // ���콺 Ȱ��ȭ
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	char filename[100]; // �̹��� ����
	int dpi;
	HBITMAP bitmap;
	HWND hWnd = getConsoleWindowHandle();
	dpi = GetDPI(hWnd);

	while (1) { // process ������ ���� ���� ��Ȳ�� ��Ÿ��. (��: process�� MAINSCREEN�̸� �� ó�� Ÿ��Ʋ, STAGE1�̸� ù ��° ��������)
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ��� ��
					y = pos.Y;

					if (x >= 44 && x <= 83) {
						if (y >= 16 && y <= 19) { // 'NEW GAME'�� ������ ��
							process = NEWGAME;
							mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
						}
						else if (y >= 22 && y <= 24) { // 'LOAD GAME'�� ������ ��
							process = LOADGAME;
							mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
						}
						else if (y >= 27 && y <= 29) { // 'CREDIT'�� ������ ��		
							process = CREDIT;
							mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
						}
					}
				}
			}
		}

		if (process == NEWGAME) { // 'NEW GAME'�� �����ų� 'RESET'�� ������ �� (������ �����ϱ� �Ǵ� ���� ����)
			data.level = 1;
			data.max_health = 100;
			data.health = 100;
			data.gold = 0;
			data.potion1 = 0;
			data.potion2 = 0;
			process = TUTORIAL;
			stopmusic();
		}
		else if (process == LOADGAME) { // 'LOAD GAME'�� ������ ��
			FILE* fp1 = fopen("save\\save.txt", "r");
			fscanf(fp1, "level: %d\nhealth: %d\nmaxhealth: %d\ngold: %d\npotion1: %d\npotion2: %d\nprocess: %d", &data.level, &data.health, &data.max_health, &data.gold, &data.potion1, &data.potion2, &process);
			fclose(fp1);
			stopmusic();
		}


		else if (process == CREDIT) { // ũ���� ȭ�� �����ֱ�
			sprintf(filename, "Image\\credit.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			_getch();
			mciSendString("play Music\\confirm.mp3", NULL, 0, NULL);
			process = MAINSCREEN;
		}

		else if (process == MENU) { // �޴� ��ư�� ������ ��
			sprintf(filename, "Image\\menu.bmp");
			bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
			if (be_input()) {
				if (get_input(&key, &pos) != 0) {
					MOUSE_EVENT;
					x = pos.X;    // ���콺Ŭ������ x,y�� ����ǵ��� ��
					y = pos.Y;

					if (x >= 44 && x <= 83) {
						if (y >= 9 && y <= 11) { // 'SAVE' ��ư�� ������ ��
							FILE* fp1 = fopen("Save\\save.txt", "w");
							fprintf(fp1, "level: %d\nhealth: %d\nmaxhealth: %d\ngold: %d\npotion1: %d\npotion2: %d\nprocess: %d", data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, data.process);
							fclose(fp1);
							process = MAINSCREEN;
						}
						else if (y >= 16 && y <= 19) { // 'RESET' ��ư�� ������ �� (�ٽ� �ϱ� ��� �����: ���� �����͸� ���� �ʱ�ȭ�ϰ�, ó������ �ٽ� ������)
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
						else if (y >= 24 && y <= 27) { // 'SHUTDOWN' ��ư�� ������ ��
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

		else if (process == TUTORIAL) { // Ʃ�丮�� ����
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
		else if (process == STAGE9_STORY) { // -1 �������� ���丮
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
		else if (process == STAGE9) { // -1 ��° ��������
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = STAGE9;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = STAGE9;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = STAGE0_STORY;
						stage9(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage9.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE0_STORY) { // �������� 0 ���丮
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
		else if (process == STAGE0) { // 0�� ° ��������
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = STAGE0;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = STAGE0;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = STAGE8_STORY;
						stage0(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage0.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE1_STORY) { // ù ��° �������� ���丮
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
		else if (process == STAGE1) { // ù�� ° ��������
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
						x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
						y = pos.Y;
						if (y >= 33 && y <= 35) {
							if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
								process = SHOP;
								data.process = STAGE1;
							}
							else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
								process = MENU;
								data.process = STAGE1;
							}
						}
						else {
							attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
							if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
								process = STAGE2_STORY;
							stage1(mob.health, mob.max_health);
							ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
						}
					}
				}
				Sleep(10);
				cnt++;
				if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
					counterattack(&data.health, &mob.damage, &cnt);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
			}
			mciSendString("stop Music\\Stage1.mp3", NULL, 0, NULL);
		}
		else if (process == SHOP) { // ���� ��ư�� ������ ���
			// ���� ȭ�� ���� ������ ���� Ŭ���� ���ŵǴ� ����
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
						x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
						y = pos.Y;
						if ((x >= 102 && x <= 109) && (y >= 4 && y <= 7)) { // ���� ���� ��ư�� ������ ���
							FILE* fp1 = fopen("Save\\time.txt", "r");
							fscanf(fp1, "%d", &past);
							fclose(fp1);
							now = _time64(NULL);
							if (now - past >= 30) { // ���������� ���� ���� 30�ʰ� ������ ���
								mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
								system("start http://sunrint.hs.kr/index.do");
								mouseenable(); // system �Լ��� ����ϰ� ���� ���콺 �ν��� ��Ȱ��ȭ �ż� �ٽ� Ȱ��ȭ ���Ѿ� ��
								FILE* fp1 = fopen("Save\\time.txt", "w"); // ���������� ���� �� �ð��� ������
								fprintf(fp1, "%d", now);
								fclose(fp1);
								data.gold *= 2;
								sprintf(filename, "Image\\SHOPMAIN.bmp");
								bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
								paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							}
						}
						else if ((x >= 48 && x <= 68) && (y >= 13 && y <= 26)) { // ���� ������ ������ ���
							process = SHOPLEVEL;
							mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
							system("cls");
							sprintf(filename, "Image\\SHOPLEVEL.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
							printf("[ ���� �� ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("���� ����: %d �� ���� ����: %d", data.level, data.level + 1);
							gotoxy(48, 16);
							printf("���� ���ݷ�: %d �� ���� ���ݷ�: %d", 7 + data.level * 3, 7 + (data.level + 1) * 3);
							gotoxy(48, 17);
							printf("���� ü��: %d �� ���� ü��: %d", data.max_health, data.max_health + 10);
							gotoxy(48, 19);
							printf("���: %dGD", 25 + data.level * 25);
							gotoxy(48, 20);
							printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
							printf("[ ���� �� ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("���� ����: %d �� ���� ����: %d", data.level, data.level + 1);
							gotoxy(48, 16);
							printf("���� ���ݷ�: %d �� ���� ���ݷ�: %d", 7 + data.level * 3, 7 + (data.level + 1) * 3);
							gotoxy(48, 17);
							printf("���� ü��: %d �� ���� ü��: %d", data.max_health, data.max_health + 10);
							gotoxy(48, 19);
							printf("���: %dGD", 25 + data.level * 25);
							gotoxy(48, 20);
							printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
							while (process == SHOPLEVEL) {
								if (be_input()) {
									if (get_input(&key, &pos) != 0) {
										MOUSE_EVENT;
										x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
										y = pos.Y;
										if ((x >= 93 && x <= 101) && (y >= 15 || y <= 18)) { // BUY ��ư�� ������ ��
											if ((25 + data.level * 25) <= data.gold) { // �������� �ʿ� ��뺸�� ���� ���
												mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
												paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
												data.gold -= 25 + data.level * 25;
												data.level++;
												data.max_health += 10;
												data.health += 10;
												gotoxy(48, 14);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
												printf("[ ���� �� ]");
												gotoxy(48, 15);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
												printf("���� ����: %d �� ���� ����: %d", data.level, data.level + 1);
												gotoxy(48, 16);
												printf("���� ���ݷ�: %d �� ���� ���ݷ�: %d", 7 + data.level * 3, 7 + (data.level + 1) * 3);
												gotoxy(48, 17);
												printf("���� ü��: %d �� ���� ü��: %d", data.max_health, data.max_health + 10);
												gotoxy(48, 19);
												printf("���: %dGD", 25 + data.level * 25);
												gotoxy(48, 20);
												printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
											}
											else
												mciSendString("play Music\\error.mp3", NULL, 0, NULL);
										}
										else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // �ڷΰ��� ��ư�� ������ ��
											process = SHOP;
									}
								}
							}
						}
						else if ((x >= 77 && x <= 96) && (y >= 13 && y <= 26)) { // �ϱ� ���� ������ ������ ���
							mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
							process = SHOPLOWPOTION;
							system("cls");
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ �ϱ� ���� ���� ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP�� 100��ŭ ȸ���մϴ�.");
							gotoxy(48, 17);
							printf("���: %dGD", 50);
							gotoxy(48, 18);
							printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
							gotoxy(48, 19);
							printf("(���� �ϱ� ���� %d���� �����ϰ� �ֽ��ϴ�.)", data.potion1);
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ �ϱ� ���� ���� ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP�� 100��ŭ ȸ���մϴ�.");
							gotoxy(48, 17);
							printf("���: %dGD", 50);
							gotoxy(48, 18);
							printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
							gotoxy(48, 19);
							printf("(���� �ϱ� ���� %d���� �����ϰ� �ֽ��ϴ�.)", data.potion1);
							while (process == SHOPLOWPOTION) {
								if (be_input()) {
									if (get_input(&key, &pos) != 0) {
										MOUSE_EVENT;
										x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
										y = pos.Y;
										if ((x >= 93 && x <= 101) && (y >= 15 || y <= 18)) { // BUY ��ư�� ������ ��
											if (50 <= data.gold) { // �������� �ʿ� ��뺸�� ���� ���
												mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
												paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
												data.gold -= 50;
												data.potion1++;
												gotoxy(48, 14);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
												printf("[ �ϱ� ���� ���� ]");
												gotoxy(48, 15);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
												printf("HP�� 100��ŭ ȸ���մϴ�.");
												gotoxy(48, 17);
												printf("���: %dGD", 50);
												gotoxy(48, 18);
												printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
												gotoxy(48, 19);
												printf("(���� �ϱ� ���� %d���� �����ϰ� �ֽ��ϴ�.)", data.potion1);
											}
											else
												mciSendString("play Music\\error.mp3", NULL, 0, NULL);
										}
										else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // �ڷΰ��� ��ư�� ������ ��
											process = SHOP;
									}
								}
							}
						}
						else if ((x >= 104 && x <= 124) && (y >= 13 && y <= 26)) { // ��� ���� ������ ������ ���
							mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
							process = SHOPHIGHPOTION;
							system("cls");
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ ��� ���� ���� ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP�� 500��ŭ ȸ���մϴ�.");
							gotoxy(48, 17);
							printf("���: %dGD", 250);
							gotoxy(48, 18);
							printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
							gotoxy(48, 19);
							printf("(���� ��� ���� %d���� �����ϰ� �ֽ��ϴ�.)", data.potion1);
							sprintf(filename, "Image\\SHOPLOWPOTION.bmp");
							bitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
							mouseenable();
							paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
							gotoxy(48, 14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
							printf("[ ��� ���� ���� ]");
							gotoxy(48, 15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
							printf("HP�� 500��ŭ ȸ���մϴ�.");
							gotoxy(48, 17);
							printf("���: %dGD", 250);
							gotoxy(48, 18);
							printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
							gotoxy(48, 19);
							printf("(���� ��� ���� %d���� �����ϰ� �ֽ��ϴ�.)", data.potion2);
							while (process == SHOPHIGHPOTION) { // ��� ���� ����â
								if (be_input()) {
									if (get_input(&key, &pos) != 0) {
										MOUSE_EVENT;
										x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
										y = pos.Y;
										if ((x >= 93 && x <= 101) && (y >= 15 || y <= 18)) { // BUY ��ư�� ������ ��
											if (250 <= data.gold) { // �������� �ʿ� ��뺸�� ���� ���
												mciSendString("play Music\\coin.mp3", NULL, 0, NULL);
												paint(hWnd, dpi, bitmap, WIDTH, HEIGHT);
												data.gold -= 250;
												data.potion2++;
												gotoxy(48, 14);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
												printf("[ ��� ���� ���� ]");
												gotoxy(48, 15);
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
												printf("HP�� 500��ŭ ȸ���մϴ�.");
												gotoxy(48, 17);
												printf("���: %dGD", 250);
												gotoxy(48, 18);
												printf("(���� %dGD�� �����ϰ� �ֽ��ϴ�.)       ", data.gold);
												gotoxy(48, 19);
												printf("(���� ��� ���� %d���� �����ϰ� �ֽ��ϴ�.)", data.potion2);
											}
											else
												mciSendString("play Music\\error.mp3", NULL, 0, NULL);
										}
										else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // �ڷΰ��� ��ư�� ������ ��
											process = SHOP;
									}
								}
							}
						}
						else if ((x >= 120 && x <= 125) && (y >= 32 && y <= 34)) // �ڷΰ��� ��ư�� ������ ��
							process = data.process;

					}
				}
			}
			// ���� �����⸦ ������ ��
			toggle = 1;
		}
		else if (process == STAGE2_STORY) { // �ι� ° �������� ���丮
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
		else if (process == STAGE8_STORY) { // �ι� ° �������� ���丮
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
		else if (process == STAGE2) { // �� ��° ��������
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
						x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
						y = pos.Y;
						if (y >= 33 && y <= 35) {
							if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
								process = SHOP;
								data.process = STAGE2;
							}
							else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
								process = MENU;
								data.process = STAGE2;
							}
						}
						else {
							attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
							if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
								process = STAGE3_STORY;
							stage2(mob.health, mob.max_health);
							ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
						}
					}
				}
				Sleep(10);
				cnt++;
				if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = STAGE8;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = STAGE8;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = STAGE1_STORY;
						stage8(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage2.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE3_STORY) {// �� ��° �������� ���丮
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

		else if (process == STAGE3) { // �� ��° ��������
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
						x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
						y = pos.Y;
						if (y >= 33 && y <= 35) {
							if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
								process = SHOP;
								data.process = STAGE3;
							}
							else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
								process = MENU;
								data.process = STAGE3;
								toggle = 1;
							}
						}
						else {
							attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
							if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
								process = STAGE3_STORY;
							stage3(mob.health, mob.max_health);
							ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
						}
					}
				}
				Sleep(10);
				cnt++;
				if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
					counterattack(&data.health, &mob.damage, &cnt);
					ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
				}
			}
			mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE4) { // �� ��° ��������
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = STAGE4;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = STAGE4;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = STAGE6_STORY;
						stage3(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
		}
		else if (process == STAGE6_STORY) { // ������ ° �������� ���丮
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
		} // �������� 6

		else if (process == STAGE6) { // �� ��° ��������
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = STAGE6;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = STAGE6;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = STAGE7_STORY;
						stage6(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage3.mp3", NULL, 0, NULL);
		}

		else if (process == STAGE7_STORY) { // �ϰ��� ° �������� ���丮
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = STAGE7;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = STAGE7;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = NSTAGE1_STORY;
						stage7(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage7.mp3", NULL, 0, NULL);
		}
		else if (process == NSTAGE1_STORY) { //  11��° �������� ���丮
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

		else if (process == NSTAGE1) { // 11 ��° ��������
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = NSTAGE1;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = NSTAGE1;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
							process = NSTAGE2_STORY;
						nstage1(mob.health, mob.max_health);
						ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
					}
				}
			}
			Sleep(10);
			cnt++;
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\Stage11.mp3", NULL, 0, NULL);
		}

		else if (process == NSTAGE2_STORY) { //  12��° �������� ���丮
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

		else if (process == LASTSTAGE) { // ������ ��������
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					if (y >= 33 && y <= 35) {
						if (x >= 114 && x <= 118) { // ���� ��ư�� ������ ���
							process = SHOP;
							data.process = LASTSTAGE;
						}
						else if (x >= 120 && x <= 124) { // �޴� ��ư�� ������ ���
							process = MENU;
							data.process = LASTSTAGE;
							toggle = 1;
						}
					}
					else {
						attack(&mob.max_health, &mob.health, 7 + data.level * 3, &mob.killedmob, &mob.dropgold, &data.gold);
						if (mob.targetmob == mob.killedmob) // ��ǥ ų ���� ������ ���, ���� ���������� �Ѿ
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
			if (cnt >= mob.cooldown) { // ī��Ʈ�� ������ �ݰ� �ֱ⸦ �Ѿ��� ���, ���Ͱ� ������ ���� ��
				counterattack(&data.health, &mob.damage, &cnt);
				ui(data.level, data.health, data.max_health, data.gold, data.potion1, data.potion2, mob.health, mob.max_health, mob.killedmob, mob.targetmob);
			}
		}
		mciSendString("stop Music\\boss.mp3", NULL, 0, NULL);
		}

		else if (process == ENDSTORY) { //  ����
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
						x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
						y = pos.Y;
						if ((x >= 23 && x <= 33) && (y >= 26 && y <= 31)) { // �������� 1 ��ư�� ������ ��
							process = STAGE9;
						}
						else if ((x = 68 && x <= 78) && (y >= 20 && y <= 24)) { // �������� 2 ��ư�� ������ ��
							if (data.process >= STAGE1) // ���� �� ���� ���������� mŰ�� �̿��ؼ� ���� ���ϵ��� ��
								process = STAGE1;
						}
						else if ((x = 62 && x <= 72) && (y >= 8 && y <= 12)) { // �������� 3 ��ư�� ������ ��
							if (data.process >= STAGE2)
								process = STAGE2;
						}
						else if ((x = 78 && x <= 88) && (y >= 0 && y <= 5)) { // �������� 4 ��ư�� ������ ��
							if (data.process >= STAGE6)
								process = STAGE6;
						}
						else if ((x = 110 && x <= 120) && (y >= 25 && y <= 29)) { // �������� 5 ��ư�� ������ ��
							if (data.process >= STAGE5)
								process = STAGE5;
						}
					}
				}
			}
		}
		else if (process == GAMEOVER) { // ���� ������ ���� ���, �ٽ� ù ȭ������ ���ư�. (�ٽ��ϱ� ���)
			process = MAINSCREEN;
		}
	}
}