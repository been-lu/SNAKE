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
	tail->next = (sn*)malloc(sizeof(sn));
	p = tail->next;
	p->pre = tail;
	tail = p;
	p->next = NULL;
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


//4��ʳ�￪�ֽ�Ϊ����ʳ��
fd* fd1 = (fd*)malloc(sizeof(fd));
fd* fd2 = (fd*)malloc(sizeof(fd));
fd* fd3 = (fd*)malloc(sizeof(fd));
fd* fd4 = (fd*)malloc(sizeof(fd));



int speed = 150;//sleep time(ms)
int score = 0;//����
int choose = 0;//����ѡ����
char c[3];

int go_position = 's';//��ʼǰ������

//��ͷ4����������ͼƬ
IMAGE headw, heada, heads, headd, snake, map, stop, menu0, menude;
//4��ʳ��
IMAGE food0, food1, food2, food3;
//����
IMAGE story0, story1, story2, story3, story4, story5, story6, story7;
IMAGE storyend0, storyend1, storyend2, storyend3, scores, menu1;

