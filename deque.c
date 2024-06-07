#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int DQ[MAX];
int front=-1,rear=-1;
int isEmpty();
int isFull();
void insert_frontend(int);
void insert_rearend(int);
int delete_frontend();
int delete_rearend();
void display();
int isEmpty(){
	return (front==-1)?1:0;
}
int isFull(){
	if((front==rear+1) || (front==0 && rear==MAX-1)){
		return 1;
	}
	else{
		return 0;
	}
}
void insert_frontend(int data){
	if(isFull()==1){
		printf("Queue Overflow");
		return;
	}
	else if(front==-1){
		front=0;
		rear=0;
	}
	else if(front==0){
		front=MAX-1;
	}
	else{
		front=front=-1;
	}
	DQ[front]=data;
}
void insert_rearend(int data){
	if(front==-1){
		front=0;
	}
	rear=(++rear)%MAX;
	DQ[rear]=data;
}
int delete_frontend(){
	if(isEmpty()==1){
		printf("Queue Underflow");
		return -1;
	}
	int v=DQ[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1){
		front=0;
	}
	else{
		front=front+1;
	}
	return v;
}
int delete_rearend(){
	if(isEmpty()==1){
		printf("Queue Underflow");
		return -1;
	}
	int val=DQ[rear];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else if(rear==0){
		rear=MAX-1;
	}
	else{
		rear=rear-1;
	}
	return val;
}
void display(){
	/*if(isEmpty()==1){
		printf("Queue Empty");
		return;
	}
	int i;
	printf("Deque:-\n");
	for(i=0;i<MAX;i++){
		if(i==front){
			printf("Front->");
		}
		if(i==rear){
			printf("Rear->");
		}
		printf("%d ",DQ[i]);
	}*/
	/*if(isEmpty()==1){
		printf("Queue Empty");
		return;
	}
	int i=front;
	while(i!=rear){
		printf("%d ",DQ[i]);
		i=(i+1)%MAX;
	}
	printf("%d",DQ[i]);*/
	if(isEmpty()==1){
		printf("Queue Empty");
		return;
	}
	int i;
	if(front<=rear){
		for(i=front;i<=rear;i++){
			printf("%d ",DQ[i]);
		}
	}
	else{
		for(i=front;i<=MAX-1;i++){
			printf("%d ",DQ[i]);
		}
		for(i=0;i<=rear;i++){
			printf("%d ",DQ[i]);
		}
	}
}
int main(){
	int n,p;
	while(1){
		printf("\nPress 1 for insert at front end\n");
		printf("Press 2 for insert at rear end\n");
		printf("Press 3 for delete at front end\n");
		printf("Press 4 for delete at rear end\n");
		printf("Press 5 to check the Queue is empty or not?\n");
		printf("Press 6 to check the Queue is full or not?\n");
		printf("Press 7 for display the Queue\n");
		printf("Press 8 for exit\n");
		printf("Enter your choice:");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Enter the number to insert at front end:");
				scanf("%d",&p);
				insert_frontend(p);
				break;
			case 2:
				printf("Enter the number to insert at rear end:");
				scanf("%d",&p);
				insert_rearend(p);
				break;
			case 3:
				p=delete_frontend();
				if(p==-1){
					printf("Queue is Empty");
					break;
				}
				else{
					printf("Deleted item is:%d",p);
					break;
				}
			case 4:
				p=delete_rearend();
				if(p==-1){
					printf("Queue is Empty");
					break;
				}
				else{
					printf("Deleted item is:%d",p);
					break;
				}
			case 5:
				display();
				break;
			case 6:
				(isFull()==1)?printf("The queue is Full"):printf("The queue is not Full");
				break;
			case 7:
				display();
				break;
			case 8:
				exit (0);
				break;
			default:
				printf("Invalid Input");
				break;
		}
	}
}
