#include"my.h"

//��ʼ����������
void start();
void restart();
//ѡ��˵�
void menu();
void menud();
void setst();
void setdegree();
//ʳ������
void createfood(fd* food);
//��ͼ
void drawfood();
void drawwall();
void drawsnake();
void draw();
//��ͣ
void pause();
void keyboard();
void gameover();
void run();
void exit();
int check();

void setdegree();
//Ӧ���и�����
void storytell();
void endtell();
//���а��д
void writelist();
void readlist();
//��Ϸ�׶�
void st();
//���ȱ���
void save();
void load();

int main()
{
	//��ʼ��Ϸ
	start();

	closegraph();

	return 0;
}

//��ʼ
void start()
{
	//��ͼ�󲢶�ȡͼƬ
	{
		initgraph(800, 600);

		loadimage(&headw, _T("PNG"), MAKEINTRESOURCE(_headw), 20, 20);
		loadimage(&heada, _T("PNG"), MAKEINTRESOURCE(_heada), 20, 20);
		loadimage(&heads, _T("PNG"), MAKEINTRESOURCE(_heads), 20, 20);
		loadimage(&headd, _T("PNG"), MAKEINTRESOURCE(_headd), 20, 20);
		loadimage(&snake, _T("PNG"), MAKEINTRESOURCE(_snake), 20, 20);
		loadimage(&food0, _T("PNG"), MAKEINTRESOURCE(_food0), 20, 20);
		loadimage(&food1, _T("PNG"), MAKEINTRESOURCE(_food1), 20, 20);
		loadimage(&food2, _T("PNG"), MAKEINTRESOURCE(_food2), 20, 20);
		loadimage(&food3, _T("PNG"), MAKEINTRESOURCE(_food3), 20, 20);
		loadimage(&map, _T("PNG"), MAKEINTRESOURCE(_map), 800, 600);
		loadimage(&stop, _T("PNG"), MAKEINTRESOURCE(_stop), 800, 600);
		loadimage(&menu0, _T("PNG"), MAKEINTRESOURCE(_menu0), 800, 600);
		loadimage(&menude, _T("PNG"), MAKEINTRESOURCE(_menud), 800, 600);
		loadimage(&story00, _T("PNG"), MAKEINTRESOURCE(_story00), 800, 600);
		loadimage(&story01, _T("PNG"), MAKEINTRESOURCE(_story01), 800, 600);
		loadimage(&story1, _T("PNG"), MAKEINTRESOURCE(_story1), 800, 600);
		loadimage(&story2, _T("PNG"), MAKEINTRESOURCE(_story2), 800, 600);
		loadimage(&story3, _T("PNG"), MAKEINTRESOURCE(_story3), 800, 600);
		loadimage(&story4, _T("PNG"), MAKEINTRESOURCE(_story4), 800, 600);
		loadimage(&help0, _T("PNG"), MAKEINTRESOURCE(_help0), 800, 600);
		loadimage(&help1, _T("PNG"), MAKEINTRESOURCE(_help1), 800, 600);
		loadimage(&list, _T("PNG"), MAKEINTRESOURCE(_list), 400, 300);
		loadimage(&stage1, _T("PNG"), MAKEINTRESOURCE(_stage1), 800, 600);
		loadimage(&stage2, _T("PNG"), MAKEINTRESOURCE(_stage2), 800, 600);
		loadimage(&stage3, _T("PNG"), MAKEINTRESOURCE(_stage3), 800, 600);
		loadimage(&stage4, _T("PNG"), MAKEINTRESOURCE(_stage4), 800, 600);
		loadimage(&end1, _T("PNG"), MAKEINTRESOURCE(_end1), 800, 600);
		loadimage(&end2, _T("PNG"), MAKEINTRESOURCE(_end2), 800, 600);
		loadimage(&end3, _T("PNG"), MAKEINTRESOURCE(_end3), 800, 600);
		loadimage(&end41, _T("PNG"), MAKEINTRESOURCE(_end41), 800, 600);
		loadimage(&end42, _T("PNG"), MAKEINTRESOURCE(_end42), 800, 600);
		loadimage(&end5, _T("PNG"), MAKEINTRESOURCE(_end5), 800, 600);
		loadimage(&end61, _T("PNG"), MAKEINTRESOURCE(_end61), 800, 600);
		loadimage(&end62, _T("PNG"), MAKEINTRESOURCE(_end62), 800, 600);
		loadimage(&wall, _T("PNG"), MAKEINTRESOURCE(_wall), 20, 20);
		loadimage(&done, _T("PNG"), MAKEINTRESOURCE(_done), 80, 60);
		loadimage(&death, _T("PNG"), MAKEINTRESOURCE(_gameover), 400, 300);
		loadimage(&degree, _T("PNG"), MAKEINTRESOURCE(_degree), 800, 600);
		loadimage(&setstage, _T("PNG"), MAKEINTRESOURCE(_setstg), 800, 600);
	}

	//�����߳�ʼ��
	{
		head = (sn*)malloc(sizeof(sn));
		head->pre = NULL;
		head->position_x = 7;
		head->position_y = 7;

		head->next = (sn*)malloc(sizeof(sn));
		p = head->next;
		p->position_x = 7;
		p->position_y = 6;
		p->pre = head;

		p->next = (sn*)malloc(sizeof(sn));
		tail = p->next;
		tail->position_x = 7;
		tail->position_y = 5;
		tail->pre = p;
		tail->next = NULL;
		p = NULL;
		//��ʼ����Ϊ3
		length = 3;
		over = 0;
	}

	//��������Ӽ�ʳ���ʼ��
	{
	srand((unsigned)time(NULL));
	fd1->position_x = 11; 
	fd1->position_y = 13; 
	fd1->type = 0; 
	fd1->times = -1;

	fd2->position_x = 4; 
	fd2->position_y = 17; 
	fd2->type = 1;
	fd2->times = 10;

	fd3->position_x = 7;
	fd3->position_y = 7; 
	fd3->type = 0; 
	fd3->times = -1;

	fd4->position_x = 3;  
	fd4->position_y = 7; 
	fd4->type = 2; 
	fd3->times = -1;
	}

	//���뿪ʼͼƬ
	{
	loadimage(NULL, _T("PNG"), MAKEINTRESOURCE(_load0), 800, 600);
	Sleep(1700);
	loadimage(NULL, _T("PNG"), MAKEINTRESOURCE(_load1), 800, 600);
	Sleep(1700);
	loadimage(NULL, _T("PNG"), MAKEINTRESOURCE(_load2), 800, 600);
	Sleep(1700); 
	}
	
	//���뿪ʼ����
	menu();
}
//���¿�ʼ
void restart()
{
	score = 0;
	stage = 0;

	//��ʼ��
	{
		//�߹�λ
		head = (sn*)malloc(sizeof(sn));
		head->pre = NULL;
		head->position_x = 7;
		head->position_y = 7;
		head->next = (sn*)malloc(sizeof(sn));
		p = head->next;
		p->position_x = 7;
		p->position_y = 6;
		p->pre = head;
		p->next = (sn*)malloc(sizeof(sn));
		tail = p->next;
		tail->position_x = 7;
		tail->position_y = 5;
		tail->pre = p;
		tail->next = NULL;
		p = NULL;
		length = 3;
		over = 0;
		go_position = 's';
		//ʳ���λ
		fd1->position_x = 11;
		fd1->position_y = 13; 
		fd1->type = 0;
		fd1->times = -1;

		fd2->position_x = 4; 
		fd2->position_y = 17; 
		fd2->type = 1; 
		fd2->times = 10;

		fd3->position_x = 7;  
		fd3->position_y = 7;  
		fd3->type = 0; 
		fd3->times = -1;

		fd4->position_x = 3;
		fd4->position_y = 7;
		fd4->type = 2;
		fd4->times = -1;
	}

	//������
	draw();
	run();

}

