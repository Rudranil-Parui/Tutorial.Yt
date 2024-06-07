#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int priority;
	int data;
	struct node *link;
}node;
struct node *front=NULL;
int isEmpty(){
	return (front==NULL)?1:0;
}
void insert(int prio,int item){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->priority=prio;
	temp->data=item;
	if(isEmpty()==1 || prio<front->priority){
		temp->link=front;
		front=temp;
		return;
	}
	struct node *p=front;
	while(p->link!=NULL){
		if((p->link)->priority>prio){
			break;
		}
		p=p->link;
	}
	temp->link=p->link;
	p->link=temp;
}
int delete_item(){
	if(isEmpty()==1){
		printf("Queue underflow");
		return -1;
	}
	int v=front->data;
	struct node *p=front;
	front=front->link;
	p->link=NULL;
	free(p);
	return v;
}
void display(){
	if(isEmpty()==1){
		printf("Queue is empty");
		return;
	}
	struct node *p=front;
	printf("Front->");
	while(p!=NULL){
		printf("%d %d->",p->priority,p->data);
		p=p->link;
	}
	printf("NULL");
}
int main(){
	int choice,n,p;
	while(1){
		printf("\nPress 1 to insert operation\n");
		printf("Press 2 to delete operation\n");
		printf("Press 3 to display the priority queue\n");
		printf("Press 4 to exit\n");
		printf("Enter your choice::");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the priority:");
				scanf("%d",&p);
				printf("Enter the item to insert:");
				scanf("%d",&n);
				insert(p,n);
				break;
			case 2:
				n=delete_item();
				if(n==-1){
					continue;
				}
				printf("The deleted item is %d",n);
				break;
			case 3:
				printf("Priority queue:-\n");
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Input!");
		}
	}
	return 0;
}
