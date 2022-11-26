#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <gl/gl.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "opengl32.lib")
int sbrosGameOver = 0;
int width = 850;
int high = 850;
int count = 0;
float speed_meteor = 0.009;
int flagstart = 0;
int flagLeaders = 0;
int enterUserName = 0;
char UserName[15];
Iname = 0;
float yLVL = 0.9;
int NUMLVL = 1;
int Health = 3;
int score = 0;
void show_Heatlh3();
void show_Heatlh2();
void show_Heatlh1();
int MAXscore = 0;
FILE* Leaders;





typedef struct Liders {
	char name[100];
	int ochko;
}Liders;
Liders chel[5];
void read_leaders(void)
{

	Leaders = fopen("C:/Server/Leaders.txt", "r");
	int i = 0;
	char c;
	while (!feof(Leaders))
	{
		fscanf(Leaders, "%s", chel[i].name);
		if (feof(Leaders)) break;
		c = fgetc(Leaders);
		fscanf(Leaders, "%d\n", &chel[i].ochko);
		i++;
	}
	fclose(Leaders);
}


typedef struct TButton {
	char name[20];
	float vert[8];
	BOOL hover;

}TButton;
TButton btn[] =
{
	{"start",{250,100,550,100,550,180,250,180},FALSE},
	{"quit",{250,220,550,220,550,300,250,300},FALSE},
	{"lider",{250,340,550,340,550,420,250,420},FALSE}
};
int btnCnt = sizeof(btn) / sizeof(btn[0]);





void TButton_Show(TButton btn)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	if (btn.hover) glColor3f(0, 1, 0);
	else glColor3f(1, 1, 1);
	glVertexPointer(2, GL_FLOAT, 0, btn.vert);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

typedef struct TButtonEnter {
	char name[20];
	float vert[8];
	BOOL hover;

}TButtonEnter;
TButtonEnter btnEnter[] =
{
{ "btnA",  { 50,50,50,100,100,100,100,50},FALSE },
{ "btnB",  { 125,50,125,100,175,100,175,50 },FALSE},
{ "btnC",  { 200,50,200,100,250,100,250,50 },FALSE},
{ "btn1",  { 50,125,50,175,100,175,100,125 },FALSE},
{ "btn2",  { 125,125,125,175,175,175,175,125 },FALSE},
{ "btn3",  { 200,125,200,175,250,175,250,125 },FALSE},
{ "enter", { 50,200,50,250,250,250,250,200 },FALSE}
};
int btnCntEnter = sizeof(btnEnter) / sizeof(btnEnter[0]);



void TButtonEnter_Show(TButtonEnter btnEnter)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	if (btnEnter.hover) glColor3f(0, 1, 0);
	else glColor3f(1, 1, 1);
	glVertexPointer(2, GL_FLOAT, 0, btnEnter.vert);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBegin(GL_LINES);
	//ShowA
	glColor3f(1, 0, 0);
	glVertex2f(75, 55);
	glVertex2f(95, 95);

	glVertex2f(75, 55);
	glVertex2f(55, 95);

	glVertex2f(65, 75);
	glVertex2f(85, 75);
	//ShowB
	glVertex2f(55 + 75, 55);
	glVertex2f(55 + 75, 95);

	glVertex2f(55 + 75, 75);
	glVertex2f(75 + 75, 75);

	glVertex2f(55 + 75, 55);
	glVertex2f(75 + 75, 55);

	glVertex2f(55 + 75, 95);
	glVertex2f(75 + 75, 95);

	glVertex2f(75 + 75, 75);
	glVertex2f(80 + 75, 80);

	glVertex2f(75 + 75, 95);
	glVertex2f(80 + 75, 90);

	glVertex2f(75 + 75, 55);
	glVertex2f(80 + 75, 60);

	glVertex2f(75 + 75, 75);
	glVertex2f(80 + 75, 70);

	glVertex2f(80 + 75, 70);
	glVertex2f(80 + 75, 60);

	glVertex2f(80 + 75, 80);
	glVertex2f(80 + 75, 90);
	//showC
	glVertex2f(55 + 150, 55);
	glVertex2f(55 + 150, 95);

	glVertex2f(55 + 150, 55);
	glVertex2f(80 + 150, 55);

	glVertex2f(55 + 150, 95);
	glVertex2f(80 + 150, 95);
	//show1
	glVertex2f(75, 55 + 75);
	glVertex2f(75, 95 + 75);

	glVertex2f(75, 55 + 75);
	glVertex2f(65, 65 + 75);

	glVertex2f(67, 95 + 75);
	glVertex2f(83, 95 + 75);
	//show2
	glVertex2f(65 + 75, 55 + 75);
	glVertex2f(80 + 75, 55 + 75);

	glVertex2f(80 + 75, 55 + 75);
	glVertex2f(85 + 75, 60 + 75);

	glVertex2f(85 + 75, 60 + 75);
	glVertex2f(85 + 75, 70 + 75);

	glVertex2f(85 + 75, 70 + 75);
	glVertex2f(80 + 75, 75 + 75);

	glVertex2f(80 + 75, 75 + 75);
	glVertex2f(70 + 75, 75 + 75);

	glVertex2f(70 + 75, 75 + 75);
	glVertex2f(65 + 75, 80 + 75);

	glVertex2f(65 + 75, 80 + 75);
	glVertex2f(65 + 75, 95 + 75);

	glVertex2f(80 + 75, 95 + 75);
	glVertex2f(65 + 75, 95 + 75);
	//show3
	glVertex2f(90 + 150, 55 + 75);
	glVertex2f(90 + 150, 95 + 75);

	glVertex2f(90 + 150, 95 + 75);
	glVertex2f(65 + 150, 95 + 75);

	glVertex2f(90 + 150, 75 + 75);
	glVertex2f(65 + 150, 75 + 75);

	glVertex2f(90 + 150, 55 + 75);
	glVertex2f(65 + 150, 55 + 75);
	//show E
	glVertex2f(55, 95 + 150);
	glVertex2f(55, 55 + 150);
	glVertex2f(75, 95 + 150);
	glVertex2f(55, 95 + 150);
	glVertex2f(75, 75 + 150);
	glVertex2f(55, 75 + 150);
	glVertex2f(75, 55 + 150);
	glVertex2f(55, 55 + 150);
	//show N
	glVertex2f(55 + 40, 95 + 150);
	glVertex2f(55 + 40, 55 + 150);
	glVertex2f(55 + 40, 55 + 150);
	glVertex2f(75 + 40, 95 + 150);
	glVertex2f(75 + 40, 55 + 150);
	glVertex2f(75 + 40, 95 + 150);
	//showT
	glVertex2f(65 + 75, 55 + 150);
	glVertex2f(65 + 75, 95 + 150);

	glVertex2f(75 + 75, 55 + 150);
	glVertex2f(55 + 75, 55 + 150);
	//showE
	glVertex2f(55 + 110, 95 + 150);
	glVertex2f(55 + 110, 55 + 150);
	glVertex2f(75 + 110, 95 + 150);
	glVertex2f(55 + 110, 95 + 150);
	glVertex2f(75 + 110, 75 + 150);
	glVertex2f(55 + 110, 75 + 150);
	glVertex2f(75 + 110, 55 + 150);
	glVertex2f(55 + 110, 55 + 150);
	//showR
	glVertex2f(55 + 140, 95 + 150);
	glVertex2f(55 + 140, 55 + 150);

	glVertex2f(75 + 140, 75 + 150);
	glVertex2f(55 + 140, 75 + 150);

	glVertex2f(75 + 140, 55 + 150);
	glVertex2f(55 + 140, 55 + 150);

	glVertex2f(75 + 140, 55 + 150);
	glVertex2f(75 + 140, 75 + 150);

	glVertex2f(75 + 140, 95 + 150);
	glVertex2f(55 + 140, 75 + 150);

	glEnd();
}
typedef struct LidersButton {
	char name[20];
	float vert[8];
	BOOL hover;
}LidersButton;
LidersButton btnLiders = { "back",{20,20,20,40,60,40,60,20},FALSE };

