#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *start=NULL;
void create();
void display();
int diff_max_min();
void create()
{
	//int a[]={10, 20, 30, 40};
	int a[]={10, 20, 30, 40, 20, 20, 10, 10, 70, 30};
	//int a[]={10};
	int i;
	int n=sizeof(a)/sizeof(a[0]);
	struct node *p=start;
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
int diff_max_min(){
	int max,min,d;
	if(start==NULL){
		printf("Empty Linked List");
		return 0;
	}
	if(start->link==NULL){
		printf("Only one node is present");
		return -1;
	}
	struct node *p=start;
	max=p->data;
	min=p->data;
	p=p->link;
	while(p!=NULL){
		if(p->data>max){
			max=p->data;
		}
		if(p->data<min){
			min=p->data;
		}
		p=p->link;
	}
	d=max-min;
	return d;
}
int main()
{
	create();
	printf("Previous Linked List :: ");
	display();
	int x=diff_max_min();
	printf("Resust :: %d",x);
	
	/*printf("New Linked List :: ");
	display();*/
	return 0;
}
