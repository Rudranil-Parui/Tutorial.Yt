#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int CQ[MAX];
int front=-1,rear=-1;
int isEmpty(){
	if(front==-1 && rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(){
	if((front==rear+1)||(front==0 && rear==MAX-1)){
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(int item){
	if(isFull()==1){
		printf("Queue Overflow");
		return;
	}
	if(front==-1){
		front=0;
	}
	rear=(++rear) % MAX;
	CQ[rear]=item;
}
int dequeue(){
	if(isEmpty()==1){
		printf("Queue Underflow");
		return -1;
	}
	int v=CQ[front];
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
int peek(){
	return (isEmpty()?-1:CQ[front]);
}
void display(){
	if(isEmpty()==1){
		printf("Queue is Empty");
		return;
	}
	int i;
	if(rear>=front){
		for(i=0;i<=MAX-1;i++){
			if(i==front || (i<=rear && i>front)){
				printf("%d ",CQ[i]);
			}
			else{
				printf("_");
			}
		}
	}
	else{
		for(i=0;i<=MAX-1;i++){
			if(i>rear && i<front){
				printf("_");
			}
			else
			{
				printf("%d ",CQ[i]);
			}
		}
	}
}
int main(){
	int choice,item,z;
	while(1){
		printf("\n%c Press 1 for Enqueue operation\n",249);
		printf("%c Press 2 for Dequeue operation\n",249);
		printf("%c Press 3 to check the Queue is empty?\n",249);
		printf("%c Press 4 to check the Queue is full?\n",249);
		printf("%c Press 5 for peek the front element of the Queue\n",249);
		printf("%c Press 6 for display the Queue\n",249);
		printf("%c Press 7 for Exit\n",249);
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the item to Enqueue:");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 2:
				z=dequeue();
				if(z==-1){
					continue;
				}
				else{
					printf("The deleted item is %d",z);
				}
				break;
			case 3:
				z=isEmpty();
				if(z==1){
					printf("The Queue is Empty");
				}
				else{
					printf("The Queue is not Empty");
					display();
				}
				break;
			case 4:
				z=isFull();
				if(z==1){
					printf("The Queue is Full");
				}
				break;
			case 5:
				z=peek();
				if(z==-1){
					printf("The Queue is empty");
					break;
				}
				printf("The peek element is %d",z);
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("Invalid Input");
		}
	}
	return 0;
}