void LidersButton_Show(LidersButton btn)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	if (btn.hover) glColor3f(0, 1, 0);
	else glColor3f(1, 1, 1);
	glVertexPointer(2, GL_FLOAT, 0, btn.vert);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void show_S(int x, int y);
void show_T(int x, int y);
void show_A(int x, int y);
void show_R(int x, int y);
void printQ(int x, int y);
void printU(int x, int y);
void printI(int x, int y);
void printL(int x, int y);
void printD(int x, int y);
void printE(int x, int y);
void printLeaders();
void print1(int x, int y);
void print2(int x, int y);
void print3(int x, int y);
void print4(int x, int y);
void print5(int x, int y);
void print6(int x, int y);
void print7(int x, int y);
void print8(int x, int y);
void print9(int x, int y);
void print0(int x, int y);
void printB(int x, int y);
void printC(int x, int y);
void printA(int x, int y);


void show_start()
{
	glLineWidth(5);
	show_S(50, 0);
	show_T(50, 0);
	show_A(50, 0);
	show_R(50, 0);
	show_T(210, 0);
}

void show_quit()
{
	printQ(150, 110);
	printU(200, 110);
	printI(250, 110);
	show_T(125, 120);
}
void showLeaders()
{
	printL(150, 230);
	printE(185, 230);
	show_A(30, 240);
	printD(280, 230);
	printE(330, 230);
	show_R(120, 240);
	//show_S(300, 240);
}



BOOL PointINButton(int x, int y, TButton btn)
{
	return (x > btn.vert[0]) && (x < btn.vert[4]) &&
		(y > btn.vert[1]) && (y < btn.vert[5]);
}

BOOL PointINButtonEnter(int x, int y, TButtonEnter btnEnter)
{
	return (x > btnEnter.vert[0]) && (x < btnEnter.vert[4]) &&
		(y > btnEnter.vert[1]) && (y < btnEnter.vert[5]);
}
BOOL PointINLidersButton(int x, int y, LidersButton btnLid)
{
	return (x > btnLid.vert[0]) && (x < btnLid.vert[4]) &&
		(y > btnLid.vert[1]) && (y < btnLid.vert[5]);
}



void ShowMenu()
{
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 850, 850, 0, -1, 1);
	for (int i = 0; i < btnCnt; i++)
	{
		TButton_Show(btn[i]);
	}
	show_start();
	show_quit();
	showLeaders();
	glPopMatrix();

}

void ShowEnterNameMenu()
{
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 850, 850, 0, -1, 1);
	for (int i = 0; i < btnCntEnter; i++)
	{
		TButtonEnter_Show(btnEnter[i]);
	}
	glPopMatrix();

}
void ShowLidersMenu()
{
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 850, 850, 0, -1, 1);
	LidersButton_Show(btnLiders);
	glLineWidth(3);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);

	glVertex2f(25, 30);
	glVertex2f(50, 30);

	glVertex2f(25, 30);
	glVertex2f(30, 25);

	glVertex2f(25, 30);
	glVertex2f(30, 35);

	glEnd();
	printLeaders();
	glPopMatrix();
}

void Show_LVL(float y);
void Show_LVLE(float ly);
void numLVL(float ly);


float getrand()
{
	//srand(time(NULL));
	float i = rand();
	i = (float)rand() / RAND_MAX * 2;
	i * 100;
	i--;
	if (i > 0.9)
		i = i - 0.1;
	return i;
}
void ShowQ(float x, float y, float size);
void show_space_ship(float x, float y, float size);
void showDopsaHealth(float x, float y);





typedef struct Space_Ship {
	float x, y;
	float dx, dy;
	float size;
}Space_Ship;
Space_Ship ship;

typedef struct Bullet {
	float bx, by;
	float bdx, bdy;
	float bsize;
} Bullet;

typedef struct meteoritq
{
	float mx;
	float my;
	float msize;
}meteorit;

typedef struct meteoritHealth
{
	float mx;
	float my;
	float msize;
}meteoritHealth;

meteoritHealth meteorH;

short checkHealth(meteoritHealth meteorh)  // ��������� ���������� �� ������� � �������� ����������, � �������� �����
{
	if (((ship.y + 0.25) >= (meteorh.my - 0.1 + 0.95)) && (ship.y + 0.25 <= meteorh.my + 0.1 + 0.95))
		if ((ship.x + 0.15 >= meteorh.mx - 0.11) && (ship.x - 0.05 <= meteorh.mx + 0.11))
			return 0;
	return 1;
}


void Space_Ship_Init(Space_Ship* obj, float x1, float y1, float size1) // ����������� ���������� �������, ���������� �� ��������� �����,1 ���
{
	obj->x = x1;
	obj->y = y1;

	obj->size = size1;
}
void Bullet_Init(Bullet* obj, float bsize1) // �������� ���� � �������, ����� ��� �� ���� ��������
{
	obj->bx = ship.x;
	obj->by = ship.y;
	obj->bsize = bsize1;
}

void meteorHealthInit(meteoritHealth* metH) // ������ ���������� ��������� �� ���������
{
	float i = getrand();
	metH->mx = getrand();
	metH->my = ((i + 2) * (i + 2) / 1.5);
	//metH->my = 1;
}
void Space_Ship_Show(Space_Ship obj) // ����������� ������� �� ������ �����
{
	glPushMatrix();
	glTranslatef(obj.x, -0.9, 0);
	glColor3f(1.0f, 0.4f, 0.4f);
	show_space_ship(0, 0, 0.1);  //������ ������ �������
	glPopMatrix();
}

short checkGameOver(meteorit meteor) // ��������� ������������ ������� � ����������
{
	if (((ship.y + 0.25) >= (meteor.my - 0.1 + 0.95)) && (ship.y + 0.25 <= (meteor.my + 0.1 + 0.95)))
		if ((ship.x + 0.15 >= meteor.mx - 0.11) && (ship.x - 0.05 <= meteor.mx + 0.11))
			return 0;
	return 1;
}
void Bullet_Show(Bullet obj, Space_Ship object) // ����������� ���� �� ������ ����� (������ �� ������� ����� �� ������)
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	ShowQ(obj.bx, obj.by + (2.5 * object.size), 0.05);
	glPopMatrix();
}

void Space_Ship_Move(Space_Ship* obj, char left, char right, char shot, float wl1, float wl2) // ���������� ������� ��� ������� ������
{
	static float speed = 0.02;
	if (GetKeyState(left) < 0)obj->x -= speed;
	else if (GetKeyState(right) < 0)obj->x += speed;



	if (obj->x - (obj->size) < wl1)
		obj->x = wl1 + (obj->size);
	if (obj->x + obj->size + 0.05 > wl2)
		obj->x = wl2 - obj->size - 0.05;


}
void Bullet_Move(Bullet* obj) // ���������� ����
{
	static float speed = 0.025;
	obj->by += speed;

	if (obj->by > 1)
	{
		//Bullet_Init(&obj, 0.05);
		obj->bx = 3;
	}
}
void move_meteorHealth(meteoritHealth* meteorH) // ���������� �������� ��������
{

	meteorH->my = meteorH->my - speed_meteor;
	glPushMatrix();
	glTranslatef(0.0, meteorH->my, 0.0);
	showDopsaHealth(meteorH->mx, 0.9);
	glPopMatrix();

}


LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
void meteorInit(meteorit* met);
void move_meteorit(meteorit* meteor);
void show_meteorit(float x, float y);
void showGameOver();
void show_meteor(float x, float y);
void showDopsaHealth(float x, float y);
void showAnimation(float x, float y);
meteorit* shootCheck(Bullet* bull, meteorit* meteor);
void take_digitals(int* array);
void show_score_1();
void show_score_2();
void show_score_3();
void show_score_4();
void show_score_5();
void show_score_6();
void show_score_7();
void show_score_8();
void show_score_9();
void show_score_0();
void check_leaders();

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;
	float theta = 0.0f;

	/* register window class */
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "GLSample";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


	if (!RegisterClassEx(&wcex))
		return 0;

	/* create main window */
	hwnd = CreateWindowEx(0,
		"GLSample",
		"OpenGL Sample",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		high,
		NULL,
		NULL,
		hInstance,
		NULL);





	ShowWindow(hwnd, nCmdShow);

	/* enable OpenGL for the window */
	EnableOpenGL(hwnd, &hDC, &hRC);

	//Liders = fopen("C: / Users / gusar / Desktop / Liders.txt", "r");
	meteorit* tmp1;
	meteorit meteor_array[50];
	int i = 0;
	int j = 0;
	int k = 0;
	int h = 0;
	int t = 0;
	int d = 0;
	float corX = -1000;
	float corY = -1000;
	int index;
	int cadr = 0;
	int flag = 0;
	int array_score[4];
	for (int i = 0; i < 4; i++)
		array_score[i] = 0;
	i = rand();
	srand(i);
	Bullet bull_array[10];
	for (j = 0; j < 10; j++)
	{
		bull_array[j].bx = 3;
		bull_array[j].by = 3;
	}
	//glLoadIdentity();
	//srand(time(NULL));


	for (i = 0; i < 50; i++)
	{
		meteorInit(&meteor_array[i]);
		meteor_array[i].my = meteor_array[i].my + i * 0.2;
	}

	meteorHealthInit(&meteorH);



	Space_Ship_Init(&ship, 0, -0.9, 0.1);
	read_leaders();


	int Myseed = rand();

	/* program main loop */

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   �������� ���� ����    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (!bQuit)
	{

		/* check for messages */
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* handle or dispatch messages */
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{


			if (enterUserName == 0)
			{
				ShowEnterNameMenu();
				SwapBuffers(hDC);
				continue;
			}
			if (enterUserName == 1)  //���� ����� ��� 
			{


				glClearColor(0.1f, 0.1f, 0.18f, 0.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				if (flagLeaders == 1)  // ���� ������ �� ������ �������
				{
					flagstart = 2;
					ShowLidersMenu();
					SwapBuffers(hDC);
					continue;

				}
				if (flagLeaders == 0)
				{
					flagstart == 0;
				}
				if (flagstart == 0)
				{
					ShowMenu();
					SwapBuffers(hDC);
					continue;
				}
				if (flagstart == 1)                // ���� ������ �� ������ ����� (����������� ����)
				{
					/* OpenGL animation code goes here */
					glClearColor(0.1f, 0.1f, 0.18f, 0.0f);
					glClear(GL_COLOR_BUFFER_BIT);

					if (Health == 3)
						show_Heatlh3();
					if (Health == 2)
						show_Heatlh2();
					if (Health == 1)
						show_Heatlh1();

					// ������ ��������������� ����� (������� )  
					glBegin(GL_LINES);
					glColor3f(0.8, 0, 0);

					glVertex2f(-1, 0);
					glVertex2f(1, 0);

					glVertex2f(0, 1);
					glVertex2f(0, -1);

					glColor3f(0.8, 1, 0);

					glVertex2f(-0.778, 1);
					glVertex2f(-0.778, -1);

					glVertex2f(-0.556, 1);
					glVertex2f(-0.556, -1);

					glVertex2f(-0.334, 1);
					glVertex2f(-0.334, -1);

					glVertex2f(-0.112, 1);
					glVertex2f(-0.112, -1);

					glVertex2f(0.108, 1);
					glVertex2f(0.108, -1);

					glVertex2f(0.330, 1);
					glVertex2f(0.330, -1);

					glVertex2f(0.552, 1);
					glVertex2f(0.552, -1);

					glVertex2f(0.774, 1);
					glVertex2f(0.774, -1);

					glVertex2f(0.778, 1);
					glVertex2f(0.778, -1);

					glEnd();
					// ��������� �������� (�������)


					if ((flag == 1) && (sbrosGameOver < 3000)) //���������� ���� ���������
					{

						glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
						glClear(GL_COLOR_BUFFER_BIT);
						showGameOver();
						SwapBuffers(hDC);
						sbrosGameOver++;
						continue;

					}
					if (sbrosGameOver == 3000)   // ������ 3000 ������ � ��������� ����� ���� ���������, �������� �������� ���������� 
					{
						flag = 0;
						flagstart = 0;
						sbrosGameOver = 0;
						count = 0;
						Health = 3;
						NUMLVL = 1;
						numLVL(yLVL);
						yLVL = 0.9;
						score = 0;
						meteorHealthInit(&meteorH);
						Space_Ship_Init(&ship, -0.1, -0.9, 0.1);
						for (i = 0; i < 50; i++)
						{
							meteorInit(&meteor_array[i]);
							meteor_array[i].my = meteor_array[i].my + i * 0.2;
						}
						speed_meteor = 0.009;
						continue;

					}

					//showSEM();
					srand(Myseed);
					for (int i = 0; i < 100; i++)
					{
						glColor3f(1.0, 1.0, 1.0);
						ShowQ(getrand(), getrand(), 0.010);
					}
					ShowQ(-0.85, 0.85, 0.005);
					ShowQ(-0.86, 0.85, 0.005);
					ShowQ(-0.855, 0.855, 0.005);
					ShowQ(-0.855, 0.86, 0.005);
					ShowQ(-0.855, 0.865, 0.005);


					yLVL = yLVL - speed_meteor - 0.0015;

					Show_LVLE(yLVL);
					numLVL(yLVL);


					Space_Ship_Move(&ship, 'A', 'D', 'W', -1, 1);
					move_meteorHealth(&meteorH);

					Space_Ship_Show(ship);
					k++;
					for (j = 0; j < 10; j++)
					{
						if ((GetKeyState('W') < 0) && (bull_array[j].bx == 3) && k > 12)
						{
							Bullet_Init(&bull_array[j], 0.05);
							k = 0;
							break;
							//Bullet_Move(&Bull);
							//Bullet_Show(Bull, ship);
						}
					}
					for (j = 0; j < 10; j++)
					{
						if (bull_array[j].bx != 3)
						{
							Bullet_Move(&bull_array[j]);
							Bullet_Show(bull_array[j], ship);
						}
					}


					take_digitals(array_score);
					glPushMatrix();
					for (int i = 0; i < 4; i++)
					{
						if (array_score[i] == 1)
							show_score_1();
						if (array_score[i] == 2)
							show_score_2();
						if (array_score[i] == 3)
							show_score_3();
						if (array_score[i] == 4)
							show_score_4();
						if (array_score[i] == 5)
							show_score_5();
						if (array_score[i] == 6)
							show_score_6();
						if (array_score[i] == 7)
							show_score_7();
						if (array_score[i] == 8)
							show_score_8();
						if (array_score[i] == 9)
							show_score_9();
						if (array_score[i] == 0)
							show_score_0();
						glTranslatef(-0.1, 0.0, 0.0);
					}
					glPopMatrix();
					for (h = 0; h < 50; h++)
					{
						i = rand();
						srand(i);

						move_meteorit(&meteor_array[h]);
						if (checkGameOver(meteor_array[h]) == 0)
						{
							meteor_array[h].my = 2;
							Health--;
							if (Health == 0)
							{
								flag = 1;
								check_leaders();
								break;
							}
						}
					}
					if ((checkHealth(meteorH)) == 0)
					{
						if (Health < 3)
							Health++;
						meteorHealthInit(&meteorH);
					}

					//move_meteorit(&meteor_array[0]);
					//for (t=0;t<10;t++)
					//shootCheck(&bull_array[t], &meteor_array[0]);
					h = 0;

					for (t = 0; t < 10; t++)
						for (d = 0; d < 50; d++)
						{
							tmp1 = shootCheck(&bull_array[t], &meteor_array[d]);
							if (tmp1->mx != -1000)
							{
								corX = tmp1->mx;
								corY = tmp1->my;

							}

						}
					if (cadr < 80 && corX != -1000)
					{
						showAnimation(corX, corY + 0.9);
						cadr++;
					}
					if (cadr == 10)
					{
						cadr = 0;
						corX = -1000;
						corY = -1000;
					}
					if (count == 50)
					{
						for (i = 0; i < 50; i++)
						{
							meteorInit(&meteor_array[i]);
							meteor_array[i].my = meteor_array[i].my + i * 0.2;
						}
						meteorHealthInit(&meteorH);
						count = 0;
						speed_meteor += 0.0025;
						yLVL = 0.9;
						NUMLVL++;

					}
				}
				//ShowMenu();
				SwapBuffers(hDC);



				Sleep(1);
			}
		}
	}

	/* shutdown OpenGL */
	DisableOpenGL(hwnd, hDC, hRC);

	/* destroy the window explicitly */
	DestroyWindow(hwnd);

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN:
		for (int i = 0; i < btnCnt; i++)
			if (PointINButton(LOWORD(lParam), HIWORD(lParam), btn[i]))
			{
				if (strcmp(btn[i].name, "quit") == 0)
					PostQuitMessage(0);
				//flagstart = 1;
				if (strcmp(btn[i].name, "start") == 0)
					flagstart = 1;
				//PostQuitMessage(0);
				if (strcmp(btn[i].name, "lider") == 0)
				{
					flagLeaders = 1;
				}
			}


		for (int i = 0; i < btnCntEnter; i++)
			if (PointINButtonEnter(LOWORD(lParam), HIWORD(lParam), btnEnter[i]))
			{
				if (strcmp(btnEnter[i].name, "btnA") == 0)
				{
					UserName[Iname] = 'A';
					Iname++;
				}
				if (strcmp(btnEnter[i].name, "btnB") == 0)
				{
					UserName[Iname] = 'B';
					Iname++;
				}
				if (strcmp(btnEnter[i].name, "btnC") == 0)
				{
					UserName[Iname] = 'C';
					Iname++;
				}
				if (strcmp(btnEnter[i].name, "btn1") == 0)
				{
					UserName[Iname] = '1';
					Iname++;
				}
				if (strcmp(btnEnter[i].name, "btn2") == 0)
				{
					UserName[Iname] = '2';
					Iname++;
				}
				if (strcmp(btnEnter[i].name, "btn3") == 0)
				{

					UserName[Iname] = '3';
					Iname++;
				}

				if (strcmp(btnEnter[i].name, "enter") == 0)
				{
					if (Iname > 0)
						enterUserName = 1;
				}

			}
		if (PointINLidersButton(LOWORD(lParam), HIWORD(lParam), btnLiders))
		{
			if (strcmp(btnLiders.name, "back") == 0)
			{
				flagLeaders = 0;
				flagstart = 0;
			}
		}
		break;


	case WM_MOUSEMOVE:
		for (int i = 0; i < btnCnt; i++)
			btn[i].hover = PointINButton(LOWORD(lParam), HIWORD(lParam), btn[i]);

		for (int i = 0; i < btnCntEnter; i++)
			btnEnter[i].hover = PointINButtonEnter(LOWORD(lParam), HIWORD(lParam), btnEnter[i]);


		btnLiders.hover = PointINLidersButton(LOWORD(lParam), HIWORD(lParam), btnLiders);



		break;

	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
	}
	break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	/* get the device context (DC) */
	*hDC = GetDC(hwnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);

	SetPixelFormat(*hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
	*hRC = wglCreateContext(*hDC);

	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}