//ѡ��˵�
void menu()
{
	putimage(0, 0, &menu0);
	while(1)
	{
		if (_kbhit())
		{
			choose = _getch();
			if (choose != 49 && choose != 50 && choose != 51 && choose != 52)
				continue;
			else
				break;
		}
	}
	Sleep(100);
	cleardevice();
	switch (choose)
	{
	case 49:setdegree(); setst(); storytell();
		draw(); run();  break;
	case 50:readlist(); break;
	case 51:load(); break;
	case 52:exit(); break;
	}		
}
void menud()
{
	putimage(0, 0, &menude);
	while (1)
	{
		if (_kbhit())
		{
			choose = _getch();
			if (choose != 49 && choose != 50 && choose != 51 && choose!=52)
				continue;
			else
				break;
		}
	}
	cleardevice();
	switch (choose)
	{
	case 49:setdegree(); setst(); restart(); break;
	case 50:readlist(); break;
	case 51:load(); break;
	case 52:exit(); break;
	}
}
void setdegree()
{
	cleardevice();
	int key;
	putimage(0, 0, &degree);
	for (;;)
	{
		if (_kbhit)
		{
			key = _getch();
			if (key == 49 || key == 50)
				break;
			else
				continue;
		}
	}
	switch (key)
	{
	case 49:speed = 150; perhaps = 8; hard = 0; break;
	case 50:speed = 100; perhaps = 7; hard = 1; break;
	}
	putimage(360, 270, &done);
	Sleep(500);
}
void setst()
{
	cleardevice();
	int key;
	putimage(0, 0, &setstage);
	for (;;)
	{
		if (_kbhit)
		{
			key = _getch();
			if (key == 49 || key == 50 || key == 51)
				break;
			else
				continue;
		}
	}
	switch (key)
	{
	case 49:stage = 0; break;
	case 50:stage = 1; break;
	case 51:stage = 2; break;
	}
	putimage(360, 270, &done);
	Sleep(500);
}
//����ʳ��
void createfood(fd*food)
{
	food->position_x = rand() % (MAP_WIDTH -1);
	food->position_y = rand() % (MAP_LENGTH -1);
	food->type = rand() % (perhaps);
	if (food->type >= 4)
		food->type = 0;

	if (food->type == 1)
		food->flash = 0;
	else
		food->flash = -1;

	if (food->type == 1)
		food->times = 10;
	else
		food->times = -1;
	//���ʳ��᲻�ᱻ������ס
	if (food->position_x <= 3 && food->position_y == 0)
	{
		createfood(food);return;
	}

	//���ʳ���ڲ���������
	int flag = 0;
	p = head;
	while (p && flag==0)
	{
		if (food->position_x == p->position_x && food->position_y == p->position_y)
		{
			flag = 1;
		}
		p = p->next;
	}
	p = NULL;
	if (flag == 1)
	{
		createfood(food); return;
	}
	//�᲻����ǽ
	{
	if (stage >= 1)
	{
		for (int i = 5; i <= 25; i++)
			if (food->position_x == 15 && food->position_y == (i))
			{
				createfood(food); return;
			}
		for (int i = 5; i <= 25; i++)
			if (food->position_y == 25 && food->position_x == (i))
			{
				createfood(food); return;
			}
	}
	if (stage >= 2)
	{
		for (int i = 0; i < 5; i++)
			if (food->position_x == (20 + a[i]) && food->position_y == (5 + b[i]))
			{
				createfood(food); return;
			}
		for (int i = 0; i < 5; i++)
			if (food->position_x == (20 + a[i]) && food->position_y == (15 + b[i]))
			{
				createfood(food); return;
			}
		for (int i = 0; i < 5; i++)
			if (food->position_x == (20 + a[i]) && food->position_y == (25 + b[i]))
			{
				createfood(food); return;
			}

	}
	}
	//���ʳ��᲻���غ�
	//�Ͳ������
	//����Ҫ���ģ�С�����¼����ǻᷢ����
	{
		if (food == fd1)
			if (food->position_x == fd2->position_x && food->position_y == fd2->position_y)
				createfood(food);
		if (food == fd1)
			if (food->position_x == fd3->position_x && food->position_y == fd3->position_y)
				createfood(food);
		if (food == fd1)
			if (food->position_x == fd4->position_x && food->position_y == fd4->position_y)
				createfood(food);
		if (food == fd2)
			if (food->position_x == fd1->position_x && food->position_y == fd1->position_y)
				createfood(food);
		if (food == fd2)
			if (food->position_x == fd3->position_x && food->position_y == fd3->position_y)
				createfood(food);
		if (food == fd2)
			if (food->position_x == fd4->position_x && food->position_y == fd4->position_y)
				createfood(food);
		if (food == fd3)
			if (food->position_x == fd1->position_x && food->position_y == fd1->position_y)
				createfood(food);
		if (food == fd3)
			if (food->position_x == fd2->position_x && food->position_y == fd2->position_y)
				createfood(food);
		if (food == fd3)
			if (food->position_x == fd4->position_x && food->position_y == fd4->position_y)
				createfood(food);
		if (food == fd4)
			if (food->position_x == fd1->position_x && food->position_y == fd1->position_y)
				createfood(food);
		if (food == fd4)
			if (food->position_x == fd2->position_x && food->position_y == fd2->position_y)
				createfood(food);
		if (food == fd4)
			if (food->position_x == fd3->position_x && food->position_y == fd3->position_y)
				createfood(food);
	}
}

