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


//Function to insert Node at First position:
void insertfirst (int b)
{
	struct node *pos = head;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = b;
	
	temp->next = head;
	
	head = temp;
			
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

//Function to insert elements at position
void insertanywhere(int a, int b)
{
	int i;
	int l = length();
	struct node *pos = head;
	struct node *current;
	struct node *previous;
	
	bool x = listempty();
	bool y = validateposition(a); 
	
	if (x==1)
	{
		printf("\n\n------------List is Empty -------\n\n\t-------Create New List to to Use Insert Function------\n\n");
	}
	
	else if (x==0 && y==0)
	{
	
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
		
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		
		//new data at Ath position
		temp->data = b;
		
		//Point New Node to Ath node
		temp->next = current;
		
		//Point (A-1)th node to new node
		previous->next = temp; 
	
	}
	
	else if(y==1)
	{
		if (a==1)
		{
			insertfirst(b);			
		}
		else if (a==l+1)
		{
			insertlast(b);
		}
		else
		{
			printf("\n\n-----Invalid Position ( %d ) to Enter ---- Out of Range (Length of List = %d)----\n\n",a,l);
		}
	}
		
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
	
	insertanywhere(3,89);
	insertanywhere(1,33);
	insertanywhere(8,56);
	insertanywhere(15,30);
	insertanywhere(0,25);
	
	printf("\n\n --------List After New Element--------\n\n");
    printlist();
	
}
