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

int count = 0;//������
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



//��ӭ����
void Welcome() {
	printf("���ڽ���ѧ��ͨѶ¼����ϵͳ............\n");
	printf("\n");
	Sleep(4000);
	printf("\n��Ǹ������ʧ�ܣ�\n");
	printf("\nC:\\ѧ��ͨѶ¼.exe (���� 13944)���˳�������Ϊ 0��Ҫ�ڵ���ֹͣʱ�Զ��رտ���̨�������á����ߡ�->��ѡ�->�����ԡ�->������ֹͣʱ�Զ��رտ���̨������������رմ˴���. . .\n");
	printf("\n");
	printf("\n");
	Sleep(1000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼����ϵͳ	       **\n");
	printf("*************************************************\n");
	Sleep(1000);
}


//�˵�����
void ShowMenu() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڼ��ز˵�.........\n");
	Sleep(2000);
	printf("*************************************************\n");
	printf("**	        	 �˵�		       **\n");
	printf("*************************************************\n");
	printf("\n��ǰϵͳ�й���%d��ѧ��\n", count);
	printf("\n1: ��Ϣ¼��\n2����Ϣ��ѯ\n3��ɾ����Ա\n4����Ϣ����\n0: �˳�ϵͳ\n");
	printf("��ѡ��Ҫ���еĲ�����");
}


//ģʽѡ��
void Choice()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼¼��ϵͳ.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼¼��ϵͳ	       **\n");
	printf("*************************************************\n");
	printf("\n1 �ļ���ȡ\t2 �ֶ�����\n��ѡ�����ݶ�ȡģʽ��");
	scanf("%d", &choice_2);
}



//��ȡ�ļ�
void Readingfile()
{
	printf("��������Ҫ��ȡ�ļ���·����\t");
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




//�ֶ���������
void Insert() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("������ѧ����\n������");
	scanf("%s", &list[count].name);

	printf("������ѧ����\n�Ա�(��/Ů)��");
	char InputSex[5];
	char Man[5] = "��";
	char Woman[7] = "Ů";
	scanf("%s", &InputSex);

	if (strcmp(InputSex, Man) == 0 || strcmp(InputSex, Woman) == 0)
	{
		strcpy(list[count].sex, InputSex);
	}

	else
	{
		printf("������Ա��ʽ����!\n");
		exit(0);
	}

	printf("������ѧ����\nѧ�ţ�");
	scanf("%ld", &list[count].num);

	printf("������ѧ����\n�绰��");
	scanf("%ld", &list[count].phone);

	printf("������ѧ����\nסַ��");
	scanf("%s", &list[count].address);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("��ʾ��   ��Ϣ¼��ɹ�!");
	count++;
}


//��ѯ
void Find()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼��ѯϵͳ.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼��ѯϵͳ	       **\n");
	printf("*************************************************\n");
	char FindName[10] = { 0 };
	printf("��������Ҫ��ѯ��ѧ��������:\n");
	scanf("%s", &FindName);

	for (int i = 0; i <= count; i++)
	{
		if (strcmp(FindName, list[i].name) == 0)
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("��ѧ������Ϣ���£�\n");
			printf("������%s\n", list[i].name);
			printf("�Ա�%s\n", list[i].sex);
			printf("ѧ�ţ�%ld\n", list[i].num);
			printf("�绰��%ld\n", list[i].phone);
			printf("��ͥסַ��%s\n", list[i].address);
		}
		else if (strcmp(FindName, list[i].name) == 0)
		{
			printf("��ʾ��     û���ҵ���ѧ��!\n");
		}
		
	}
}



//ɾ��
void Delete() 
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼ɾ��ϵͳ.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼ɾ��ϵͳ	       **\n");
	printf("*************************************************\n");
	char DeleteName[10] = { 0 };
	printf("��������Ҫɾ����ѧ����������\n");
	scanf("%s", &DeleteName);

	for (int i = 0; i < count; i++)
	{
		if (strcmp(DeleteName, list[i].name) == 0)
		{
			list[i] = list[i + 1];
			printf("\n");
			printf("\n");
			printf("\n");

			printf("��ʾ��     ��Ϣɾ���ɹ���\n");
			count--;
		}
		else
		{
			printf("\n");
			printf("\n");
			printf("\n");

			printf("��ʾ��    û���ҵ���ѧ����\n");
		}
	}
}



//����
void Update() 
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n���ڽ���ѧ��ͨѶ¼����ϵͳ.........\n");
	Sleep(2000);
	printf("\n*************************************************\n");
	printf("**	     ��ӭ����ѧ��ͨѶ¼����ϵͳ	       **\n");
	printf("*************************************************\n");
	char UpdateName[10] = { 0 };
	int choice = 0;
	printf("��������Ҫ������Ϣ��ѧ����������\n");
	scanf("%s", &UpdateName);

	for (int i = 0; i < count; i++)
	{
		if (strcmp(UpdateName, list[i].name) == 0)
		{
			do
			{
				printf("��������Ҫ���ĵ���Ŀ��\n");
				printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1:
					printf("��������ѧ�ţ�");
					long int newnum;
					scanf("%ld", &newnum);
					list[i].num = newnum;

					printf("��������Ҫ���ĵ���Ŀ��\n");
					printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
					scanf("%d", &choice);

					continue;
				case 2:
					printf("���������Ա�");
					char newsex[5];
					scanf("%s", &newsex);
					strcpy(list[i].sex, newsex);

					printf("��������Ҫ���ĵ���Ŀ��\n");
					printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
					scanf("%d", &choice);

					continue;
				case 3:
					printf("�������µ绰��");
					long int newphone;
					scanf("%ld", &newphone);
					list[i].phone = newphone;

					printf("��������Ҫ���ĵ���Ŀ��\n");
					printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
					scanf("%d", &choice);

					continue;
				case 4:
					printf("��������סַ��");
					char newaddress[100];
					scanf("%s", &newaddress);
					strcpy(list[i].address, newaddress);

					printf("��������Ҫ���ĵ���Ŀ��\n");
					printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
					scanf("%d", &choice);

					continue;
				default:
					printf("��������ȷ��ѡ�\n");
					printf("��������Ҫ���ĵ���Ŀ��\n");
					printf("1 ѧ��\t2 �Ա�\t3 �绰\t4 ��ͥסַ\t0 ���ز˵�\n");
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

			printf("��ʾ��    û���ҵ���ѧ����\n");
		}
	}
}



//�˳�ϵͳ
void Quit()
{
	printf("\n�����˳�.........\n");
	Sleep(3000);
	printf("��ʾ��    �˳��ɹ���");
}
