#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;



//Function Declaration & definition:


//Function to Create New List from Node 1:
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


//Function to print list of all node within Linklist
void printlist()
{
	struct node *pos=head;
	
	while(pos != NULL)
	{
		printf("%d\t:%d\n",pos,pos->data);
		pos = pos->next;
	}
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

//Function to check List is empty or not
bool listempty()
{
	return (head == NULL);
}


//Function to check New Inserted Node is within range or not:
bool validateposition(int a)
{
	int l=0;
	
	l= length();
	
	return ((a>l || a<2));
	
}


//Function to delete Node between 1st and last node:
void deletefirst ()
{
	struct node *pos = head;
	struct node *current;
	int i;
	
	for (i=1;i<=2;i++)
	{
		if (i==2)
		{
			current = head;
			head = pos;
			current->next = NULL;
		}
		
		pos = pos->next;
	}
		

			
}

void deletelast ()
{
	struct node *pos = head;
	struct node *current;
	int i;
	int l = length();
	
	for (i=1;i<l-1;i++)
	{
		pos=pos->next;
		if (i==l-2)
		{
		  pos->next = NULL;
			
		}
		
	}
		

			
}

//Function to insert Node at End position:



void main()
{
	create(10);
	create(8);
	create(5);
	create(15);
	create(18);
	
	printf("-----Original List-------\n\n");
	printlist();
	
    deletefirst();
    deletelast();
	
	printf("\n\n --------List After New Element--------\n\n");
    printlist();
	
}