//��ͼ
void drawfood() 
{
	if (stage == 0)
	switch (fd1->type)
	{
	case 0:putimage((fd1->position_x * 20), (fd1->position_y) * 20, &food0); break;
	case 1:
		if (fd1->flash == 0)
		{
			putimage((fd1->position_x * 20), (fd1->position_y) * 20, &food1); fd1->flash = 1; fd1->times--;
			if (fd1->times == 0)
				createfood(fd1);
		}
		else
			fd1->flash = 0;
		break;
	case 2:putimage((fd1->position_x * 20), (fd1->position_y) * 20, &food2); break;
	case 3:putimage((fd1->position_x * 20), (fd1->position_y) * 20, &food3); break;
	}

	if (stage <= 1)
	switch (fd2->type)
	{
	case 0:putimage((fd2->position_x * 20), (fd2->position_y) * 20, &food0); break;
	case 1:
		if (fd2->flash == 0)
		{
			putimage((fd2->position_x * 20), (fd2->position_y) * 20, &food1); fd2->flash = 1; fd2->times--;
			if (fd2->times == 0)createfood(fd2);
		}
		else
			fd2->flash = 0;
		break;
	case 2:putimage((fd2->position_x * 20), (fd2->position_y) * 20, &food2); break;
	case 3:putimage((fd2->position_x * 20), (fd2->position_y) * 20, &food3); break;
	}

	if (stage <= 2)
	switch (fd3->type)
	{
	case 0:putimage((fd3->position_x * 20), (fd3->position_y) * 20, &food0); break;
	case 1:
		if (fd3->flash == 0)
		{
			putimage((fd3->position_x * 20), (fd3->position_y) * 20, &food1); fd3->flash = 1; fd3->times--;
			if (fd3->times == 0)createfood(fd3);
		}
		else
			fd3->flash = 0;
		break;
	case 2:putimage((fd3->position_x * 20), (fd3->position_y) * 20, &food2); break;
	case 3:putimage((fd3->position_x * 20), (fd3->position_y) * 20, &food3); break;
	}
	
	switch (fd4->type)
	{
	case 0:putimage((fd4->position_x * 20), (fd4->position_y) * 20, &food0); break;
	case 1:
		if (fd4->flash == 0)
		{
			putimage((fd4->position_x * 20), (fd4->position_y) * 20, &food1); fd4->flash = 1; fd4->times--;
			if (fd4->times == 0)createfood(fd4);
		}
		else
			fd4->flash = 0;
		break;
	case 2:putimage((fd4->position_x * 20), (fd4->position_y) * 20, &food2); break;
	case 3:putimage((fd4->position_x * 20), (fd4->position_y) * 20, &food3); break;
	}
}
void drawsnake()
{
	//���ݷ�����ͷ����Ȼ����������
	switch (go_position)
	{
	case'W':case 'w':putimage((head->position_x) * 20, (head->position_y) * 20, &headw); break;
	case'A':case 'a':putimage((head->position_x) * 20, (head->position_y) * 20, &heada); break;
	case'S':case 's':putimage((head->position_x) * 20, (head->position_y) * 20, &heads); break;
	case'D':case 'd':putimage((head->position_x) * 20, (head->position_y) * 20, &headd); break;
	}
	//������
	for(p = head->next;p!=NULL;p = p->next)
	{
		putimage((p->position_x) * 20, (p->position_y) * 20, &snake);
	}
	//putimage((tail->position_x) * 20, (tail->position_y) * 20, &snake);
	//putimage((tail->pre->position_x) * 20, (tail->pre->position_y) * 20, &snake);
}
void drawwall() //û��ǽʹ�����Լ����ģ�
{
	if (stage >= 1)
	{
		for (int i = 5; i <= 25; i++)
			putimage(300, i * 20, &wall);
		for (int i = 5; i <= 25; i++)
			putimage(500, i * 20, &wall);
	}
	if (stage >= 2)
	{
		for (int i = 0; i < 5; i++)
			putimage((20 + a[i]) * 20, (5 + b[i]) * 20, &wall);
		for (int i = 0; i < 5; i++)
			putimage((20 + a[i]) * 20, (15 + b[i]) * 20, &wall);
		for (int i = 0; i < 5; i++)
			putimage((20 + a[i]) * 20, (25 + b[i]) * 20, &wall);
	}
}
void draw()
{
	cleardevice();
	putimage(0, 0, &map);
	drawfood();
	drawsnake();
	drawwall();
	
	//���ϽǴ�ӡ����
	outtextxy(0, 0,"Score:");
	c[2] = score % 10 + 48;
	c[1] = (score / 10) % 10 + 48;
	c[0] = (score / 100) % 10 + 48;
	outtextxy(50, 0, c);
}