void meteorInit(meteorit* met)
{
	int j = rand() % 9;
	float result = 0.11;

	result = (result + 0.222 * j) - 1;
	met->mx = result;
	met->my = 0.2;
	met->msize = 0.2 / 5;
}
void move_meteorit(meteorit* meteor)
{

	meteor->my = meteor->my - speed_meteor;
	if (meteor->my < -2.0)
	{
		meteor->mx = 3;
		meteor->my = 100;
		count++;
	}
	glPushMatrix();
	glTranslatef(0.0, meteor->my + 0.9, 0.0);
	show_meteor(meteor->mx, 0);
	glPopMatrix();

}




void showGameOver()
{

	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.95, 0.2);
	glVertex2f(-0.95, 0.4);
	glVertex2f(-0.9, 0.6);
	glVertex2f(-0.6, 0.6);
	glVertex2f(-0.6, 0.5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(-0.9, 0.4);
	glVertex2f(-0.9, 0.2);
	glVertex2f(-0.8, 0.1);
	glVertex2f(-0.7, 0.1);
	glVertex2f(-0.7, 0.2);
	glVertex2f(-0.8, 0.2);
	glVertex2f(-0.8, 0.3);
	glVertex2f(-0.6, 0.3);
	glVertex2f(-0.6, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.3, 0.6);
	glVertex2f(-0.2, 0.6);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.1, 0.0);
	glVertex2f(-0.2, 0.2);
	glVertex2f(-0.3, 0.2);
	glVertex2f(-0.4, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.3, 0.3);
	glVertex2f(-0.3, 0.4);
	glVertex2f(-0.2, 0.4);
	glVertex2f(-0.2, 0.3);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(0.05, 0.0);
	glVertex2f(0.05, 0.6);
	glVertex2f(0.2, 0.4);
	glVertex2f(0.3, 0.4);
	glVertex2f(0.45, 0.6);
	glVertex2f(0.45, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.3, 0.2);
	glVertex2f(0.2, 0.2);
	glVertex2f(0.1, 0.3);
	glVertex2f(0.1, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.6, 0.2);
	glVertex2f(0.6, 0.5);
	glVertex2f(0.7, 0.6);
	glVertex2f(0.8, 0.6);
	glVertex2f(0.9, 0.5);
	glVertex2f(0.9, 0.3);
	glVertex2f(0.7, 0.3);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.9, 0.1);
	glVertex2f(0.9, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.7, 0.4);
	glVertex2f(0.7, 0.5);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.8, 0.4);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.6, -0.1);
	glVertex2f(-0.55, -0.3);
	glVertex2f(-0.55, -0.5);
	glVertex2f(-0.6, -0.7);
	glVertex2f(-0.9, -0.7);
	glVertex2f(-0.95, -0.5);
	glVertex2f(-0.95, -0.3);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(-0.75, -0.2);
	glVertex2f(-0.6, -0.3);
	glVertex2f(-0.6, -0.5);
	glVertex2f(-0.75, -0.6);
	glVertex2f(-0.9, -0.5);
	glVertex2f(-0.9, -0.3);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(-0.5, -0.1);
	glVertex2f(-0.4, -0.1);
	glVertex2f(-0.3, -0.6);
	glVertex2f(-0.2, -0.6);
	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.0, -0.1);
	glVertex2f(-0.1, -0.7);
	glVertex2f(-0.4, -0.7);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(0.8 - 0.5, 0.0 - 0.7);
	glVertex2f(0.6 - 0.5, 0.2 - 0.7);
	glVertex2f(0.6 - 0.5, 0.5 - 0.7);
	glVertex2f(0.7 - 0.5, 0.6 - 0.7);
	glVertex2f(0.8 - 0.5, 0.6 - 0.7);
	glVertex2f(0.9 - 0.5, 0.5 - 0.7);
	glVertex2f(0.9 - 0.5, 0.3 - 0.7);
	glVertex2f(0.7 - 0.5, 0.3 - 0.7);
	glVertex2f(0.7 - 0.5, 0.2 - 0.7);
	glVertex2f(0.8 - 0.5, 0.1 - 0.7);
	glVertex2f(0.9 - 0.5, 0.1 - 0.7);
	glVertex2f(0.9 - 0.5, 0.0 - 0.7);
	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.7 - 0.5, 0.4 - 0.7);
	glVertex2f(0.7 - 0.5, 0.5 - 0.7);
	glVertex2f(0.8 - 0.5, 0.5 - 0.7);
	glVertex2f(0.8 - 0.5, 0.4 - 0.7);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 0.0);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.9, -0.1);
	glVertex2f(0.9, -0.4);
	glVertex2f(0.8, -0.4);
	glVertex2f(0.9, -0.7);
	glVertex2f(0.8, -0.7);
	glVertex2f(0.7, -0.4);
	glVertex2f(0.6, -0.4);
	glVertex2f(0.6, -0.7);
	glVertex2f(0.5, -0.7);
	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.6, -0.2);
	glVertex2f(0.8, -0.2);
	glVertex2f(0.8, -0.3);
	glVertex2f(0.6, -0.3);

	glEnd();
}
void show_meteor(float x, float y)
{
	glPushMatrix();
	//glRotatef(270, 0, 0, 1);

	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);  glVertex2f(x - 0.55 / 5, y - 0.15 / 5);
	glColor3f(1.0f, 1.0f, 1.0f);  glVertex2f(x - 0.55 / 5, y + 0.15 / 5);
	glColor3f(1.0f, 1.0f, 1.0f);  glVertex2f(x + 0.55 / 5, y + 0.15 / 5);
	glColor3f(1.0f, 1.0f, 1.0f);  glVertex2f(x + 0.55 / 5, y - 0.15 / 5);

	glEnd();
	glLineWidth(1.5);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - 0.5 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.3 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.45 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.42 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.42 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.38 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.38 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.35 / 5, y - 0.1 / 5);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - 0.25 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.15 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.15 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.25 / 5, y - 0.1 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - 0.05 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y - 0.1 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 0.2 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.2 / 5, y + 0.1 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 0.25 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.3 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.3 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.35 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.25 / 5, y + 0.0 / 5);
	glVertex2f(x + 0.35 / 5, y + 0.0 / 5);

	glEnd();
	glPopMatrix();
}   //


