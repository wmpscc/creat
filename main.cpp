#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           图书管理系统\n\n			1、列出当前库存\n			2、删除一本书\n			3、增添一本书\n			4、取出一本书\n			5、搜索\n			6、查看菜单\n			7、清屏\n\n");
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

book * readDataByTxt()	//创建链表 
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
	if((fp = fopen("C:\\Users\\wmpscc\\Desktop\\链表\\data.txt","r")) == NULL)
	{
		printf("********************从本地文档加载数据失败********************\n");
		
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
			
			//赋值 
			strcpy(bookp->bookName,bookName);
			strcpy(bookp->authorName,authorName);
			strcpy(bookp->kind,kind);
			bookp->price = price;
			bookp->pageNumber = pageNumber;
			bookp->next = NULL;
			
			prev = bookp;
			
			
		}while(fgetc(fp)!=EOF);
		printf("********************已成功从本地文档加载数据********************\n");
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
	printf("输入要删除的书名:");
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
	printf("输入要执行的命令:");
	while(scanf("%d",&i)!=EOF)
	{
	switch(i)
	{
		case 1:
			showlist(head);
			printf("\n输入要执行的命令:");
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