//��ͣ
void pause()
{
	putimage(0, 0, &stop);
	int key;
	for (;;)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 's'|| key == 'S')
			{
				save();
			}
			if (key == 'p'|| key == 'P')
				break;
		}
	}
}

//�����ͷ�Ӵ���ʲô
int check()
{
	//1��������0������
	int flag = 1;
	//�Ե�ʳ�� ��������ʳ��
	if(stage == 0)
	if (head->position_x == fd1->position_x && head->position_y == fd1->position_y)
	{
		switch (fd1->type)
		{
		case 0:join(); 
			if (hard == 0)score = score + 4;
			else score = score + 5;
			createfood(fd1); break;//������
		case 1:dele();
			if (hard == 0)score = score + 2;
			else score = score + 3;
			speed = speed - 5;
			if (speed == 0)
			{
				speed = 10; score = score - 10;
			}
			createfood(fd1); break;//����
		case 2:dele(); score = score - 5;
			 createfood(fd1); break;//����
		case 3:score = score + 2; 
			createfood(fd1); break;//����ˢ��ʳ��
		}
	}

	if(stage <= 1)
	if (head->position_x == fd2->position_x && head->position_y == fd2->position_y)
	{
		switch (fd2->type)
		{
		case 0:join(); 
			if (hard == 0)score = score + 4;
			else score = score + 5;
			createfood(fd2); break;
		case 1:dele();
			if (hard == 0)score = score + 2;
			else score = score + 3;
			speed = speed - 5;
			if (speed == 0)
			{
				speed = 10; score = score - 10;
			}
			createfood(fd2); break;
		case 2:dele(); score = score - 5; 
			createfood(fd2); break;
		case 3:score = score + 2;
			createfood(fd2); break;//δ��
		}
	}

	if(stage <= 2)
	if (head->position_x == fd3->position_x && head->position_y == fd3->position_y)
	{
		switch (fd3->type)
		{
		case 0:join(); 
			if (hard == 0)	score = score + 4;
			else score = score + 5;
			createfood(fd3); break;
		case 1: dele();
			if (hard == 0)score = score + 2;
			else score = score + 3;
			speed = speed - 10;
			if (speed == 0)
			{
				speed = 10; score = score - 10;
			}
			createfood(fd3); break;
		case 2:dele(); score = score - 5; 
			createfood(fd3); break;
		case 3:score = score + 2; createfood(fd3); break;//δ��
		}
	}

	if (head->position_x == fd4->position_x && head->position_y == fd4->position_y)
	{
		switch (fd4->type)
		{
		case 0:join(); 
			if (hard == 0)score = score + 4;
			else score = score + 5;
			createfood(fd4); break;
		case 1:dele();
			if(hard==0)score = score + 2; 
			else score = score + 3; 
			speed = speed - 10;
			if (speed == 0)
			{
				speed = 10; score = score - 10;
			}
			createfood(fd4); break;
		case 2:dele(); score = score - 5; 
			createfood(fd4); break;
		case 3:score = score + 2; createfood(fd4); break;//δ��
		}
	}
	
	if (head == tail)
	{
		flag = 0;
		return flag;
	}
	//ײǽ
	if (head->position_x < 0 || head->position_x > 39 || head->position_y < 0 || head->position_y > 29)
	{
		flag = 0;
		return flag;
	}
	if (stage >= 1)
	{
		for (int i = 5; i <= 25; i++)
			if (head->position_x == 15 && head->position_y == i)
			{
				flag=0;
				return flag;
			}
		for (int i = 5; i <= 25; i++)
			if (head->position_x == 25 && head->position_y == i)
			{
				flag = 0;
				return flag;
			}
	}
	if (stage >= 2)
	{
		for (int i = 0; i < 5; i++)
			if(head->position_x == (20 + a[i]) && head->position_y == (5 + b[i]))
			{
				flag = 0;
				return flag;
			}
		for (int i = 0; i < 5; i++)
			if (head->position_x == (20 + a[i]) && head->position_y == (15 + b[i]))
			{
				flag = 0;
				return flag;
			}
		for (int i = 0; i < 5; i++)
			if (head->position_x == (20 + a[i]) && head->position_y == (25 + b[i]))
			{
				flag = 0;
				return flag;
			}

	}
	//�Ե��Լ�
	p = head->next;
	while (p)
	{
		if (head->position_x == p->position_x && head->position_y == p->position_y)
		{
			flag = 0;
			break;
			p = NULL;
		}
		p = p->next;
	}

	return flag;
}

