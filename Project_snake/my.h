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
	tail->next = (sn*)malloc(sizeof(sn));
	p = tail->next;
	p->pre = tail;
	tail = p;
	p->next = NULL;
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


//4个食物开局结为基础食物
fd* fd1 = (fd*)malloc(sizeof(fd));
fd* fd2 = (fd*)malloc(sizeof(fd));
fd* fd3 = (fd*)malloc(sizeof(fd));
fd* fd4 = (fd*)malloc(sizeof(fd));



int speed = 150;//sleep time(ms)
int score = 0;//分数
int choose = 0;//界面选择用
char c[3];

int go_position = 's';//初始前进方向

//蛇头4个方向及蛇身图片
IMAGE headw, heada, heads, headd, snake, map, stop, menu0, menude;
//4种食物
IMAGE food0, food1, food2, food3;
//剧情
IMAGE story0, story1, story2, story3, story4, story5, story6, story7;
IMAGE storyend0, storyend1, storyend2, storyend3, scores, menu1;

