#pragma warning(disable:4996)
#include "stdio.h"    
#include "string.h"     
#include "stdlib.h"   
#include <windows.h> 

typedef struct student
{
	long int num;
	char name[10];
	char sex[5];
	long int phone;
	char address[100];
};

struct student list[999];

int count = 0;//计数器
int choice_2;

void Welcome();
void ShowMenu();
void Insert();
void Find();
void Delete();
void Update();
void Readingfile();
void Choice();
void Quit();


int main()
{
	int choice;
	Welcome();
	ShowMenu();
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
			Choice();
			if (choice_2 == 1)
				Readingfile();
			else
				Insert();
				ShowMenu();
				scanf("%d", &choice);
			continue;
		case 2:
			Find();
			ShowMenu();
			scanf("%d", &choice);
			continue;
		case 3:
			Delete();
			ShowMenu();
			scanf("%d", &choice);
			continue;
		case 4:
			Update();
			ShowMenu();
			scanf("%d", &choice);
			continue;
		default:
			Quit();
			break;
		}
	} while (choice != 0);
}



//欢迎界面
void Welcome() {
	printf("正在进入学生通讯录管理系统............\n");
	printf("\n");
	Sleep(4000);
	printf("\n抱歉，进入失败！\n");
	printf("\nC:\\学生通讯录.exe (进程 13944)已退出，代码为 0。要在调试停止时自动关闭控制台，请启用“工具”->“选项”->“调试”->“调试停止时自动关闭控制台”。按任意键关闭此窗口. . .\n");
	printf("\n");
	printf("\n");
	Sleep(1000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录管理系统	       **\n");
	printf("*************************************************\n");
	Sleep(1000);
}


//菜单界面
void ShowMenu() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在加载菜单.........\n");
	Sleep(2000);
	printf("*************************************************\n");
	printf("**	        	 菜单		       **\n");
	printf("*************************************************\n");
	printf("\n当前系统中共有%d名学生\n", count);
	printf("\n1: 信息录入\n2：信息查询\n3：删除成员\n4：信息更新\n0: 退出系统\n");
	printf("请选择要进行的操作：");
}


//模式选择
void Choice()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在进入学生通讯录录入系统.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录录入系统	       **\n");
	printf("*************************************************\n");
	printf("\n1 文件读取\t2 手动输入\n请选择数据读取模式：");
	scanf("%d", &choice_2);
}



//读取文件
void Readingfile()
{
	printf("请输入需要读取文件的路径：\t");
	char path[99];
	scanf("%s", &path);
	FILE* fp;
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %ld %ld %s", &list[count].name, &list[count].sex, &list[count].num, &list[count].phone, &list[count].address);
		count++;
	}
}




//手动输入数据
void Insert() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("请输入学生的\n姓名：");
	scanf("%s", &list[count].name);

	printf("请输入学生的\n性别(男/女)：");
	char InputSex[5];
	char Man[5] = "男";
	char Woman[7] = "女";
	scanf("%s", &InputSex);

	if (strcmp(InputSex, Man) == 0 || strcmp(InputSex, Woman) == 0)
	{
		strcpy(list[count].sex, InputSex);
	}

	else
	{
		printf("输入的性别格式错误!\n");
		exit(0);
	}

	printf("请输入学生的\n学号：");
	scanf("%ld", &list[count].num);

	printf("请输入学生的\n电话：");
	scanf("%ld", &list[count].phone);

	printf("请输入学生的\n住址：");
	scanf("%s", &list[count].address);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("提示：   信息录入成功!");
	count++;
}


//查询
void Find()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在进入学生通讯录查询系统.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录查询系统	       **\n");
	printf("*************************************************\n");
	char FindName[10] = { 0 };
	printf("请输入需要查询的学生的姓名:\n");
	scanf("%s", &FindName);

	for (int i = 0; i <= count; i++)
	{
		if (strcmp(FindName, list[i].name) == 0)
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("该学生的信息如下：\n");
			printf("姓名：%s\n", list[i].name);
			printf("性别：%s\n", list[i].sex);
			printf("学号：%ld\n", list[i].num);
			printf("电话：%ld\n", list[i].phone);
			printf("家庭住址：%s\n", list[i].address);
		}
		else if (strcmp(FindName, list[i].name) == 0)
		{
			printf("提示：     没有找到该学生!\n");
		}
		
	}
}



//删除
void Delete() 
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在进入学生通讯录删除系统.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录删除系统	       **\n");
	printf("*************************************************\n");
	char DeleteName[10] = { 0 };
	printf("请输入需要删除的学生的姓名：\n");
	scanf("%s", &DeleteName);

	for (int i = 0; i < count; i++)
	{
		if (strcmp(DeleteName, list[i].name) == 0)
		{
			list[i] = list[i + 1];
			printf("\n");
			printf("\n");
			printf("\n");

			printf("提示：     信息删除成功！\n");
			count--;
		}
		else
		{
			printf("\n");
			printf("\n");
			printf("\n");

			printf("提示：    没有找到该学生！\n");
		}
	}
}



//更新
void Update() 
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n正在进入学生通讯录更新系统.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     欢迎进入学生通讯录更新系统	       **\n");
	printf("*************************************************\n");
	char UpdateName[10] = { 0 };
	int choice = 0;
	printf("请输入需要更新信息的学生的姓名：\n");
	scanf("%s", &UpdateName);

	for (int i = 0; i < count; i++)
	{
		if (strcmp(UpdateName, list[i].name) == 0)
		{
			do
			{
				printf("请输入需要更改的项目：\n");
				printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1:
					printf("请输入新学号：");
					long int newnum;
					scanf("%ld", &newnum);
					list[i].num = newnum;

					printf("请输入需要更改的项目：\n");
					printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
					scanf("%d", &choice);

					continue;
				case 2:
					printf("请输入新性别：");
					char newsex[5];
					scanf("%s", &newsex);
					strcpy(list[i].sex, newsex);

					printf("请输入需要更改的项目：\n");
					printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
					scanf("%d", &choice);

					continue;
				case 3:
					printf("请输入新电话：");
					long int newphone;
					scanf("%ld", &newphone);
					list[i].phone = newphone;

					printf("请输入需要更改的项目：\n");
					printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
					scanf("%d", &choice);

					continue;
				case 4:
					printf("请输入新住址：");
					char newaddress[100];
					scanf("%s", &newaddress);
					strcpy(list[i].address, newaddress);

					printf("请输入需要更改的项目：\n");
					printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
					scanf("%d", &choice);

					continue;
				default:
					printf("请输入正确的选项！\n");
					printf("请输入需要更改的项目：\n");
					printf("1 学号\t2 性别\t3 电话\t4 家庭住址\t0 返回菜单\n");
					scanf("%d", &choice);

					continue;
				}
			} while (choice != 0);
		}
		else
		{
			printf("\n");
			printf("\n");
			printf("\n");

			printf("提示：    没有找到该学生！\n");
		}
	}
}



//退出系统
void Quit()
{
	printf("\n正在退出.........\n");
	Sleep(3000);
	printf("提示：    退出成功！");
}
