#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr_queue[MAX];
int front=-1,rear=-1;
int isEmpty(){
	if(front==-1 || front==rear+1){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(){
	if(rear==MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(int item){
	if(isFull()==1){
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1){
		front=0;
	}
	rear=rear+1;
	arr_queue[rear]=item;
}
int dequeue(){
	int v;
	if(isEmpty()==1){
		printf("Queue Underflow\n");
		return -1;
	}
	v=arr_queue[front];
	front=front+1;
	return v;
}
int peek(){
	return (isEmpty()?-1:arr_queue[front]);
	/*if(isEmpty()==1){
		printf("Queue Underflow");
		return -1;
	}
	int val=arr_queue[front];
	return val;
}
void display(){
	int i;
	if(isEmpty()==1){
		printf("Queue is Empty");
		return;
	}
	printf("Queue: -\n");
	for(i=front;i<=rear;i++){
		printf("%d  ",arr_queue[i]);
	}
	printf("\n");
}
int main(){
	int choice,item,z;
	while(1)
	{
		printf("\n%c Press 1 for Enqueue operation\n",249);
		printf("%c Press 2 for Dequeue operation\n",249);
		printf("%c Press 3 to check the Queue is empty?\n",249);
		printf("%c Press 4 to check the Queue is full?\n",249);
		printf("%c Press 5 for peek the front element of the Queue\n",249);
		printf("%c Press 6 for display the Queue\n",249);
		printf("%c Press 7 for Exit\n",249);
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
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
