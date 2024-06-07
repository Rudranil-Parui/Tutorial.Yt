#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
} node;
void insert_Begin(int);
void insert_End(int);
void insert_After(int,int);
void insert_Before(int,int);
void insert_Before_pointer(int,int);
int count();
void insert_At_Position(int,int);
int search_position(int);
int delete_End();
int delete_End_pointer();
int delete_After(int);
int delete_Before(int);
int delete_Node(int);
void reverse();
void display();
void create(int);
struct node *START=NULL;
void insert_Begin(int value)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START==NULL)
	{
		temp->link=NULL;
		START=temp;
	}
	else
	{
		temp->link=START;
		START=temp;
	}
}
void insert_End(int value)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START==NULL)
	{
		temp->link=NULL;
		START=temp;
	}
	else
	{
		struct node *p=START;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
		temp->link=NULL;
	}
}
void insert_After(int value,int item)
{
	if(START==NULL)
	{
		printf("Linked list is empty");
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	int flag=0;
	struct node *p=START;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->link;
	}
	if(flag==1)
	{
		temp->link=p->link;
		p->link=temp;
	}
	else
	{
		printf("Data %d is not found",item);
	}
}
void insert_Before(int value,int item)
{
	if(START==NULL)
	{
		printf("Linked list is empty!");
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START->data==item)
	{
		temp->link=START;
		START=temp;
		return;
	}
	struct node *p=START;
	int flag=0;
	while(p->link!=NULL)
	{
		if((p->link)->data==item)
		{
			flag=1;
			break;
		}
		p=p->link;
	}
	if(flag==1)
	{
		temp->link=p->link;
		p->link=temp;
	}
	else
	{
		printf("%d is not found",item);
	}
}
void insert_Before_pointer(int item,int value)
{
	if(START==NULL)
	{
		printf("Linked list is empty!");
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START->data==item)
	{
		temp->link=START;
		START=temp;
		return;
	}
	struct node *p=START;
	struct node *q=START->link;
	int flag=0;
	while(q!=NULL)
	{
		if(q->data==item)
		{
			flag=1;
			break;
		}
		p=q;
		q=q->link;
	}
	if(flag==0)
	{
		printf("%d is not found",item);
		return;
	}
	temp->link=q;
	p->link=temp;
}
int count()
{
	struct node *p=START;
	int i=0;
	while(p!=NULL)
	{
		p=p->link;
		i=i+1;
	}
	return i;
}
void insert_At_Position(int pos,int value)
{
	int i;
	if(START==NULL&&pos>1)
	{
		printf("Position not found");
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START==NULL&&pos==1)
	{
		temp->link=NULL;
		START=temp;
	}
	int flag=0;
	struct node *p=START;
	if(pos>count()+1||pos<=0)
	{
		printf("Position not found! position should start from 1");
		return;
	}
	for(i=1;i<pos-1;i++)
	{
		p=p->link;
		flag=1;
	}
	if(flag==0&&pos==1)
	{
		insert_Begin(value);
	}
	else
	{
		temp->link=p->link;
		p->link=temp;
	}
}
int search_position(int item)
{
	if(START==NULL)
	{
		printf("Search is not possible");
		return -1;
	}
	struct node *p=START;
	int i=0,flag=0;
	while(p!=NULL)
	{
		i=i+1;
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->link;
	}
	if(flag==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
int delete_Begin()
{
	int v;
	if(START==NULL)
	{
		printf("Nothing to delete");
		return -1;
	}
	else
	{
		struct node *p=START;
		START =p->link;
		v=p->data;
		p->link=NULL;
		free(p);
		return v;
	}
}
int delete_End()
{
	int v;
	if(START==NULL)
	{
		printf("Nothing to delete");
		return -1;
	}
	else if(START->link==NULL)
	{
		v=START->data;
		free(START);
		START=NULL;
	}
	else
	{
		struct node *p=START;
		while((p->link)->link!=NULL)
		{
			p=p->link;
		}
		struct node *q=p->link;
		p->link=NULL;
		v=q->data;
		free(q);
	}
	return v;
}
int delete_End_pointer()
{
	int v;
	if(START==NULL)
	{
		printf("Nothing to delete");
		return -1;
	}
	else if(START->link==NULL)
	{
		v=START->data;
		START=NULL;
		free(START);
	}
	else
	{
		struct node *p=START;
		struct node *q=START->link;
		while(q->link!=NULL)
		{
			p=p->link;
			q=q->link;
		}
		p->link=NULL;
		v=q->data;
		free(q);
	}
	return v;
}
int delete_After(int item)
{
	int v;
	if(START==NULL)
	{
		printf("Nothing to delete");
		return -1;
	}
	else if(START->link==NULL)
	{
		printf("Only one node is present");
		return -1;
	}
	int flag=0;
	struct node *p=START;
	struct node *q=START->link;
	if(START->data==item)
	{
		
	}
	while(q!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=q;
		q=q->link;
	}
	if(flag==0)
	{
		return -1;
	}
	if(p->link==NULL)
	{
		
	}
	p->link=q->link;
	v=q->data;
	q->link=NULL;
	free(q);
	return v;
}
int delete_Before(int value)
{
	if(START==NULL)
	{
		printf("List Empty!");
		return -1;
	}
	if(START->data==value)
	{
		printf("No data present before");
		return -1;
	}
	struct node *p,*q=START;
	int flag=0,v;
	while(q->link!=NULL)
	{
		if((q->link)->data==value)
		{
			flag=1;
			break;
		}
		p=q;
		q=q->link;
	}
	if(flag==0)
	{
		printf("Value %d is not present",value);
		return -1;
	}
	v=q->data;
	if(q==START)
	{
		START=q->link;
	}
	else
	{
		p->link=q->link;
	}
	q->link=NULL;
	free(q);
	return v;
}
int delete_Node(int value)
{
	if(START==NULL)
	{
		printf("List empty!");
		return -1;
	}
	struct node *p,*q=START;
	int v,flag=0;
	while(q!=NULL)
	{
		if(q->data==value)
		{
			flag=1;
			break;
		}
		p=q;
		q=q->link;
	}
	if(flag==0)
	{
		printf("Data %d is not found",value);
	}
}
void reverse()
{
	if(START==NULL)
	{
		printf("Linked list empty!");
		return;
	}
	if(START->link==NULL)
	{
		printf("one node is present, reverse not required");
		return;
	}
	struct node *p,*prev,*next;
	p=START,prev=NULL;
	while(p!=NULL)
	{
		next=p->link;
		p->link=prev;
		prev=p;
		p=next;
	}
	START=prev;
}
void display()
{
	printf("START-> ");
	struct node *p=START;
	while(p!=NULL)
	{
		printf("%d-> ",p->data);
		p=p->link;
	}
	printf("NULL");
}
void create(int n)
{
	struct node *p;
	int i,v;
	for(i=0;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter value::");
		scanf("%d",&v);
		temp->data=v;
		temp->link=NULL;
		if(i==0)
		{
			START=temp;
			p=START;
		}
		else
		{
			p->link=temp;
			p=p->link;
		}
	}
}
int main()
{
	int n,key,value,item,pos,z,x;
	printf("%c Enter the no. of nodes::",254);
	scanf("%d",&n);
	create(n);
	key=0;
	while(key!=17)
	{
		printf("\n\n%c Your current Singly Linked List is :\n\n",178);
        display();
		printf("\n\n\n%c Press 1 for Insert Begin\n",249);
		printf("%c Press 2 for Insert End\n",249);
		printf("%c Press 3 for Insert After\n",249);
		printf("%c Press 4 for Insert Before\n",249);
		printf("%c Press 5 for Insert Before using pointer\n",249);
		printf("%c Press 6 for Count the no. of node\n",249);
		printf("%c Press 7 for Insert at position\n",249);
		printf("%c Press 8 for Search a item\n",249);
		printf("%c Press 9 for Delete begin\n",249);
		printf("%c press 10 for Delete end\n",249);
		printf("%c Press 11 for Delete end using pointer\n",249);
		printf("%c Press 12 for Delete after\n",249);
		printf("%c Press 13 for Delete before\n",249);
		printf("%c Press 14 for Delete node\n",249);
		printf("%c Press 15 for Reverse the Linked List\n",249);
		printf("%c Press 16 for Display the Linked List\n",249);
		printf("%c Press 17 for EXIT\n",249);
		printf("\nEnter your choice::");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				printf("Enter the value to insert at Begin:");
				scanf("%d",&value);
				insert_Begin(value);
				break;
			case 2:
				printf("Enter the value to insert at End:");
				scanf("%d",&value);
				insert_End(value);
				break;
			case 3:
				printf("Enter the value to insert After:");
				scanf("%d",&value);
				printf("Enter the item to insert After:");
				scanf("%d",&item);
				insert_After(value,item);
				break;
			case 4:
				printf("Enter the value to insert Before:");
				scanf("%d",&value);
				printf("Enter the item to insert Before:");
				scanf("%d",&item);
				insert_Before(value,item);
				break;
			case 5:
				printf("Enter the value to insert Before:");
				scanf("%d",&value);
				printf("Enter the item to insert Before:");
				scanf("%d",&item);
				insert_Before_pointer(item,value);
				break;
			case 6:
				z=count();
				printf("No. of nodes in the linked list:%d",z);
				break;
			case 7:
				printf("Enter the position to insert:");
				scanf("%d",&pos);
				printf("Enter the value to insert at the position:");
				scanf("%d",&value);
				insert_At_Position(pos,value);
				break;
			case 8:
				printf("Enter the item to search:");
				scanf("%d",&item);
				z=search_position(item);
				if(z==-1)
				{
					printf("%d is not found",item);
				}
				else
				{
					printf("%d is found at %d position",item,z);
				}
				break;
			case 9:
				x=delete_Begin();
				if(x==-1)
				{
					printf("Empty linked list");
				}
				else
				{
					printf("Deleted value is %d",x);
				}
				break;
			case 10: 
				x=delete_End();
				if(x==-1)
				{
					printf("Empty linked list");
				}
				else
				{
					printf("Deleted value is %d",x);
				}
				break;
			case 11:
				x=delete_End_pointer();
				if(x==-1)
				{
					printf("Empty linked list");
				}
				else
				{
					printf("Deleted value is %d",x);
				}
				break;
			case 12:
				printf("Enter the item:");
				scanf("%d",item);
				int x;
				x=delete_After(item);
				if(x==-1)
				{
					printf("Empty linked list");
				}
				else
				{
					printf("Deleted value is %d",x);
				}
				break;
			case 13:
				printf("Enter the item:");
				x=delete_Before(item);
				if(x==-1)
				{
					printf("Empty linked list");
				}
				else
				{
					printf("Deleted value is %d",x);
				}
				break;
			case 14:
				printf("Enter the value to delete:");
				scanf("%d",&value);
				x=delete_Node(value);
				if(x==-1)
				{
					printf("Empty linked list");
				}
				else
				{
					printf("Deleted value is %d",x);
				}
				break;
			case 15:
				reverse();
				break;
			case 16:
				display();
				break;
			case 17:
				key=17;
				break;
			default:
				printf("Invalid Output");
		}
	}
	return 0;
}
