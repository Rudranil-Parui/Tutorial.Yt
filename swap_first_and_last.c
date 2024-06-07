#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *start=NULL;
void create();
void display();
void swap_first_last();
void create()
{
	//int a[]={10, 20, 30, 40};
	int a[]={10, 20, 30, 40, 20, 20, 10, 10, 70, 30};
	//int a[]={10};
	int i;
	int n=sizeof(a)/sizeof(a[0]);
	struct node *p;
	for(i=0; i<n; i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=a[i];
		temp->link=NULL;
		if(i==0)
		{
			start=temp;
			p=start;
		}
		else
		{
			p->link=temp;
			p=p->link;
		}
	}
}
void display()
{
	printf("\n\nSTART-> ");
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d-> ",p->data);
		p=p->link;
	}
	printf("NULL\n\n");
}
void swap_first_last(){
	if(start==NULL){
		return;
	}
	if(start->link==NULL){
		return;
	}
	struct node *p=start,*q=start->link;
	while(q->link!=NULL){
		p=q;
		q=q->link;
	}
	q->link=start->link;
	p->link=start;
	start->link=NULL;
	start=q;
}
int main()
{
	create();
	printf("Previous linked list is:: ");
	display();
	
	swap_first_last();
	
	printf("After swaping linked list:: ");
	display();
	return 0;
}
