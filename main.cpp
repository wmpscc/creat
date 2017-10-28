#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           ͼ�����ϵͳ\n\n			1���г���ǰ���\n			2��ɾ��һ����\n			3������һ����\n			4��ȡ��һ����\n			5������\n			6���鿴�˵�\n			7������\n\n");
	printf("*****************************************************************\n\n\n");
}

typedef struct book{
	char bookName[20];	
	char authorName[20];
	int pageNumber;
	float price;
	char kind[10];
	
	struct book *next;
}Book;

book * readDataByTxt()	//�������� 
{
	char allChar[100];
	char bookName[20];
	char authorName[20];
	float price;
	int pageNumber;
	char kind[10];
	Book *head = NULL, *prev = NULL, *bookp = NULL;
	FILE *fp;
	
	int temp = 0, i, flag;
	if((fp = fopen("C:\\Users\\wmpscc\\Desktop\\����\\data.txt","r")) == NULL)
	{
		printf("********************�ӱ����ĵ���������ʧ��********************\n");
		
	}
	else
	{
		do
		{
			fscanf(fp,"%s%s%s%f%d",bookName,authorName,kind,&price,&pageNumber);
			bookp = (Book *)malloc(sizeof(Book));
			if(prev != NULL)
			{
				prev->next = bookp;
			}
			if(head == NULL)
			{
				head = bookp;
			}
			
			//��ֵ 
			strcpy(bookp->bookName,bookName);
			strcpy(bookp->authorName,authorName);
			strcpy(bookp->kind,kind);
			bookp->price = price;
			bookp->pageNumber = pageNumber;
			bookp->next = NULL;
			
			prev = bookp;
			
			
		}while(fgetc(fp)!=EOF);
		printf("********************�ѳɹ��ӱ����ĵ���������********************\n");
	}
	

	fclose(fp);
	return head;
}

void showlist(Book *book)
{
	do
	{
		printf("%-10s\t%-10s\t%-10s\t%-5.1f\t%-5d\n",book->bookName,book->authorName,book->kind,book->price,book->pageNumber); 
	}while(book = book->next);
}

Book *delByName(Book *head)
{
	Book *prev = NULL, *return0 = NULL;
	char name[20];
	printf("����Ҫɾ��������:");
	scanf("%s",name);
	return0 = head;
	do
	{
		for(strcmp(head->bookName,name)==0)
		{
			if(prev == NULL)
			{
				head = head->next;
				return0 = head;
				break;
			}
			else
			{
				prev->next = head->next;
				break;
			}
		}
		
	}while(head = head->next);
}



int main()
{
	int i = 1;
	Book * head;
	showTitle();
	head = readDataByTxt();
	printf("����Ҫִ�е�����:");
	while(scanf("%d",&i)!=EOF)
	{
	switch(i)
	{
		case 1:
			showlist(head);
			printf("\n����Ҫִ�е�����:");
			break;
		case 2:
			delByName();
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
			
		default :printf("error!");
	}
}
	return 0;
}
