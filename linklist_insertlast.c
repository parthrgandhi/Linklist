#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

void create(int a)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp ->data = a;
	temp ->next = head;
	head = temp;

}


//Function to find the length of Linklist
int length ()
{
	int length = 0;
	struct node *pos = head;
	
	while (pos != NULL)
	{
		length++;
		pos = pos->next;
	}
	
	return length;
}


//Function to insert Node at End position:
void insertlast(int b)
{
	int i;
	int l = 0;
	struct node *pos = head;
	
	l= length();
	
	for (i=1;i<=l-1;i++)
	{
		pos = pos ->next;
	}
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = b;
	
	temp->next = NULL;
	
	pos->next = temp;
	
}


void printlist()
{
	struct node *pos = head;
	
	while (pos != NULL)
	{
		printf("%d\t:\t%d\n",pos->data,pos);
		//printf("%d\n",pos->data);
		pos = pos->next;
	}
}

void main()
{
	create(10);
	create(8);
	create(5);
	create(15);
	create(18);
	
	printlist();
	
}
