#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>

//实际为800*600，但以20像素为一单位
#define MAP_WIDTH 40
#define MAP_LENGTH 30

//蛇的结构体（双向链表）
typedef struct snake
{
	int position_x;
	int position_y;
	struct snake* pre;
	struct snake* next;
}sn;

sn* head;//蛇头
sn* tail;//蛇尾
sn* p = NULL;//用于遍历

//加入节点
void join()
{
	p = (sn*)malloc(sizeof(sn));
	p->pre = tail;
	p->next = NULL;
	p->position_x = tail->position_x;
	p->position_y = tail->position_y;
	tail = p;
	p = NULL;
}

//删除尾节点
void dele()
{
	p = (tail->pre);
	free(tail);
	tail = p;
	tail->next = NULL;
	p = NULL;
}

//食物结构体
typedef struct
{
	int position_x;
	int position_y;
	//食物种类 0为基础型，1为地雷，2为毒草，3为特效草
	int type;
}fd;

//排名结构体
typedef struct list
{
	char name[20];
	int score;
}lt;

//移动光标(现已废弃)
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}


//4个食物开局结为基础食物
fd* fd1 = (fd*)malloc(sizeof(fd));
fd* fd2 = (fd*)malloc(sizeof(fd));
fd* fd3 = (fd*)malloc(sizeof(fd));
fd* fd4 = (fd*)malloc(sizeof(fd));


int speed = 150;//sleep time(ms)
int score = 0;//分数
int choose = 0;//界面选择用

int go_position = 's';//初始前进方向

//蛇头4个方向及蛇身图片
IMAGE headw, heada, heads, headd, snake, map, stop, menu0;
//4种食物
IMAGE food0, food1, food2, food3;

