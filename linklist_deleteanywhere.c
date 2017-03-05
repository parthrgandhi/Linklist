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
	
	return ((a>l || a<1));
	
}


//Function to  delete Node at First position:
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


//Function to delete Node at End position:
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


//Function to delete Node between 1st and last node:
void deletebtw (int a)
{
	struct node *pos = head;
	struct node *previous;
	struct node *current;
	int i;
	
	for (i=1;i<=a;i++)
	{
		
		if(i==a-1)
		{
			previous = pos;
		}
		
		else if (i==a)
		{
			current = pos;
		}

		pos = pos->next;
		
	}
	
	
	previous->next = pos;
	
	current->next = NULL;
			
}


//Function to delete ANY Node :
void deleteanywhere(int a)
{
	int list = listempty();
	int v = validateposition(a);
	int l = length();
	
	if (list ==1 && v==1)
	{
		printf("\nList is Empty : Cannot Perform Delete Operation\n");
	}
	else if(list ==0 && v == 1)
	{
		printf("\nOut of Bound position : Cannot Perform Delete Operation\n");
	}
	else if(list ==0 && v == 0 && a==1)
	{
		deletefirst();
	}
	else if(list ==0 && v == 0 && a==l)
	{
		deletelast();
	}
	else
	{
		deletebtw(a);
	}
}




void main()
{
	create(10);
	create(8);
	create(5);
	create(15);
	create(18);
	int a;
	
	printf("-----Original List-------\n\n");
	printlist();
	
	printf("---------- Enter Node Position to be deleted-------\n\n");
	scanf("%d",&a);
	
    deleteanywhere(a);
	
	printf("\n\n --------List After New Element--------\n\n");
    printlist();
	
}
