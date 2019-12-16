#include"my.h"

void start();
void menu();
void createfood(fd* food);
void drawfood();
void drawsnake();
void draw();
void keyboard();
void gameover();
void run();
void exit();
int check();
void restart();
void setdegree();
//应该有个故事
void storytell();
void endtell();
//排行榜读写
void writelist();
void readlist();
//游戏阶段
void st();
//进度保存
void save();
void load();

int main()
{
	//开始游戏
	start();

	closegraph();

	return 0;
}

//开始
void start()
{
	//开图象并读取图片
	{
		initgraph(800, 600);

		loadimage(&headw, _T("E://SnakeImage//headw.png"), 20, 20);
		loadimage(&heada, _T("E://SnakeImage//heada.png"), 20, 20);
		loadimage(&heads, _T("E://SnakeImage//heads.png"), 20, 20);
		loadimage(&headd, _T("E://SnakeImage//headd.png"), 20, 20);
		loadimage(&snake, _T("E://SnakeImage//snake.png"), 20, 20);
		loadimage(&food0, _T("E://SnakeImage//food0.png"), 20, 20);
		loadimage(&food1, _T("E://SnakeImage//food1.png"), 20, 20);
		loadimage(&food2, _T("E://SnakeImage//food2.png"), 20, 20);
		loadimage(&food3, _T("E://SnakeImage//food3.png"), 20, 20);
		loadimage(&map, _T("E://SnakeImage//map.png"), 800, 600);
		loadimage(&stop, _T("E://SnakeImage//stop.png"), 800, 600);
		loadimage(&menu0, _T("E://SnakeImage//menu0.png"), 800, 600);
		loadimage(&menude, _T("E://SnakeImage//menud.png"), 800, 600);
		loadimage(&story00, _T("E://SnakeImage//story00.png"), 800, 600);
		loadimage(&story01, _T("E://SnakeImage//story01.png"), 800, 600);
		loadimage(&story1, _T("E://SnakeImage//story1.png"), 800, 600);
		loadimage(&story2, _T("E://SnakeImage//story2.png"), 800, 600);
		loadimage(&story3, _T("E://SnakeImage//story3.png"), 800, 600);
		loadimage(&story4, _T("E://SnakeImage//story4.png"), 800, 600);
		loadimage(&help0, _T("E://SnakeImage//help0.png"), 800, 600);
		loadimage(&help1, _T("E://SnakeImage//help1.png"), 800, 600);
		loadimage(&list, _T("E://SnakeImage//list.jpg"));
		loadimage(&stage1, _T("E://SnakeImage//stage1.png"), 800, 600);
		loadimage(&stage2, _T("E://SnakeImage//stage2.png"), 800, 600);
		loadimage(&stage3, _T("E://SnakeImage//stage3.png"), 800, 600);
		loadimage(&stage4, _T("E://SnakeImage//stage4.png"), 800, 600);
		loadimage(&end1, _T("E://SnakeImage//end1.png"), 800, 600);
		loadimage(&end2, _T("E://SnakeImage//end2.png"), 800, 600);
		loadimage(&end3, _T("E://SnakeImage//end3.png"), 800, 600);
		loadimage(&end41, _T("E://SnakeImage//end41.png"));
		loadimage(&end42, _T("E://SnakeImage//end42.png"), 800, 600);
		loadimage(&end5, _T("E://SnakeImage//end5.png"), 800, 600);
		loadimage(&end61, _T("E://SnakeImage//end61.png"), 800, 600);
		loadimage(&end62, _T("E://SnakeImage//end62.png"), 800, 600);
		loadimage(&wall, _T("E://SnakeImage//wall.png"), 20, 20);
		loadimage(&done, _T("E://SnakeImage//done.png"), 80, 60);
		loadimage(&death, _T("E://SnakeImage//gameover.png"), 400, 300);
		loadimage(&degree, _T("E://SnakeImage//degree.png"), 800, 600);
	}

	//链表蛇初始化
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
		//初始长度为3
		length = 3;
	}

	//随机数种子及食物初始化
	{
	srand((unsigned)time(NULL));
	fd1->position_x = 11; fd1->position_y = 13; fd1->type = 0;
	fd2->position_x = 4; fd2->position_y = 17; fd2->type = 1;
	fd3->position_x = 7; fd3->position_y = 7; fd3->type = 0;
	fd4->position_x = 3; fd4->position_y = 7; fd4->type = 2;
	}

	//载入开始图片
	{
	loadimage(NULL, _T("E://SnakeImage//load0.jpg"), 800, 600);
	Sleep(1700);
	loadimage(NULL, _T("E://SnakeImage//load1.jpg"), 800, 600);
	Sleep(1700);
	loadimage(NULL, _T("E://SnakeImage//load2.png"), 800, 600);
	Sleep(1700); 
	}
	
	//进入开始界面
	menu();
}