//����������
void run()
{
	keyboard();
	if (check() == 0)
	{
		putimage(200, 150, &death);
		Sleep(500);
		gameover();
		return;
	}
	st();
	for(p=tail;p!=head;p=p->pre)
	{
		p->position_x = p->pre->position_x;
		p->position_y = p->pre->position_y;
	}
	switch (go_position)
	{
	case'w':case'W':head->position_y--; break;
	case'a':case'A':head->position_x--; break;
	case's':case'S':head->position_y++; break;
	case'd':case'D':head->position_x++; break;
	}
	p = NULL;
	draw();

	Sleep(speed);
	run();
}

//��Ϸ����
void gameover()
{
	//�ռ��ͷ�
	{
	p = head->next;
	while (p)
	{
		free(p->pre);
		p = p->next;
	}
	free(tail);
	}
	over = 1;
	//���
	endtell();

	//�������д�����а�
	writelist();
	Sleep(20);

	//��������ѡ��˵�
	menud();

}

//����
void keyboard()
{
	
	if (_kbhit()==1)
	{
		fflush(stdin);
		int key,death=0;
		key = _getch();
		if (key == 'p' || key == 'P')
			pause();
		else
		{
			//��Ҫ���߳��Լ�
			{
				if ((key == 'w' || key == 'W') && (go_position == 's' || go_position == 'S'))
				{
					go_position = 's';
					death = 1;
				}
				if ((key == 's' || key == 'S') && (go_position == 'w' || go_position == 'W'))
				{
					go_position = 'w';
					death = 1;
				}
				if ((key == 'a' || key == 'A') && (go_position == 'D' || go_position == 'd'))
				{
					go_position = 'd';
					death = 1;
				}
				if ((key == 'd' || key == 'D') && (go_position == 'a' || go_position == 'A'))
				{
					go_position = 'a';
					death = 1;
				}
				if (death == 0)
					go_position = key;
			}
		}
	}
}

