#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node;
struct node *front=NULL,*rear=NULL;
int isEmpty();
void enqueue(int);
int dequeue();
int peek();
void display();
int isEmpty(){
	if(front==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(int item){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Queue Overflow");
		return;
	}
	temp->data=item;
	temp->link=NULL;
	if(front==NULL && rear==NULL){
		front=temp;
		rear=temp;
		return;
	}
	rear->link=temp;
	rear=temp;
}
int dequeue(){
	if(isEmpty()==1){
		printf("Queue Underflow");
		return -1;
	}
	int v=front->data;
	struct node *p=front;
	if(front->link==NULL){
		rear=NULL;
		front=NULL;
		free(p);
	}
	else{
		front=front->link;
		p->link=NULL;
		free(p);
	}
	return v;
}
int peek(){
	if(isEmpty()==1){
		printf("Queue Underflow");
		return -1;
	}
	return (front->data);
}
void display(){
	if(isEmpty()==1){
		printf("Empty Queue");
		return;
	}
	struct node *p=front;
	printf("Front->");
	while(p!=NULL){
		printf("%d->",p->data);
		p=p->link;
	}
	printf("Rear");
}
int main(){
	int n,x,y,z,w;
	while(1){
		printf("\nPress 1 for enqueue:\n");
		printf("Press 2 for dequeue\n");
		printf("Press 3 for check the queue is empty or not?\n");
		printf("Press 4 for display the peek element\n");
		printf("Press 5 for display the Queue\n");
		printf("Press 6 for Exit\n");
		printf("Enter your choice:");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Enter the number to insert:");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2:
				z=dequeue();
				if(z==-1){
					printf("Queue is Empty");
					break;
				}
				else{
					printf("The deleted item is: %d",z);
					break;
				}
			case 3:
				y=isEmpty();
				y==1?printf("Queue is Empty!"):printf("The queue is not empty");
				break;
			case 4:
				w=peek();
				if(w==-1){
					printf("Queue is Empty");
					break;
				}
				else{
					printf("The peek item is: %d",w);
					break;
				}
			case 5:
				printf("Queue:-\n");
				display();
				break;
			case 6:
				exit (0);
				break;
			default:
				printf("Invalid Input");
		}
	}
	return 0;
}
