#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;
struct node *last=NULL;
void insert_Begin(int);
void insert_End(int);
void insert_After(int,int);
int delete_Begin();
int delete_End();
void delete_item(int);
int count();
struct node* search_node(int);
void display();
void reverse();
void create(int);
void insert_Begin(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if(last==NULL)
    {
        temp->link=temp;
        last=temp;
        return;
    }
    temp->link=last->link;
    last->link=temp;
}
void insert_End(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if(last==NULL)
    {
        temp->link=temp;
        last=temp;
        return;
    }
    temp->link=last->link;
    last->link=temp;
    last=temp;
}
void insert_After(int value,int item)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if(last==NULL)
    {
        printf("Empty linked list");
        return;
    }
    if(item==last->data)
    {
    temp->link=last->link;
    last->link=temp;
    last=temp;
    }
    struct node *p=last->link;
    int flag=0;
    while(p!=last)
    {
        if(p->data==item)
        {
            flag=1;
            break;
        }
        p=p->link;
    }
    if(flag==0)
    {
        printf("%d is not found",item);
        return;
    }
    temp->link=p->link;
    p->link=temp;
}
int delete_Begin()
{
    if(last==NULL)
    {
        printf("Empty Linked List");
        return -1;
    }
    struct node *p;
    int v;
    if(last->link==last)
    {
        v=last->data;
        p=last;
        last=NULL;
        free(p);
    }
    else
    {
        p=last->link;
        v=p->data;
        last->link=p->link;
        p->link=NULL;
        free(p);
    }
    return v;
}
int delete_End()
{
    if(last==NULL)
    {
        printf("Empty Linked List");
        return -1;
    }
    struct node*p;
    int v;
    if(last->link==last)
    {
        v=last->data;
        p=last;
        last=NULL;
        free(p);
    }
    else
    {
        p=last->link;
        while(p->link!=last)
        {
            p=p->link;
        }
        p->link=last->link;
        v=(p->link)->data;
        last->link=NULL;
        free(last);
        last=p;
    }
    return v;
}
void delete_item(int item)
{
    if(last==NULL)
    {
        printf("Empty Linked List");
        return;
    }
    struct node *p;
    if(last->link==last && last->data==item)
    {
        p=last;
        last=NULL;
        free(p);
    }
    if(last->data==item)
    {
        p=last->link;
        while(p->link!=last)
        {
            p=p->link;
        }
        p->link=last->link;
        last->link=NULL;
        free(last);
        last=p;
    }
    int flag=0;
    struct node *q;
    p=last->link;
    while(p->link!=last)
    {
        if(p->data=item)
        {
            flag=1;
            break;
        }
        q=p;
        p=p->link;
    }
    if(flag==0)
    {
        printf("%d is not found",item);
        return;
    }
    q->link=p->link;
    p->link=NULL;
    free(p);
}
int count()
{
    struct node *p;
    int i=0;
    if(last==NULL)
    {
        printf("Empty Linked List");
        return 0;
    }
    if(last->link=last)
    {
        printf("Only one node is present");
        return 1;
    }
    p=p->link;
    while(p!=last)
    {
        i++;
        p=p->link;
    }
    return (i+1);
}
/*
int count()
{
    if(last==NULL)
    {
        printf("Empty Linked List");
        return 0;
    }
    struct node *p=last->link;
    int c=1;
    while(p!=last)
    {
        c++;
        p=p->link;
    }
    return c;
}
*/
struct node* search_node(int item)
{
    if(last==NULL)
    {
        printf("Empty Linked List");
        return NULL;
    }
    if(last->data==item)
    {
        return last;
    }
    int flag=0;
    struct node *p=p->link;
    while(p!=last)
    {
        if(p->data==item)
        {
            flag=1;
            break;
        }
        p=p->link;
    }
    if(flag==0)
    {
        printf("%d is not found",item);
        return NULL;
    }
    return p;
}
void display()
{
    if(last==NULL)
    {
        printf("Empty Linked List");
        return;
    }
    struct node *p=last->link;
    while(p!=last)
    {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("%d->",last->data);
    printf("last");
}
void reverse()
{
    struct node *ptr,*next,*prev;
    if(last==NULL)
    {
        printf("Empty Linked List. Reverse not required");
    return;
    }
    if(last->link==last)
    {
        printf("Only one node is present. Reverse not required");
    return;
    }
    prev=last;
    ptr=last->link;
    next=ptr->link;
    while(ptr!=NULL)
    {
        ptr->link=prev;
        prev=ptr;
        ptr=next;
        next=next->link;
    }
    ptr->link=prev;
    last=next;
}
void create(int n)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *p,*q;
	int i;
	printf("Enter the value:");
	scanf("%d",&temp->data);
	p=temp;
	q=temp;
	for(i=1;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the value:");
		scanf("%d",&temp->data);
		p->link=temp;
		temp->link=q;
		p=p->link;
	}
	last=temp;
}
/*void create(int n)
{
	struct node *p,*q;
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
			q=temp;
			p=temp;
		}
		else
		{
			p->link=temp;
			p=p->link;
		}
	}
}*/
int main() 
{
    int key,n,value,item,pos,z,x;
    printf("%c Enter the size of the Linked List:",254);
    scanf("%d",&n);
    create(n);
    while(1)
    {
    	printf("\n\n%c Your current circular linked list is:\n",178);
    	display();
        printf("\n");
		printf("\n%c Press 1 for Insert Begin\n",249);
		printf("%c Press 2 for Insert End\n",249);
		printf("%c Press 3 for Insert After\n",249);
		printf("%c Press 4 for Count the no. of node\n",249);
		printf("%c Press 5 for Search a node\n",249);
		printf("%c Press 6 for Delete begin\n",249);
		printf("%c Press 7 for Delete end\n",249);
		printf("%c Press 8 for Delete a node\n",249);
		printf("%c Press 9 for Reverse the Linked List\n",249);
		printf("%c Press 10 for Display the Linked List\n",249);
		printf("%c Press 11 for EXIT\n",249);
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
				z=count();
				printf("No. of nodes in the linked list:%d",z);
				break;
			case 5:
				printf("Enter the item to search:");
				scanf("%d",&item);
				struct node *w;
				w=search_node(item);
				printf("Node Address - %p, Data - %d",w,w->data);
				break;
			case 6:
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
			case 7: 
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
			case 8:
				printf("Enter the item to delete:");
				scanf("%d",&item);
				delete_item(item);
				break;
			case 9:
				reverse();
				break;
			case 10:
				display();
				break;
			case 11:
				exit (0);
				break;
			default:
				printf("Invalid Output");
		}
	}
    return 0;
}
