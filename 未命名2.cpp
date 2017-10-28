#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book{
	char c[10];	
}Book;


int main()
{
	Book *mBook=(Book *)malloc(sizeof(Book));
//	Book *mBook = NULL;
//	Book *mBook;
	strcpy(mBook->c,"test");
	printf("%s",mBook->c);
	
	return 0;
}
