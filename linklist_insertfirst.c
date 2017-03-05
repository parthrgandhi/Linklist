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

//Function to insert Node at First position:
void insertfirst (int b)
{
	struct node *pos = head;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = b;
	
	temp->next = head;
	
	head = temp;
			
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
	
	insertfirst(53);
	
	printlist();
	
}
