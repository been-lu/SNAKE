#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>

//ʵ��Ϊ800*600������20����Ϊһ��λ
#define MAP_WIDTH 40
#define MAP_LENGTH 30

//�ߵĽṹ�壨˫������
typedef struct snake
{
	int position_x;
	int position_y;
	struct snake* pre;
	struct snake* next;
}sn;

sn* head;//��ͷ
sn* tail;//��β
sn* p = NULL;//���ڱ���

//����ڵ�
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

//ɾ��β�ڵ�
void dele()
{
	p = (tail->pre);
	free(tail);
	tail = p;
	tail->next = NULL;
	p = NULL;
}

//ʳ��ṹ��
typedef struct
{
	int position_x;
	int position_y;
	//ʳ������ 0Ϊ�����ͣ�1Ϊ���ף�2Ϊ���ݣ�3Ϊ��Ч��
	int type;
}fd;

//�����ṹ��
typedef struct list
{
	char name[20];
	int score;
}lt;

//�ƶ����(���ѷ���)
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}


//4��ʳ�￪�ֽ�Ϊ����ʳ��
fd* fd1 = (fd*)malloc(sizeof(fd));
fd* fd2 = (fd*)malloc(sizeof(fd));
fd* fd3 = (fd*)malloc(sizeof(fd));
fd* fd4 = (fd*)malloc(sizeof(fd));


int speed = 150;//sleep time(ms)
int score = 0;//����
int choose = 0;//����ѡ����

int go_position = 's';//��ʼǰ������

//��ͷ4����������ͼƬ
IMAGE headw, heada, heads, headd, snake, map, stop, menu0;
//4��ʳ��
IMAGE food0, food1, food2, food3;