//�˳���Ϸ
void exit()
{
	Sleep(10);
}

//����
void storytell()
{
	putimage(0, 0, &story00);
	Sleep(1000);
	putimage(0, 0, &story01);
	Sleep(2000);
	putimage(0, 0, &story1);
	Sleep(2000);
	putimage(0, 0, &story2);
	Sleep(6000);
	putimage(0, 0, &story3);
	Sleep(2000);
	putimage(0, 0, &story4);
	Sleep(2000);
	putimage(0, 0, &help0);
	Sleep(4000);
	putimage(0, 0, &help1);
	system("pause");
}
void endtell()
{
	putimage(0, 0, &story1);
	Sleep(1000);
	putimage(0, 0, &end1);
	Sleep(1000);
	putimage(0, 0, &end2);
	Sleep(1000);
	putimage(0, 0, &end3);
	Sleep(8000);
	if (score < 60)
	{
		putimage(0, 0, &end41);
		Sleep(2000);
		putimage(0, 0, &end5);
		Sleep(2000);
		putimage(0, 0, &end61);
		Sleep(6000);
	}
	else
	{
		putimage(0, 0, &end42);
		Sleep(2000);
		putimage(0, 0, &end5);
		Sleep(2000);
		putimage(0, 0, &end62);
		Sleep(6000);
	}
}

