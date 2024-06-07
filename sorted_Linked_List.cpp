#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}node;
struct node *start=NULL;
void insert(int);
void delete_item(int);
struct node* search_node(int);
void display();
void create(int);
void insert(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if(start==NULL)
    {
        temp->link=NULL;
        start=temp;
    }
    else
    {
        if(start->data>value)
        {
            temp->link=start;
            start=temp;
        }
        else
        {
            struct node *p=start,*q=start->link;
            while(q!=NULL)
            {
                if(q->data>value)
                {
                    break;
                }
                p=q;
                q=p->link;
            }
            p->link=temp;
            temp->link=q;
        }
    }
}
void delete_item(int item)
{
    if(start==NULL)
    {
        printf("Empty Linked List");
        return;
    }
    struct node *p=start,*q=start->link;
    int flag=0;
    if(p->data==item)
    {
        p->link=NULL;
        start=q;
        free(p);
    }
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
    p->link=q->link;
    q->link=NULL;
    free(q);
    while(1)
    {
    	
	}
}
struct node* search_node(int item)
{
    if(start==NULL)
    {
        printf("Empty Linked List");
        return NULL;
    }
    struct node *p=start;
    int i=0,flag=0;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        temp->data=-1;
        temp->link=NULL;
        return temp;
    }
    while(p!=NULL)
    {
        if(p->data==NULL)
        {
            flag=1;
            break;
        }
        i++;
        p=p->link;
    }
    if(flag==0)
    {
        temp->data=-1;
        temp->link=NULL;
        return temp;
    }
    else
    {
        temp->data=(i+1);
        temp->link=p;
        return temp;
    }
}
void create(int n)
{
	struct node *p;
	int i,v;
	for(i=0;i<n;i++)
	{
		printf("Enter the value:");
		scanf("%d",&v);
		insert(v);
	}
}
void display()
{
	printf("START-> ");
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d-> ",p->data);
		p=p->link;
	}
	printf("NULL");
}
int main() 
{
	int n,key,value,item;
	printf("%c Enter the size of the sorted node:",254);
	scanf("%d",&n);
	create(n);
	while(1)
	{
		printf("\n\n%c Your current Sorted Linked List is :\n\n",178);
        display();
		printf("\n\n\n%c Press 1 for Insert an item\n",249);
		printf("%c Press 2 for Delete an item\n",249);
		printf("%c Press 3 for Search a node\n",249);
		printf("%c Press 4 for Display the linked list\n",249);
		printf("%c Press 5 for Exit\n",249);
		printf("\nEnter your choice::");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				printf("Enter the value to insert:");
				scanf("%d",&value);
				insert(value);
				break;
			case 2:
				printf("Enter the item to delete:");
				scanf("%d",&item);
				delete_item(item);
				break;
			case 3:
				printf("Enter the item to search:");
				scanf("%d",&item);
				struct node *w;
				w=search_node(item);
				printf("Node Address - %p, Data - %d",w,w->data);
				break;
			case 4:
				printf("Your current Sorted Linked List is :\n\n");
				display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid Output");
		}
	}
    return 0;
}
