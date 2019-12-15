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
int length;//蛇长

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
	length++;
}

//删除尾节点
void dele()
{
	p = (tail->pre);
	free(tail);
	tail = p;
	tail->next = NULL;
	p = NULL;
	length--;
}

//食物结构体
typedef struct
{
	int position_x;
	int position_y;
	//食物种类 0为基础型，1为毒草，2为地雷，3为特效草
	int type;
	int flash;//用于毒草闪烁
}fd;

//4个食物开局结为基础食物
fd* fd1 = (fd*)malloc(sizeof(fd));
fd* fd2 = (fd*)malloc(sizeof(fd));
fd* fd3 = (fd*)malloc(sizeof(fd));
fd* fd4 = (fd*)malloc(sizeof(fd));


int speed = 150;//sleep time(ms)
int score = 0;//分数
int choose = 0;//界面选择用
char c[3];//用于分数打印（用asci转换）
int stage = 0;//游戏阶段
int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
int perhaps = 8;//与食物生成概率有关
int go_position = 's';//初始前进方向
int a[5] = { 0,1,-1,0,0 };//用于地图画十字
int b[5] = { 0,0,0,1,-1 };


//蛇头4个方向及蛇身图片
IMAGE headw, heada, heads, headd, snake, map, stop, menu0, menude, wall, done;
//4种食物
IMAGE food0, food1, food2, food3;
//剧情
IMAGE story00, story01, story1, story2, story3, story4, story5, story6, story7;
IMAGE end1, end2, end3, end41, end42, end5 ,end61, end62, scores, menu1;
IMAGE help0, help1, list;
IMAGE stage1, stage2, stage3, stage4;