//���а�
void writelist()
{
	cleardevice();
	putimage(0, 0, &list);
	if (score >= 30)
	{
		FILE* list;
		errno_t n;
		n = fopen_s(&list, "E:\\SnakeImage\\list.txt", "a+");
		fprintf(list, "%d ", score);
		fclose(list);
	}
	system("pause");
}
void readlist()
{
	putimage(0, 0, &list);
	FILE* list;
	int a, i, j;
	int e[32] = { 0 };
	errno_t no;
	TCHAR s[4];
	no = fopen_s(&list, "E:\\SnakeImage\\list.txt", "a+");
	for (i = 0; i <= 30; i++)
	{
		fscanf_s(list, "%d", &e[i]);
	}

	for (j = 0; j <= 30; j++)
		for (i = 0; i <= 28; i++)
		{
			if (e[i] <= e[i + 1])
			{
				e[i] = e[i] ^ e[i + 1];
				e[i + 1] = e[i] ^ e[i + 1];
				e[i] = e[i] ^ e[i + 1];
			}
		}

	for (i = 0; i <= 9; i++)
	{
		a = e[i];
		_stprintf_s(s, _T("%d"), a);
		settextstyle(19, 0, _T("����"));
		outtextxy(450, 102 + 36 * i, s);
	}

	fclose(list);

	system("pause");
	menu();
}

