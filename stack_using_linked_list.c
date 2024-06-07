#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node;
struct node *top=NULL;
int isEmpty();
void push(int);
//void push(int,struct node *);
int pop();
//struct node * pop(struct node *);
int peek();
void display();
int isEmpty(){
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void push(int item){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Stack Overflow");
		return;
	}
	temp->data=item;
	temp->link=top;
	top=temp;
}
/*void push(int item,struct node *p){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Stack Overflow");
		return;
	}
	temp->data=item;
	temp->link=p;
	p=temp;
}*/
int pop(){
	if(isEmpty()==1){
		printf("Stack Underflow");
		return -1;
	}
	int value;
	struct node *p=top;
	value=top->data;
	top=top->link;
	free(p);
	return value;
}
/*struct node* pop(struct node *q){
	if(isEmpty()==1){
		printf("Stack Underflow");
		return NULL;
	}
	int value;
	struct node *p=q;
	value=q->data;
	q=q->link;
	free(p);
	printf("Deleted Item is: %d",value);
	return q;
}*/
int peek(){
	if(isEmpty()==1){
		printf("Stack Underflow");
		return -1;
	}
	int v=top->data;
	return v;
}
void display(){
	if(isEmpty()==1){
		printf("Linked List is Empty");
		return;
	}
	struct node *p=top;
	printf("Top->");
	while(p!=NULL){
		printf("%d->",p->data);
		p=p->link;
	}
	printf("NULL");
}
int main(){
	int choice,item,z;
	while(1)
	{
		printf("\n%c Press 1 for push operation\n",249);
		printf("%c Press 2 for pop operation\n",249);
		printf("%c Press 3 to check the stack is empty?\n",249);
		printf("%c Press 4 for peek the top element of the stack\n",249);
		printf("%c Press 5 for display the stack\n",249);
		printf("%c Press 6 for Exit\n",249);
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to push:");
				scanf("%d",&item);
				push(item);
				//push(item,top);
				break;
			case 2:
				z=pop();
				//top=pop(top);
				printf("The deleted item is %d",z);
				break;
			case 3:
				z=isEmpty();
				if(z==1)
				{
					printf("The stack is Empty");
				}
				else{
					printf("The stack is not empty\n");
					display();
				}
				break;
			case 4:
				z=peek();
				printf("The peek element is %d",z);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Invalid Input");
		}
	}
	return 0;
}