meteorit* shootCheck(Bullet* bull, meteorit* meteor)
{
	meteorit* tmp = (meteorit*)malloc(sizeof(meteorit));

	tmp->mx = -1000;
	tmp->my = -1000;
	if ((bull->bx + bull->bsize >= meteor->mx - 0.11) && (bull->bx <= meteor->mx + 0.11))
		if ((bull->by + bull->bsize <= meteor->my + 0.1 / 5 + 0.7) && (bull->by + bull->bsize >= meteor->my - 0.1 / 5 + 0.7))
		{
			bull->bx = 3;
			tmp->mx = meteor->mx;
			tmp->my = meteor->my;
			meteor->mx = 3;
			meteor->my = 100;
			count++;
			score++;
			return tmp;
		}
	return tmp;
}
void showAnimation(float x, float y)
{
	glPushMatrix();
	//glRotatef(270, 0, 0, 1);

	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);  glVertex2f(x - 0.55 / 5, y - 0.15 / 5);
	glColor3f(0.0f, 0.0f, 0.0f);  glVertex2f(x - 0.55 / 5, y + 0.15 / 5);
	glColor3f(0.0f, 0.0f, 0.0f);  glVertex2f(x + 0.55 / 5, y + 0.15 / 5);
	glColor3f(0.0f, 0.0f, 0.0f);  glVertex2f(x + 0.55 / 5, y - 0.15 / 5);

	glEnd();
	glLineWidth(1.5);

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x - 0.4 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.3 / 5, y - 0.05 / 5);
	glVertex2f(x - 0.4 / 5, y - 0.0 / 5);
	glVertex2f(x - 0.3 / 5, y + 0.05 / 5);
	glVertex2f(x - 0.4 / 5, y + 0.1 / 5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x - 0.25 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.2 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.2 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.15 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.25 / 5, y + 0.0 / 5);
	glVertex2f(x - 0.15 / 5, y - 0.0 / 5);

	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x - 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.05 / 5, y + 0.0 / 5);
	glVertex2f(x + 0.05 / 5, y + 0.0 / 5);
	glVertex2f(x + 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y - 0.1 / 5);


	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x + 0.2 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.2 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.0 / 5);
	glVertex2f(x + 0.2 / 5, y + 0.0 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x + 0.3 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.3 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.25 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.35 / 5, y + 0.1 / 5);


	glEnd();
	glPopMatrix();
}

void take_digitals(int* array)
{

	int tmp = score;
	int i = 0;
	for (int i = 0; i < 4; i++)
	{
		array[i] = tmp % 10;
		tmp = tmp / 10;

	}

}

void show_Heatlh3()
{
	glBegin(GL_LINES);
	glColor3f(0.8, 0, 0);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.9, 1);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.9, 1);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.8, 1);

	glVertex2f(0.8, 1);
	glVertex2f(0.85, 0.98);

	glVertex2f(0.85, 0.98);
	glVertex2f(0.9, 1);



	glVertex2f(0.85 - 0.1, 0.9);
	glVertex2f(0.9 - 0.1, 1);

	glVertex2f(0.85 - 0.1, 0.9);
	glVertex2f(0.9 - 0.1, 1);

	glVertex2f(0.85 - 0.1, 0.9);
	glVertex2f(0.8 - 0.1, 1);

	glVertex2f(0.8 - 0.1, 1);
	glVertex2f(0.85 - 0.1, 0.98);

	glVertex2f(0.85 - 0.1, 0.98);
	glVertex2f(0.9 - 0.1, 1);




	glVertex2f(0.85 - 0.2, 0.9);
	glVertex2f(0.9 - 0.2, 1);

	glVertex2f(0.85 - 0.2, 0.9);
	glVertex2f(0.9 - 0.2, 1);

	glVertex2f(0.85 - 0.2, 0.9);
	glVertex2f(0.8 - 0.2, 1);

	glVertex2f(0.8 - 0.2, 1);
	glVertex2f(0.85 - 0.2, 0.98);

	glVertex2f(0.85 - 0.2, 0.98);
	glVertex2f(0.9 - 0.2, 1);

	glEnd();
}

void show_Heatlh1()
{
	glBegin(GL_LINES);
	glColor3f(0.8, 0, 0);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.9, 1);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.9, 1);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.8, 1);

	glVertex2f(0.8, 1);
	glVertex2f(0.85, 0.98);

	glVertex2f(0.85, 0.98);
	glVertex2f(0.9, 1);





	glEnd();
}


