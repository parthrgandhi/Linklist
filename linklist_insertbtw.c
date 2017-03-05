#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

//int length = 0;

//Function Declaration & definition

void create(int a)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	//Enter data in temporary link
	temp->data = a;
	
	//Point Next to Previous Link
	temp->next = head;
	
	//Point head to new link
	head = temp;
	
}

void printlist()
{
	struct node *pos=head;
	
	while(pos != NULL)
	{
		printf("%d\t:%d\n",pos,pos->data);
		pos = pos->next;
	}
}

void insertbtw(int a, int b)
{
	int i=1;
	struct node *pos = head;
	struct node *current;
	struct node *previous;
	
	
	for(i=1; i<= a+1;i++)
	{
		if (i == a-1)
		{
		    previous = pos;
		}
		if (i == a)
		{
			current = pos;
		}
		pos = pos->next;
	}
	
	printf("\n\n-----just checking----\n\n");
	printf("Previous : %d\n",previous->data);
	printf("Current : %d\n",current->data);
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	//new data at Ath position
	temp->data = b;
	
	//Point New Node to Ath node
	temp->next = current;
	
	//Point (A-1)th node to new node
	previous->next = temp; 
	
}

void main()
{
	create(10);
	create(8);
	create(5);
	create(15);
	create(18);
	
	printf("-----Original List-------\n\n");
	printlist();
	
	insertbtw(3,89);
	
	printf("\n\n --------List After New Element--------\n\n");
    printlist();
	
}
