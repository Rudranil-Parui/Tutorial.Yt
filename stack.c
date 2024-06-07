#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top=-1;
void push(int);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int isFull()
{
	if(top=MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow");
		return;
	}
	top=top+1;
	stack_arr[top]=item;
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("Stack Underflow");
		return;
	}
	item=stack_arr[top];
	top=top-1;
	return item;
}
int peek()
{
	int item;
	if(top==MAX-1)
	{
		printf("Stack Overflow");
		return;
	}
	item=stack_arr[top];
	return item;
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("Stack is empty");
		return;
	}
	for(i=top;i>-1;i--)
	{
		printf("%d\n",stack_arr[i]);
	}
	printf("\n");
}
int main()
{
	int choice,item,z;
	while(1)
	{
		printf("\n%c Press 1 for push operation\n",249);
		printf("%c Press 2 for pop operation\n",249);
		printf("%c Press 3 to check the stack is empty?\n",249);
		printf("%c Press 4 to check the stack is full?\n",249);
		printf("%c Press 5 for peek the top element of the stack\n",249);
		printf("%c Press 6 for display the stack\n",249);
		printf("%c Press 7 for Exit\n",249);
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to push:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				z=pop();
				printf("The deleted item is %d",z);
				break;
			case 3:
				z=isEmpty();
				if(z==1)
				{
					printf("The stack is Empty");
				}
				break;
			case 4:
				z=isFull();
				if(z==1)
				{
					printf("The stack is Full");
				}
				break;
			case 5:
				z=peek();
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