void show_Heatlh2()
{
	glBegin(GL_LINES);
	glColor3f(0.8, 0, 0);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.9, 1);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.9, 1);

	glVertex2f(0.85, 0.9);
	glVertex2f(0.8, 1);

	glVertex2f(0.8, 1);
	glVertex2f(0.85, 0.98);

	glVertex2f(0.85, 0.98);
	glVertex2f(0.9, 1);



	glVertex2f(0.85 - 0.1, 0.9);
	glVertex2f(0.9 - 0.1, 1);

	glVertex2f(0.85 - 0.1, 0.9);
	glVertex2f(0.9 - 0.1, 1);

	glVertex2f(0.85 - 0.1, 0.9);
	glVertex2f(0.8 - 0.1, 1);

	glVertex2f(0.8 - 0.1, 1);
	glVertex2f(0.85 - 0.1, 0.98);

	glVertex2f(0.85 - 0.1, 0.98);
	glVertex2f(0.9 - 0.1, 1);

	glEnd();
}
void check_leaders(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (score > chel[i].ochko)
		{
			for (int j = 4; j > i; j--)
			{
				chel[j].ochko = chel[j - 1].ochko;
				strcpy(chel[j].name, chel[j - 1].name);
			}
			chel[i].ochko = score;
			strcpy(chel[i].name, UserName);
			chel[i].name[strlen(chel[i].name) + 1] = 0;
			chel[i].name[strlen(chel[i].name)] = ':';
			break;
		}
	}
	Leaders = fopen("C:/Users/gusar/Desktop/Liders.txt", "w+");
	for (int j = 0; j < 5; j++)
	{
		fprintf(Leaders, "%s", chel[j].name);
		fprintf(Leaders, " %d\n", chel[j].ochko);
	}
	fclose(Leaders);
}
void printLeaders()
{
	int x = 750;
	int y = 50;
	int xn = 0;
	int yn = 50;
	glPushMatrix();
	for (int i = 0; i < 5; i++)
	{
		xn = 0;
		if (chel[i].ochko % 10 == 0)
		{
			print0(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 0)
		{
			print0(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 0)
		{
			print0(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 0)
		{
			print0(x - 120, y);
		}
		//-------------------------------------------------------     0

		if (chel[i].ochko % 10 == 1)
		{
			print1(x, y);


		}
		if ((chel[i].ochko % 100) / 10 == 1)
		{
			print1(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 1)
		{
			print1(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 1)
		{
			print1(x - 120, y);

		}
		//-------------------------------------------------------------- 1
		if (chel[i].ochko % 10 == 2)
		{
			print2(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 2)
		{
			print2(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 2)
		{
			print2(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 2)
		{
			print2(x - 120, y);

		}
		//------------------------------------------------------ 2
		if (chel[i].ochko % 10 == 3)
		{
			print3(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 3)
		{
			print3(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 3)
		{
			print3(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 3)
		{
			print3(x - 120, y);

		}
		// -------------------------------------------------- 3
		if (chel[i].ochko % 10 == 4)
		{
			print4(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 4)
		{
			print4(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 4)
		{
			print4(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 4)
		{
			print4(x - 120, y);

		}
		//------------------------------------------------- 4
		if (chel[i].ochko % 10 == 5)
		{
			print5(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 5)
		{
			print5(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 5)
		{
			print5(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 5)
		{
			print5(x - 120, y);
		}
		//--------------------------------------------------- 5
		if (chel[i].ochko % 10 == 6)
		{
			print6(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 6)
		{
			print6(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 6)
		{
			print6(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 6)
		{
			print6(x - 120, y);
		}
		//-------------------------------------------- 6
		if (chel[i].ochko % 10 == 7)
		{
			print7(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 7)
		{
			print7(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 7)
		{
			print7(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 7)
		{
			print7(x - 120, y);
		}
		////----------------------------------------------- 7
		if (chel[i].ochko % 10 == 8)
		{
			print8(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 8)
		{
			print8(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 8)
		{
			print8(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 8)
		{
			print8(x - 120, y);
		}
		////--------------------------------------------- 8
		if (chel[i].ochko % 10 == 9)
		{
			print9(x, y);

		}
		if ((chel[i].ochko % 100) / 10 == 9)
		{
			print9(x - 40, y);

		}
		if ((chel[i].ochko % 1000) / 100 == 9)
		{
			print9(x - 80, y);

		}
		if ((chel[i].ochko % 10000) / 1000 == 9)
		{
			print9(x - 120, y);
		}
		////---------------------------------------- 9
		for (int j = 0; j < 10; j++)
		{
			if (chel[i].name[j] == 'A')
			{
				printA(xn, y);
				xn = xn + 40;
			}
			if (chel[i].name[j] == 'B')
			{
				printB(xn + 5, y);
				xn = xn + 40;
			}
			if (chel[i].name[j] == 'C')
			{
				printC(xn + 5, y);
				xn = xn + 40;
			}
			if (chel[i].name[j] == '1')
			{
				print1(xn - 10, y);
				xn = xn + 20;
			}
			if (chel[i].name[j] == '2')
			{
				print2(xn, y);
				xn = xn + 40;
			}
			if (chel[i].name[j] == '3')
			{
				print3(xn, y);
				xn = xn + 45;
			}
			//xn = 0;


		}
		y = y + 70;


	}
	glPopMatrix();


}
void show_S(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex2f(235 + x, 110 + y);
	glVertex2f(210 + x, 110 + y);

	glVertex2f(210 + x, 110 + y);
	glVertex2f(210 + x, 140 + y);

	glVertex2f(210 + x, 140 + y);
	glVertex2f(235 + x, 140 + y);

	glVertex2f(235 + x, 140 + y);
	glVertex2f(235 + x, 170 + y);

	glVertex2f(235 + x, 170 + y);
	glVertex2f(210 + x, 170 + y);


	glEnd();
}
void show_T(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex2f(295 + x, 110 + y);
	glVertex2f(255 + x, 110 + y);

	glVertex2f(275 + x, 110 + y);
	glVertex2f(275 + x, 170 + y);
	glEnd();
}
void show_A(int x, int y) {
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex2f(325 + x, 110 + y);
	glVertex2f(300 + x, 170 + y);

	glVertex2f(325 + x, 110 + y);
	glVertex2f(350 + x, 170 + y);

	glVertex2f(310 + x, 140 + y);
	glVertex2f(340 + x, 140 + y);
	glEnd();
}
void show_R(int x, int y) {
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex2f(365 + x, 110 + y);
	glVertex2f(365 + x, 170 + y);

	glVertex2f(395 + x, 110 + y);
	glVertex2f(365 + x, 110 + y);

	glVertex2f(395 + x, 135 + y);
	glVertex2f(365 + x, 135 + y);

	glVertex2f(395 + x, 110 + y);
	glVertex2f(395 + x, 135 + y);

	glVertex2f(395 + x, 135 + y);
	glVertex2f(365 + x, 135 + y);

	glVertex2f(365 + x, 135 + y);
	glVertex2f(395 + x, 170 + y);

	glEnd();
}
void printQ(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(145 + x, 120 + y);
	glVertex2f(110 + x, 120 + y);

	glVertex2f(145 + x, 180 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(110 + x, 120 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(145 + x, 120 + y);
	glVertex2f(145 + x, 180 + y);

	glVertex2f(145 + x, 180 + y);
	glVertex2f(150 + x, 185 + y);

	glEnd();
}
void printU(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(145 + x, 180 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(110 + x, 120 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(145 + x, 120 + y);
	glVertex2f(145 + x, 180 + y);

	glEnd();
}
void printI(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);


	glVertex2f(110 + x, 120 + y);
	glVertex2f(110 + x, 180 + y);
	glEnd();
}
void printL(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);


	glVertex2f(110 + x, 120 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(140 + x, 180 + y);
	glVertex2f(110 + x, 180 + y);
	glEnd();
}
void printD(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(125 + x, 120 + y);
	glVertex2f(110 + x, 120 + y);

	glVertex2f(125 + x, 180 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(110 + x, 120 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(145 + x, 140 + y);
	glVertex2f(145 + x, 160 + y);

	glVertex2f(125 + x, 180 + y);
	glVertex2f(145 + x, 160 + y);

	glVertex2f(125 + x, 120 + y);
	glVertex2f(145 + x, 140 + y);

	glEnd();
}
void printE(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(140 + x, 120 + y);
	glVertex2f(110 + x, 120 + y);

	glVertex2f(140 + x, 145 + y);
	glVertex2f(110 + x, 145 + y);

	glVertex2f(140 + x, 180 + y);
	glVertex2f(110 + x, 180 + y);

	glVertex2f(110 + x, 120 + y);
	glVertex2f(110 + x, 180 + y);
	glEnd();
}
void print1(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(75 + x, 55 + y);
	glVertex2f(75 + x, 95 + y);

	glVertex2f(75 + x, 55 + y);
	glVertex2f(65 + x, 65 + y);

	glVertex2f(67 + x, 95 + y);
	glVertex2f(83 + x, 95 + y);
	glEnd();
}
void print0(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(80 + x, 55 + y);
	glVertex2f(80 + x, 95 + y);

	glVertex2f(55 + x, 95 + y);
	glVertex2f(80 + x, 95 + y);

	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);
	glEnd();
}
void print2(int x, int y)
{
	glBegin(GL_LINES);

	glColor3f(1, 0.2, 0.2);
	glVertex2f(65 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(80 + x, 55 + y);
	glVertex2f(85 + x, 60 + y);

	glVertex2f(85 + x, 60 + y);
	glVertex2f(85 + x, 70 + y);

	glVertex2f(85 + x, 70 + y);
	glVertex2f(80 + x, 75 + y);

	glVertex2f(80 + x, 75 + y);
	glVertex2f(70 + x, 75 + y);

	glVertex2f(70 + x, 75 + y);
	glVertex2f(65 + x, 80 + y);

	glVertex2f(65 + x, 80 + y);
	glVertex2f(65 + x, 95 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(65 + x, 95 + y);
	glEnd();
}
void print3(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(90 + x, 55 + y);
	glVertex2f(90 + x, 95 + y);

	glVertex2f(90 + x, 95 + y);
	glVertex2f(65 + x, 95 + y);

	glVertex2f(90 + x, 75 + y);
	glVertex2f(65 + x, 75 + y);

	glVertex2f(90 + x, 55 + y);
	glVertex2f(65 + x, 55 + y);

	glEnd();
}

void print4(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 75 + y);
	glVertex2f(55 + x, 55 + y);

	glVertex2f(55 + x, 75 + y);
	glVertex2f(75 + x, 75 + y);

	glVertex2f(75 + x, 95 + y);
	glVertex2f(75 + x, 55 + y);

	glEnd();
}
void print5(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(55 + x, 55 + y);
	glVertex2f(55 + x, 75 + y);

	glVertex2f(55 + x, 75 + y);
	glVertex2f(80 + x, 75 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(80 + x, 75 + y);

	glVertex2f(55 + x, 95 + y);
	glVertex2f(80 + x, 95 + y);


	glEnd();
}
void print6(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(55 + x, 95 + y);
	glVertex2f(80 + x, 95 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(80 + x, 75 + y);

	glVertex2f(55 + x, 75 + y);
	glVertex2f(80 + x, 75 + y);

	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glEnd();
}
void print7(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(80 + x, 55 + y);
	glVertex2f(55 + x, 95 + y);


	glEnd();
}
void print8(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(55 + x, 95 + y);
	glVertex2f(55 + x, 55 + y);

	glVertex2f(80 + x, 75 + y);
	glVertex2f(55 + x, 75 + y);

	glEnd();
}
void print9(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(80 + x, 95 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(55 + x, 75 + y);
	glVertex2f(55 + x, 55 + y);

	glVertex2f(80 + x, 75 + y);
	glVertex2f(55 + x, 75 + y);

	glEnd();
}
void printB(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(55 + x, 75 + y);
	glVertex2f(75 + x, 75 + y);

	glVertex2f(55 + x, 55 + y);
	glVertex2f(75 + x, 55 + y);

	glVertex2f(55 + x, 95 + y);
	glVertex2f(75 + x, 95 + y);

	glVertex2f(75 + x, 75 + y);
	glVertex2f(80 + x, 80 + y);

	glVertex2f(75 + x, 95 + y);
	glVertex2f(80 + x, 90 + y);

	glVertex2f(75 + x, 55 + y);
	glVertex2f(80 + x, 60 + y);

	glVertex2f(75 + x, 75 + y);
	glVertex2f(80 + x, 70 + y);

	glVertex2f(80 + x, 70 + y);
	glVertex2f(80 + x, 60 + y);

	glVertex2f(80 + x, 80 + y);
	glVertex2f(80 + x, 90 + y);
	glEnd();
}
void printC(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2f(55 + x, 55 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(55 + x, 55 + y);
	glVertex2f(80 + x, 55 + y);

	glVertex2f(55 + x, 95 + y);
	glVertex2f(80 + x, 95 + y);
	glEnd();
}
void printA(int x, int y)
{
	glBegin(GL_LINES);
	glNormal3f(1, 0, 0);
	glVertex2f(75 + x, 55 + y);
	glVertex2f(95 + x, 95 + y);

	glVertex2f(75 + x, 55 + y);
	glVertex2f(55 + x, 95 + y);

	glVertex2f(65 + x, 75 + y);
	glVertex2f(85 + x, 75 + y);
	glEnd();
}

void show_score_1()
{
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(0.2 - 0.7, 0.15 + 0.8);
	glVertex2f(0.2 - 0.7, 0 + 0.8);

	glVertex2f(0.2 - 0.7, 0.15 + 0.8);
	glVertex2f(0.15 - 0.7, 0.1 + 0.8);

	//glVertex2f(0.1, 0);
	//glVertex2f(0.15, 0);

	glEnd();
	glPopMatrix();

}
void show_score_2()
{
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex2f(0.15 - 0.7, 0.15 + 0.8);
	glVertex2f(0.225 - 0.7, 0.15 + 0.8);

	glVertex2f(0.225 - 0.7, 0.15 + 0.8);
	glVertex2f(0.25 - 0.7, 0.12 + 0.8);

	glVertex2f(0.25 - 0.7, 0.12 + 0.8);
	glVertex2f(0.225 - 0.7, 0.09 + 0.8);

	glVertex2f(0.225 - 0.7, 0.09 + 0.8);
	glVertex2f(0.15 - 0.7, 0.09 + 0.8);

	glVertex2f(0.15 - 0.7, 0.09 + 0.8);
	glVertex2f(0.15 - 0.7, 0 + 0.8);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.25 - 0.7, 0 + 0.8);
	glEnd();
	glPopMatrix();

}
void show_score_3()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);


	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.8);

	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.25 - 0.7, 0.0375 + 0.8);

	glVertex2f(0.25 - 0.7, 0.0375 + 0.8);
	glVertex2f(0.21 - 0.7, 0.075 + 0.8);

	glVertex2f(0.21 - 0.7, 0.075 + 0.8);
	glVertex2f(0.25 - 0.7, 0.1125 + 0.8);

	glVertex2f(0.25 - 0.7, 0.1125 + 0.8);
	glVertex2f(0.225 - 0.7, 0.15 + 0.8);

	glVertex2f(0.225 - 0.7, 0.15 + 0.8);
	glVertex2f(0.15 - 0.7, 0.15 + 0.8);
	glEnd();
}
void show_score_4()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glVertex2f(0.15 - 0.7, 0 + 0.875);
	glVertex2f(0.225 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.875);
	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glEnd();

}
void show_score_5()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.8);

	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.875);

	glVertex2f(0.225 - 0.7, 0 + 0.875);
	glVertex2f(0.15 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glVertex2f(0.15 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glVertex2f(0.225 - 0.7, 0 + 0.95);



	glEnd();
}
void show_score_6()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.8);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.15 - 0.7, 0 + 0.95);

	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.875);
	glVertex2f(0.225 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glVertex2f(0.225 - 0.7, 0 + 0.95);



	glEnd();
}
void show_score_7()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glVertex2f(0.225 - 0.7, 0 + 0.95);
	glVertex2f(0.15 - 0.7, 0 + 0.95);






	glEnd();
}
void show_score_8()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.8);

	glVertex2f(0.15 - 0.7, 0 + 0.875);
	glVertex2f(0.225 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.15 - 0.7, 0 + 0.95);

	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glEnd();
}
void show_score_9()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex2f(0.15 - 0.7, 0 + 0.875);
	glVertex2f(0.15 - 0.7, 0 + 0.95);

	glVertex2f(0.15 - 0.7, 0 + 0.875);
	glVertex2f(0.225 - 0.7, 0 + 0.875);

	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.95);


	glEnd();
}
void show_score_0()
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);


	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.8);

	glVertex2f(0.15 - 0.7, 0 + 0.8);
	glVertex2f(0.15 - 0.7, 0 + 0.95);

	glVertex2f(0.225 - 0.7, 0 + 0.8);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glVertex2f(0.15 - 0.7, 0 + 0.95);
	glVertex2f(0.225 - 0.7, 0 + 0.95);

	glEnd();
}

void Show_LVL(float y)
{

	glBegin(GL_QUADS);
	glVertex2f(-0.3, y);
	glVertex2f(0.3, y);
	glVertex2f(0.3, y + 0.1);
	glVertex2f(-0.3, y + 0.1);
	glEnd();
}
void Show_LVLE(float ly)
{
	glBegin(GL_LINES);

	glVertex2f(-0.2, ly + 0.15);
	glVertex2f(-0.2, ly);

	glVertex2f(-0.2, ly);
	glVertex2f(-0.125, ly);

	glVertex2f(-0.1, ly + 0.15);
	glVertex2f(-0.05, ly);

	glVertex2f(-0.05, ly);
	glVertex2f(0, ly + 0.15);


	glVertex2f(-0.2 + 0.25, ly + 0.15);
	glVertex2f(-0.2 + 0.25, ly);

	glVertex2f(-0.2 + 0.25, ly);
	glVertex2f(-0.125 + 0.25, ly);
	glEnd();
}
void numLVL(float ly)
{
	if (NUMLVL == 1)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(0.2, ly + 0.15);
		glVertex2f(0.2, ly);

		glVertex2f(0.2, ly + 0.15);
		glVertex2f(0.15, ly + 0.1);

		glVertex2f(0.1, ly);
		glVertex2f(0.15, ly);

		glEnd();
	}

	if (NUMLVL == 2)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);

		glVertex2f(0.15, ly + 0.15);
		glVertex2f(0.225, ly + 0.15);

		glVertex2f(0.225, ly + 0.15);
		glVertex2f(0.25, ly + 0.12);

		glVertex2f(0.25, ly + 0.12);
		glVertex2f(0.225, ly + 0.09);

		glVertex2f(0.225, ly + 0.09);
		glVertex2f(0.15, ly + 0.09);

		glVertex2f(0.15, ly + 0.09);
		glVertex2f(0.15, ly);

		glVertex2f(0.15, ly);
		glVertex2f(0.25, ly);
		glEnd();
	}
	if (NUMLVL == 3)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);


		glVertex2f(0.15, ly);
		glVertex2f(0.225, ly);

		glVertex2f(0.225, ly);
		glVertex2f(0.25, ly + 0.0375);

		glVertex2f(0.25, ly + 0.0375);
		glVertex2f(0.21, ly + 0.075);

		glVertex2f(0.21, ly + 0.075);
		glVertex2f(0.25, ly + 0.1125);

		glVertex2f(0.25, ly + 0.1125);
		glVertex2f(0.225, ly + 0.15);

		glVertex2f(0.225, ly + 0.15);
		glVertex2f(0.15, ly + 0.15);
		glEnd();
	}
	if (NUMLVL == 4)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(0.225, ly + 0);
		glVertex2f(0.225, ly + 0.15);

		glVertex2f(0.15, ly + 0.075);
		glVertex2f(0.225, ly + 0.075);

		glVertex2f(0.15, ly + 0.075);
		glVertex2f(0.15, ly + 0.15);
		glEnd();
	}
	if (NUMLVL == 5)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.225, ly + 0.0);

		glVertex2f(0.225, ly + 0.0);
		glVertex2f(0.225, ly + 0.075);

		glVertex2f(0.225, ly + 0.075);
		glVertex2f(0.15, ly + 0.075);

		glVertex2f(0.15, ly + 0.15);
		glVertex2f(0.15, ly + 0.075);

		glVertex2f(0.15, ly + 0.15);
		glVertex2f(0.225, ly + 0.15);

		glEnd();
	}
	if (NUMLVL == 6)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.225, ly + 0.0);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.15, ly + 0.15);

		glVertex2f(0.225, ly + 0.0);
		glVertex2f(0.225, ly + 0.075);

		glVertex2f(0.15, ly + 0.075);
		glVertex2f(0.225, ly + 0.075);

		glVertex2f(0.15, ly + 0.15);
		glVertex2f(0.225, ly + 0.15);



		glEnd();
	}
	if (NUMLVL == 7)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.225, ly + 0.15);

		glVertex2f(0.225, ly + 0.15);
		glVertex2f(0.15, ly + 0.15);
	}
	if (NUMLVL == 8)
	{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.225, ly + 0.0);

		glVertex2f(0.15, ly + 0.075);
		glVertex2f(0.225, ly + 0.075);

		glVertex2f(0.15, ly + 0.15);
		glVertex2f(0.225, ly + 0.15);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.15, ly + 0.15);

		glVertex2f(0.225, ly + 0);
		glVertex2f(0.225, ly + 0.15);

		glVertex2f(0.15, ly + 0.0);
		glVertex2f(0.225, ly + 0.0);


		glEnd();
	}
}

void ShowQ(float x, float y, float size)
{
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x, y + size);
	glVertex2f(x + size, y + size);
	glVertex2f(x + size, y);
	glEnd();
}
void show_space_ship(float x, float y, float size)
{

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
	glVertex2f(x + size / 2, y);
	glVertex2f(x + size / 2, y + (2.5 * size));
	glVertex2f(x, y + (2.5 * size));
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(x, y + (2.5 * size));
	glColor3f(0.0, 1.0, 0.0); glVertex2f(x - size / 2, y + size);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(x, y + size);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(x + size / 2, y + (2.5 * size));
	glColor3f(0.0, 1.0, 0.0); glVertex2f(x + size, y + size);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(x + size / 2, y + size);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(x, y + size);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(x - size, y);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(x, y);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(x + size / 2, y + size);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(x + (1.5 * size), y);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(x + size / 2, y);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9, 0.5, 0.0); glVertex2f(x, y);
	glColor3f(0.9, 0.5, 0.0); glVertex2f(x - (0.3 * size), y - (0.3 * size));
	glColor3f(0.9, 0.5, 0.0); glVertex2f(x, y - (0.3 * size));
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9, 0.5, 0.0); glVertex2f(x + size / 2, y);
	glColor3f(0.9, 0.5, 0.0); glVertex2f(x + (0.3 * size) + size / 2, y - (0.3 * size));
	glColor3f(0.9, 0.5, 0.0); glVertex2f(x + size / 2, y - (0.3 * size));
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.9, 1.5, 0.0); glVertex2f(x + size / 4, y);
	glColor3f(1.9, 1.5, 0.0); glVertex2f(x + size / 6, y - (0.3 * size));
	glColor3f(1.9, 1.5, 0.0); glVertex2f(x + size / 4, y - (0.3 * size));
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 0.0); glVertex2f(x + size / 4, y);
	glColor3f(1.0, 1.0, 0.0); glVertex2f(x + size / 3, y - (0.3 * size));
	glColor3f(1.0, 1.0, 0.0); glVertex2f(x + size / 4, y - (0.3 * size));
	glEnd();
	glPopMatrix();
}
void showDopsaHealth(float x, float y)
{
	glPushMatrix();
	//glRotatef(270, 0, 0, 1);

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 1.0f);  glVertex2f(x - 0.55 / 5, y - 0.15 / 5);
	glColor3f(0.0f, 1.0f, 1.0f);  glVertex2f(x - 0.55 / 5, y + 0.15 / 5);
	glColor3f(1.0f, 0.0f, 1.0f);  glVertex2f(x + 0.55 / 5, y + 0.15 / 5);
	glColor3f(0.0f, 1.0f, 1.0f);  glVertex2f(x + 0.55 / 5, y - 0.15 / 5);

	glEnd();
	glLineWidth(1.5);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - 0.5 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.3 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.45 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.42 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.42 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.38 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.38 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.35 / 5, y - 0.1 / 5);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - 0.25 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.15 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.15 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.25 / 5, y - 0.1 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - 0.05 / 5, y - 0.1 / 5);
	glVertex2f(x - 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x - 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.05 / 5, y - 0.1 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 0.2 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.1 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.2 / 5, y + 0.1 / 5);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 0.25 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.3 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.3 / 5, y + 0.1 / 5);
	glVertex2f(x + 0.35 / 5, y - 0.1 / 5);
	glVertex2f(x + 0.25 / 5, y + 0.0 / 5);
	glVertex2f(x + 0.35 / 5, y + 0.0 / 5);

	glEnd();
	glPopMatrix();
}