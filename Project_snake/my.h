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
int length;//�߳�

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
	length++;
}

//ɾ��β�ڵ�
void dele()
{
	p = (tail->pre);
	free(tail);
	tail = p;
	tail->next = NULL;
	p = NULL;
	length--;
}

//ʳ��ṹ��
typedef struct
{
	int position_x;
	int position_y;
	//ʳ������ 0Ϊ�����ͣ�1Ϊ���ݣ�2Ϊ���ף�3Ϊ��Ч��
	int type;
	int flash;//���ڶ�����˸
}fd;

//4��ʳ�￪�ֽ�Ϊ����ʳ��
fd* fd1 = (fd*)malloc(sizeof(fd));
fd* fd2 = (fd*)malloc(sizeof(fd));
fd* fd3 = (fd*)malloc(sizeof(fd));
fd* fd4 = (fd*)malloc(sizeof(fd));


int speed = 150;//sleep time(ms)
int score = 0;//����
int choose = 0;//����ѡ����
char c[3];//���ڷ�����ӡ����asciת����
int stage = 0;//��Ϸ�׶�
int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
int perhaps = 8;//��ʳ�����ɸ����й�
int go_position = 's';//��ʼǰ������
int a[5] = { 0,1,-1,0,0 };//���ڵ�ͼ��ʮ��
int b[5] = { 0,0,0,1,-1 };


//��ͷ4����������ͼƬ
IMAGE headw, heada, heads, headd, snake, map, stop, menu0, menude, wall, done;
//4��ʳ��
IMAGE food0, food1, food2, food3;
//����
IMAGE story00, story01, story1, story2, story3, story4, story5, story6, story7;
IMAGE end1, end2, end3, end41, end42, end5 ,end61, end62, scores, menu1;
IMAGE help0, help1, list;
IMAGE stage1, stage2, stage3, stage4;
