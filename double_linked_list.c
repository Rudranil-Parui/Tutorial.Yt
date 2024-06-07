#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;
struct node *START=NULL;
void insert_Begin(int);
void insert_End(int);
void insert_After(int,int);
void insert_Before(int,int);
int count();
void insert_At_Position(int,int);
int search_Position(int);
struct node *search_Node(int);
int delete_Begin();
int delete_End();
int delete_After(int);
int delete_Before(int);
void delete_Node(int);
void reverse();
void display();
void create(int);
//Insertion
void insert_Begin(int value)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->left=NULL;
	if(START==NULL)
	{
		temp->right=NULL;
		START=temp;
		return;
	}
	temp->right=START;
	START->left=temp;
	START=temp;
}
void insert_End(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->right=NULL;
	if(START==NULL)
	{
		temp->left=NULL;
		START=temp;
		return;
	}
	struct node *p=START;
	while(p->right!=NULL)
	{
		p=p->right;
	}
	p->right=temp;
	temp->left=p;
}
void insert_After(int value,int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to insert");
		return;
	}
	int flag=0;
	struct node *p=START;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->right;
	}
	if(flag==0)
	{
		return;
	}
	temp->right=p->right;
	if(p->right!=NULL)
	{
		(p->right)->left=temp;
	}
	p->right=temp;
	temp->left=p;
}
void insert_Before(int value,int item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to print");
		return;
	}
	int flag=0;
	struct node *p=START;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->right;
	}
	if(flag==0)
	{
		printf("%d is not found",item);
		return;
	}
	temp->right=p;
	if(p->data!=START->data)
	{
		(p->left)->right=temp;
	}
	else
	{
		START=temp;
	}
	temp->left=p->left;
	p->left=temp;
}
int count()
{
	struct node *p=START;
	int i=0;
	while(p!=NULL)
	{
		p=p->right;
		i++;
	}
	return i;
}
void insert_At_Position(int value,int pos)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if(START==NULL)
	{
		printf("Linked list empty! Nothing to print");
		return;
	}
	if(pos==1)
	{
		insert_Begin(value);
		return;
	}
	if(pos==(count()+1))
	{
		insert_End(value);
		return;
	}
	if(pos>(count()+1)||pos<0)
	{
		printf("Position not found");
		return;
	}
	struct node *p=START;
	int i=1;
	while(p!=NULL)
	{
		if(i==(pos-1))
		{
			break;
		}
		p=p->right;
		i++;
	}
	temp->right=p->right;
	(p->right)->left=temp;
	p->right=temp;
	temp->left=p;
}
int search_Position(int item)
{
	if(START==NULL)
	{
		printf("Linked list empty! Nothing to print");
		return -1;
	}
	struct node *p=START;
	int i=1;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			return i;
		}
		p=p->right;
		i++;
	}
	return -1;
}
struct node *search_Node(int item)
{
	if(START==NULL)
	{
		printf("Linked list empty! Nothing to print");
		return NULL;
	}
	struct node *p=START;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			return p;
		}
		p=p->right;
	}
	return NULL;
}
//Deletion
int delete_Begin()
{
	struct node *p=START;
	int v;
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to print");
		return -1;
	}
	if(START->right==NULL)
	{
		START=NULL;
		v=p->data;
		free(p);
		return v;
	}
	START=p->right;
	START->left=NULL;
	p->right=NULL;
	v=p->data;
	free(p);
	return v;
}
int delete_End()
{
	struct node *p=START;
	int v;
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to print");
		return -1;
	}
	if(START->right==NULL)
	{
		START=NULL;
		v=p->data;
		free(p);
		return v;
	}
	while(p->right!=NULL)
	{
		p=p->right;
	}
	(p->left)->right=NULL;
	p->left=NULL;
	v=p->data;
	free(p);
	return v;
}
int delete_After(int item)
{
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to print");
		return -1;
	}
	if(START->right==NULL)
	{
		printf("Only one node is present");
		return -1;
	}
	int flag=0,v;
	struct node *p=START;
	while(p->right!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->right;
	}
	if(flag==0)
	{
		printf("%d is not found",item);
		return -1;
	}
	if(p->right==NULL)
	{
		printf("Deletion not posiible");
		return -1;
	}
	p=p->right;
	(p->left)->right=p->right;
	if(p->right!=NULL)
	{
		(p->right)->left=p->left;
	}
	v=p->data;
	p->left=NULL;
	p->right=NULL;
	free(p);
	return v;
}
int delete_Before(int item)
{
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to print");
		return -1;
	}
	if(START->data==item)
	{
		printf("Deletion not possible");
		return -1;
	}
	struct  node *p=START;
	int flag=0,v;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->right;
	}
	if(flag==0)
	{
		printf("%d is not found",item);
		return -1;
	}
	p=p->left;
	if(p->left==NULL)
	{
		(p->right)->left=NULL;
		START=p->right;
		p->right=NULL;
		v=p->data;
		free(p);
		return v;
	}
	(p->right)->left=p->left;
	(p->left)->right=p->right;
	v=p->data;
	p->right=NULL;
	p->left=NULL;
	free(p);
	return v;
}
void delete_Node(int item)
{
	struct node *p=START;
	int flag=0;
	if(START==NULL)
	{
		printf("Linked list is empty! Nothing to print");
		return;
	}
	if(START->data==item)
	{
		if(START->right==NULL)
		{
			START=NULL;
			free (p);
			return;
		}
		START=START->right;
		START->left=NULL;
		p->right=NULL;
		free(p);
		return;
	}
	while(p!=NULL)
	{
		if(p->data==item)
		{
			flag=1;
			break;
		}
		p=p->right;
	}
	if(flag==0 || p==NULL)
	{
		printf("%d is not found",item);
		return;
	}
	if(p->right==NULL)
	{
		(p->left)->right=NULL;
		p->left=NULL;
		free(p);
		return;
	}
	(p->left)->right=p->right;
	(p->right)->left=p->left;
	p->left=NULL;
	p->right=NULL;
	free(p);
	return;
}
void reverse()
{
	if(START==NULL)
	{
		printf("Linked list empty!");
		return;
	}
	struct node *p1,*p2;
	p1=START;
	p2=p1->right;
	p1->right=NULL;
	p1->left=p2;
	while(p2!=NULL)
	{
		p2->left=p2->right;
		p2->right=p1;
		p1=p2;
		p2=p2->left;
	}
	START=p1;
}
void display()
{
	printf("START<->");
	struct node *p=START;
	while(p!=NULL)
	{
		printf("%d<->",p->data);
		p=p->right;
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
		printf("Enter Value:");
		scanf("%d",&v);
		temp->data=v;
		temp->right=NULL;
		temp->left=NULL;
		if(i==0)
		{
			START=temp;
			p=START;
		}
		else
		{
			p->right=temp;
			temp->left=p;
			p=p->right;
		}
	}
}
int main()
{
	int n,key,value,item,pos,z,x;
	printf("%c Enter the no. of nodes::",254);
	scanf("%d",&n);
	create(n);
	while(1)
	{
		printf("\n\n%c Your current Double Linked List is :\n\n",178);
        display();
        printf("\n");
		printf("\n%c Press 1 for Insert Begin\n",249);
		printf("%c Press 2 for Insert End\n",249);
		printf("%c Press 3 for Insert After\n",249);
		printf("%c Press 4 for Insert Before\n",249);
		printf("%c Press 5 for Count the no. of node\n",249);
		printf("%c Press 6 for Insert at position\n",249);
		printf("%c Press 7 for Search a position\n",249);
		printf("%c Press 8 for Search a node\n",249);
		printf("%c Press 9 for Delete begin\n",249);
		printf("%c Press 10 for Delete end\n",249);
		printf("%c Press 11 for Delete after\n",249);
		printf("%c Press 12 for Delete before\n",249);
		printf("%c Press 13 for Delete node\n",249);
		printf("%c Press 14 for Reverse the Linked List\n",249);
		printf("%c Press 15 for Display the Linked List\n",249);
		printf("%c Press 16 for EXIT\n",249);
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
				z=count();
				printf("No. of nodes in the linked list:%d",z);
				break;
			case 6:
				printf("Enter the position to insert:");
				scanf("%d",&pos);
				printf("Enter the value to insert at the position:");
				scanf("%d",&value);
				insert_At_Position(value,pos);
				break;
			case 7:
				printf("Enter the item to search:");
				scanf("%d",&item);
				z=search_Position(item);
				if(z==-1)
				{
					printf("%d is not found",item);
				}
				else
				{
					printf("%d is found at %d position",item,z);
				}
				break;
			case 8:
				printf("Enter the item to search:");
				scanf("%d",&item);
				struct node *w;
				w=search_Node(item);
				printf("Node Address - %p, Data - %d",w,w->data);
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
				printf("Enter the item:");
				scanf("%d",&item);
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
			case 12:
				printf("Enter the item:");
				scanf("%d",&item);
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
			case 13:
				printf("Enter the item to delete:");
				scanf("%d",&item);
				delete_Node(item);
				break;
			case 14:
				reverse();
				break;
			case 15:
				display();
				break;
			case 16:
				exit (0);
				break;
			default:
				printf("Invalid Output");
		}
	}
	return 0;
}
