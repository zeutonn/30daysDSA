/* This program is a test driver to demonstrate the basic operation of the stack push and pop functions. */
//This program is coppied from Book Pg-91
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	char data;
	struct node* link;
	} STACK_NODE;

void insertData(STACK_NODE** pStackTop);
void print(STACK_NODE** pStackTop);

bool push (STACK_NODE** pList, char dataIn);
bool pop (STACK_NODE** pList, char* dataOut);

int main (void){

	STACK_NODE* pStackTop;

	printf("Beginning Simple Stack Program \n\n");

	pStackTop=NULL;
	insertData (&pStackTop);
	print(&pStackTop);

	printf("\n\n End Simple Stack Program");
	return 0;
}

void insertData(STACK_NODE** pStackTop){
	char charIn;
	bool success;

	for (int nodeCount =0; nodeCount < 10; nodeCount++)
	{
		charIn =rand()%26+'A';
		printf("%c", charIn);
		success=push(pStackTop, charIn);
		if (!success)
		{
			printf("Error 101: Out of Memory \n");
			exit(100);
		}
	}
	printf("\n");
	return; 
}

bool push(STACK_NODE** pStackTop, char charIn){
	STACK_NODE* pNew;
	bool success;

	pNew = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!pNew)
		success= false;
	else{
		pNew->data=charIn;
		pNew->link;
		*pStackTop=pNew;
		success =true;	}
	return success;
}

void print(STACK_NODE** pStackTop)
{

	char printData;

	printf("Stack contained 		");
	while(pop(pStackTop, &printData))
		printf("%c", printData);
	return;
}

bool pop(STACK_NODE** pStackTop, char* charOut)
{
	STACK_NODE* pDlt;
	bool success;

	if(*pStackTop)
	{
		success=true;
		*charOut=(*pStackTop)->data;
		pDlt=*pStackTop;
		*pStackTop=(*pStackTop)->link;
		free(pDlt);
	}
	else
		success=false;
	return success;
}