//�׶�
void st()
{
	if (stage == 0 && score >= 20)
	{
		//free(fd1);
		perhaps--;
		putimage(0, 0, &stage1);
		stage = 1;
		system("pause");
		draw();
		Sleep(400);
		return;
	}

	if (stage == 1 && score >= 35)
	{
		//free(fd2);
		perhaps--;
		putimage(0, 0, &stage2);
		stage = 2;
		system("pause");
		draw();
		Sleep(400);
		return;
	}
	if (stage == 2 && score >= 50)
	{
		//free(fd3);
		perhaps--;
		putimage(0, 0, &stage3);
		stage = 3;
		system("pause");
		draw();
		Sleep(400);
		return;
	}
	if (stage == 3 && score >= 60)
	{
		perhaps--;
		putimage(0, 0, &stage4);
		stage = 4;
		system("pause");
		draw();
		Sleep(400);
		return;
	}
}

//���ȴ�ȡ
void save()
{
	FILE* save;
	errno_t n;
	n = fopen_s(&save, "E:\\SnakeImage\\save.txt", "w");
	
	//������ȥ��
	fprintf(save, "%d %d %d %d %d ", score, stage, speed, go_position, hard);
	fprintf(save, "%d %d %d %d %d ", fd1->position_x, fd1->position_y, fd1->type, fd1->flash, fd1->times);
	fprintf(save, "%d %d %d %d %d ", fd2->position_x, fd2->position_y, fd2->type, fd2->flash, fd2->times);
	fprintf(save, "%d %d %d %d %d ", fd3->position_x, fd3->position_y, fd3->type, fd3->flash, fd3->times);
	fprintf(save, "%d %d %d %d %d ", fd4->position_x, fd4->position_y, fd4->type, fd4->flash, fd4->times);

	p = head;
	fprintf(save, "%d ", length);
	for (int i = 1; i <= length; i++)
	{
		fprintf(save, "%d %d ", p->position_x, p->position_y);
		p = p->next;
	}

	fclose(save);

	putimage(360, 270, &done);
	Sleep(500);
	putimage(0, 0, &stop);
}
void load()
{
	FILE* save;
	errno_t n;
	n = fopen_s(&save, "E:\\SnakeImage\\save.txt", "r");

	//����������, *���ų��켺
	if(over == 0)
	{
		p = head;
		while (p->next)
		{
			q = p->next;
			free(p);
			p = q;
		}
		free(tail);
	}

	fscanf_s(save, "%d %d %d %d %d", &score, &stage, &speed, &go_position, &hard);
	fscanf_s(save, "%d %d %d %d %d", &fd1->position_x, &fd1->position_y, &fd1->type, &fd1->flash, &fd1->times);
	fscanf_s(save, "%d %d %d %d %d", &fd2->position_x, &fd2->position_y, &fd2->type, &fd2->flash, &fd2->times);
	fscanf_s(save, "%d %d %d %d %d", &fd3->position_x, &fd3->position_y, &fd3->type, &fd3->flash, &fd3->times);
	fscanf_s(save, "%d %d %d %d %d", &fd4->position_x, &fd4->position_y, &fd4->type, &fd4->flash, &fd4->times);
	fscanf_s(save, "%d", &length);

	head = (sn*)malloc(sizeof(sn));
	p = head;
	q = NULL;
	for (int i = 1; i <= length; i++)
	{
		fscanf_s(save, "%d %d", &p->position_x, &p->position_y);
		p->next = (sn*)malloc(sizeof(sn));
		p->pre = q;
		q = p;
		p = p->next;
	}
	tail = q;
	tail->next = NULL;
	free(p);
	p = NULL; q = NULL;
	fclose(save);

	putimage(360, 270, &done);
	Sleep(700);
	draw();
	Sleep(500);
	run();
}