//选择菜单
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
	case 49:setdegree(); storytell();
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
	case 49:setdegree(); restart(); break;
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

//生成食物
void createfood(fd*food)
{
	food->position_x = rand() % (MAP_WIDTH );
	food->position_y = rand() % (MAP_LENGTH );
	food->type = rand() % (perhaps);
	if (food->type >= 4)
		food->type = 0;

	if (food->type == 1)
		food->flash = 0;
	else
		food->flash = -1;
	//检查食物会不会被分数挡住
	if (food->position_x <= 3 && food->position_y == 0)
	{
		createfood(food);return;
	}

	//检查食物在不在蛇身上
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
	//会不会上墙
	{
	if (stage >= 1)
	{
		for (int i = 5; i <= 25; i++)
			if (food->position_x == 300 && food->position_y == (i * 20))
			{
				createfood(food); return;
			}
		for (int i = 5; i <= 25; i++)
			if (food->position_y == 500 && food->position_x == (i * 20))
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
	//检查食物会不会重合
	//就不检查了
	//还是要检查的，小概率事件还是会发生的
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

//画图
void drawfood() 
{
	if (stage == 0)
	switch (fd1->type)
	{
	case 0:putimage((fd1->position_x * 20), (fd1->position_y) * 20, &food0); break;
	case 1:
		if (fd1->flash == 0)
		{
			putimage((fd1->position_x * 20), (fd1->position_y) * 20, &food1); fd1->flash = 1;
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
			putimage((fd2->position_x * 20), (fd2->position_y) * 20, &food1); fd2->flash = 1;
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
			putimage((fd3->position_x * 20), (fd3->position_y) * 20, &food1); fd3->flash = 1;
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
			putimage((fd4->position_x * 20), (fd4->position_y) * 20, &food1); fd4->flash = 1;
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
	//根据方向画蛇头（虽然看不出来）
	switch (go_position)
	{
	case'W':case 'w':putimage((head->position_x) * 20, (head->position_y) * 20, &headw); break;
	case'A':case 'a':putimage((head->position_x) * 20, (head->position_y) * 20, &heada); break;
	case'S':case 's':putimage((head->position_x) * 20, (head->position_y) * 20, &heads); break;
	case'D':case 'd':putimage((head->position_x) * 20, (head->position_y) * 20, &headd); break;
	}
	//画蛇身
	for(p = head->next;p!=NULL;p = p->next)
	{
		putimage((p->position_x) * 20, (p->position_y) * 20, &snake);
	}
	//putimage((tail->position_x) * 20, (tail->position_y) * 20, &snake);
	//putimage((tail->pre->position_x) * 20, (tail->pre->position_y) * 20, &snake);
}
void drawwall() //没错，墙使是我自己画的，
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
	outtextxy(0, 0,"Score:");
	c[2] = score % 10 + 48;
	c[1] = (score / 10) % 10 + 48;
	c[0] = (score / 100) % 10 + 48;
	outtextxy(50, 0, c);
}

//暂停
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

//检查蛇头接触到什么
int check()
{
	//1是正常，0是死亡
	int flag = 1;
	//吃到食物 并重生成食物
	if(stage == 0)
	if (head->position_x == fd1->position_x && head->position_y == fd1->position_y)
	{
		switch (fd1->type)
		{
		case 0:join(); 
			if (hard == 0)score = score + 4;
			else score = score + 5;
			createfood(fd1); break;//基础型
		case 1:dele(); 
			if (hard == 0)score = score + 2;
			else score = score + 3;
			speed = speed - 5;
			if (speed == 0)
			{
				speed = 10; score = score - 10;
			}
			createfood(fd1); break;//地雷
		case 2:dele(); score = score - 5;
			 createfood(fd1); break;//毒草
		case 3:score = score + 2; 
			createfood(fd1); break;//用于刷新食物
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
			createfood(fd2); break;//未定
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
		case 1:dele(); 
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
		case 3:score = score + 2; createfood(fd3); break;//未定
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
		case 3:score = score + 2; createfood(fd4); break;//未定
		}
	}
	
	if (head == tail)
	{
		flag = 0;
		return flag;
	}
	//撞墙
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
	//吃到自己
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

//让蛇跑起来
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

//游戏结束
void gameover()
{
	//空间释放
	{
	p = head->next;
	while (p)
	{
		free(p->pre);
		p = p->next;
	}
	free(tail);
	}

	//结局
	endtell();

	//如果可以写入排行榜
	writelist();
	Sleep(20);

	//进入死亡选择菜单
	menud();

}

//键盘
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
			//还要防蛇吃自己
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

//退出游戏
void exit()
{
	Sleep(10);
}

//重新开始
void restart()
{
	score = 0;
	stage = 0;
	go_position = 's';
	//初始化
	{
		//蛇归位
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
		//食物归位
		fd1->position_x = 11; fd1->position_y = 13; fd1->type = 0;
		fd2->position_x = 4; fd2->position_y = 17; fd2->type = 1;
		fd3->position_x = 7; fd3->position_y = 7; fd3->type = 0;
		fd4->position_x = 3; fd4->position_y = 7; fd4->type = 2;
	}

	//跑起来
	draw();
	run();

}

//故事
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

//排行榜
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
	int b[32] = { 0 };
	errno_t no;
	TCHAR s[4];
	no = fopen_s(&list, "E:\\SnakeImage\\list.txt", "r");
	for (i = 0; i <= 30; i++)
	{
		fscanf_s(list, "%d", &b[i]);
	}
	for (j = 0; j <= 30; j++)
		for (i = 0; i <= 28; i++)
		{
			if (b[i] <= b[i + 1])
			{
				b[i] = b[i] ^ b[i + 1];
				b[i + 1] = b[i] ^ b[i + 1];
				b[i] = b[i] ^ b[i + 1];
			}
		}
	for (i = 0; i <= 9; i++)
	{
		a = b[i];
		_stprintf_s(s, _T("%d"), a);
		settextstyle(19, 0, _T("宋体"));
		outtextxy(450, 102 + 36 * i, s);
	}
	fclose(list);
	system("pause");
	menu();
}

//阶段
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

//进度存取
void save()
{
	FILE* save;
	errno_t n;
	n = fopen_s(&save, "E:\\SnakeImage\\save.txt", "w");
	
	//啊，进去啦
	fprintf(save, "%d %d %d %d ", score, stage, speed, go_position);
	fprintf(save, "%d %d %d %d ", fd1->position_x, fd1->position_y, fd1->type, fd1->flash);
	fprintf(save, "%d %d %d %d ", fd2->position_x, fd2->position_y, fd2->type, fd2->flash);
	fprintf(save, "%d %d %d %d ", fd3->position_x, fd3->position_y, fd3->type, fd3->flash);
	fprintf(save, "%d %d %d %d ", fd4->position_x, fd4->position_y, fd4->type, fd4->flash);

	p = head;
	fprintf(save, "%d ", length);
	for (int i = 1; i <= length; i++)
	{
		fprintf(save, "%d %d ", p->position_x, p->position_y);
		p = p->next;
	}

	fclose(save);

	putimage(360, 270, &done);
	Sleep(100);
}
void load()
{
	FILE* save;
	errno_t n;
	n = fopen_s(&save, "E:\\SnakeImage\\save.txt", "r");

	//啊，进来啦, *先排除异己
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
	fscanf_s(save, "%d %d %d %d", &score, &stage, &speed, &go_position);
	fscanf_s(save, "%d %d %d %d ", &fd1->position_x, &fd1->position_y, &fd1->type, &fd1->flash);
	fscanf_s(save, "%d %d %d %d ", &fd2->position_x, &fd2->position_y, &fd2->type, &fd2->flash);
	fscanf_s(save, "%d %d %d %d ", &fd3->position_x, &fd3->position_y, &fd3->type, &fd3->flash);
	fscanf_s(save, "%d %d %d %d ", &fd4->position_x, &fd4->position_y, &fd4->type, &fd4->flash);
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
	run();
}