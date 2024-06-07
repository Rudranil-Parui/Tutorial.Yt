#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node;
struct node *start=NULL;
void create(int);
void display();
void move_min_element();
int diff_max_min();
void swap_first_last();
void move_max_element();
void move_first_element();
int nth_node(int);
void delete_duplicate();
void move_last_element();
//To move minimum element at begin
void move_min_element(){
	if(start==NULL){
		printf("Empty Linked List");
		return;
	}
	if(start->link=NULL){
		printf("Only one node is present");
		return;
	}
	struct node *p,*q=start,*min=start;
	while(q->link!=NULL){
		if((q->link)->data < min->data){
			min=q->link;
			p=q;
		}
		q=q->link;
	}
	if(q->data < min->data){
		p=start;
		while(p->link!=q){
			p=p->link;
		}
		q->link=start;
		p->link=NULL;
		start=q;
	}
	if(min==start){
		return;
	}
	p->link=min->link;
	min->link=start;
	start=min;
}
//To find difference between maximum and minimum element
int diff_max_min(){
	int max,min,d;
	if(start==NULL){
		printf("Empty Linked List");
		return 0;
	}
	if(start->link=NULL){
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
//To swap first and last element
void swap_first_last(){
	if(start=NULL){
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
//To move maximum element at last
void move_max_element(){
	if(start=NULL){
		return;
	}
	if(start->link==NULL){
		return;
	}
	struct node *p=start,*q,*max=start;
	while(p->link!=NULL){
		if((p->link)->data > max->data){
			max=p->link;
			q=p;
		}
		p=p->link;
	}
	if(p->data > max->data){
		return;
	}
	if(start==max){
		start=start->link;
		p->link=max;
		max->link=NULL;
		return;
	}
	q->link=max->link;
	max->link=NULL;
	p->link=max;
}
//To find the nth node from the end of the list
int nth_node(int n){
	if(start==NULL){
		printf("Empty Linked List");
		return -1;
	}
	if(start->link==NULL&&n==1){
		return (start->data);
	}
	struct node *p=start,*q=start;
	int i;
	for(i=1;i<n,q!=NULL;i++){
		q=q->link;
	}
	if(p==NULL){
		printf("%d is greater than no. of node",n);
		return -1;
	}
	while(q->link!=NULL){
		q=q->link;
		p=p->link;
	}
	return (p->data);
}
//To remove first element and insert it at end
void move_first_element(){
	if(start==NULL){
		printf("Empty linked list");
		return;
	}
	if(start->link==NULL){
		printf("Only one node is present");
		return;
	}
	struct node *p=start,*q=start->link;
	while(q->link!=NULL){
		q=q->link;
	}
	q->link=p;
	start=start->link;
	p->link=NULL;
}
//To remove last element and insert it at begin
void move_last_element(){
	if(start==NULL){
		printf("Empty linked list");
		return;
	}
	if(start->link==NULL){
		printf("Only one node is present");
		return;
	}
	struct node *p=start,*q=start->link;
	while(q->link!=NULL){
		p=p->link;
		q=q->link;
	}
	q->link=start;
	p->link=NULL;
	start=q;
}
//To delete the duplicate elements
void delete_duplicate(){
	if(start==NULL){
		printf("Empty linked list");
		return;
	}
	if(start->link==NULL){
		printf("Only one node is present");
		return;
	}
	struct node *p=start,*q,*b;
	while(p!=NULL){
		b=p->link;
		if(b->data==p->data){
			p->link=b->link;
			b->link=NULL;
			free(b);
		}
		else{
			while(b->link!=NULL){
			if((b->link)->data==p->data){
				q=b->link;
				b->link=q->link;
				q->link=NULL;
				free(q);
			}
			else
			{
				b=b->link;
			}
		}
		}
		p=p->link;
	}
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
	printf("START-> ");
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d-> ",p->data);
		p=p->link;
	}
	printf("NULL");
}
int main(){
	int n;
	printf("Enter the size of the linked list: ");
	scanf("%d",&n);
	create(n);
	move_min_element();
	display();
	return 0;
}
