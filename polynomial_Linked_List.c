#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    float coeff;
    int expo;
    struct node *link;
}node;
struct node *start=NULL;
struct node *insert(struct node *,float,int);
struct node *insert_End(struct node *,float,int);
struct node *create(struct node *);
void display(struct node *);
void addition(struct node *,struct node *);
void subtraction(struct node *,struct node *);
void multiplication(struct node *,struct node *);
struct node *insert(struct node *start,float co,int ex)
{
    if(co==0)
    {
        return start;
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=co;
    temp->expo=ex;
    if(start==NULL||ex>start->expo)
    {
        temp->link=start;
        start=temp;
        return start;
    }
    if(ex==start->expo)
    {
        start->coeff+=co;
        return start;
    }
    struct node *p=start;
    while(p->link!=NULL)
    {
        if((p->link)->expo<ex)
        {
            temp->link=p->link;
            p->link=temp;
            return start;
        }
        if((p->link)->expo==ex)
        {
            p->link->coeff+=co;
            return start;
        }
        p=p->link;
    }
    p->link=temp;
    temp->link=NULL;
    return start;
}
struct node *insert_End(struct node *start,float co,int ex)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->coeff=co;
    temp->expo=ex;
    if(start==NULL)
    {
        temp->link=NULL;
        start=temp;
        return start;
    }
    struct node *p=start;
    while(p->link!=NULL)
    {
    	p=p->link;
    }
    p->link=temp;
    temp->link=NULL;
    return temp;
}
struct node *create(struct node *start)
{
	int n,ex,i;
	float co;
	printf("%c Enter the size of the Polinomial List:",256);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%c Enter coefficient %d: ",258,i+1);
		scanf("%f",&co);
		printf("%c Enter exponent %d: ",258,i+1);
		scanf("%d",&ex);
		start=insert(start,co,ex);
	}
	return start;
}
void display(struct node *start)
{
	printf("\n\n%c Polynomial :: ",254);
	if(start==NULL)
	{	
		printf("Empty Polynomial List");
		return;
	}
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->coeff<0)
		{
			printf("-");
		}
		if(p->coeff>0&&p!=start)
		{
			printf("+");
		}
		if(p->expo==0)
		{
			printf("%.1f",p->coeff);
		}
		else
		{
			printf("%.1fx^%d",p->coeff,p->expo);
		}
		p=p->link;
	}
	printf("\n\n");
}
void addition(struct node *start1,struct node *start2)
{
	struct node *start3=NULL;
	if(start1==NULL&&start2==NULL)
	{
		printf("Addition not possible");
		return;
	}
	struct node *p1=start1,*p2=start2;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->expo>p2->expo)
		{
			start3=insert(start3,p1->coeff,p1->expo);
			p1=p1->link;
		}
		if(p1->expo<p2->expo)
		{
			start3=insert(start3,p2->coeff,p2->expo);
			p2=p2->link;
		}
		if(p1->expo==p2->expo)
		{
			start3=insert(start3,(p1->coeff+p2->coeff),p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
		if(p1!=NULL)
		{
			while(p1!=NULL)
			{
				start3=insert(start3,p1->coeff,p1->expo);
				p1=p1->link;
			}
		}
		if(p2!=NULL)
		{
			while(p2!=NULL)
			{
				start3=insert(start3,p2->coeff,p2->expo);
				p2=p2->link;
			}
		}
	}
	printf("%c Polynomial Addition:",178);
	display(start3);
}
void subtraction(struct node *start1,struct node *start2)
{
	struct node *start3=NULL;
	if(start1==NULL&&start2==NULL)
	{
		printf("Subtraction not possible");
		return;
	}
	struct node *p1=start1,*p2=start2;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->expo>p2->expo)
		{
			start3=insert(start3,p1->coeff,p1->expo);
			p1=p1->link;
		}
		if(p1->expo<p2->expo)
		{
			start3=insert(start3,p2->coeff,p2->expo);
			p2=p2->link;
		}
		if(p1->expo==p2->expo)
		{
			start3=insert(start3,(p1->coeff-p2->coeff),p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
		if(p1!=NULL)
		{
			while(p1!=NULL)
			{
				start3=insert(start3,p1->coeff,p1->expo);
				p1=p1->link;
			}
		}
		if(p2!=NULL)
		{
			while(p2!=NULL)
			{
				start3=insert(start3,p2->coeff,p2->expo);
				p2=p2->link;
			}
		}
	}
	printf("Polynomial Subtarction:");
	display(start3);
}
void multiplication(struct node *start1,struct node *start2)
{
	struct node *start3=NULL;
	if(start1==NULL&&start2==NULL)
	{
		printf("Multiplication  not possible");
		return;
	}
	struct node *p1=start1,*p2;
	if(start1==NULL||start2==NULL)
	{
		printf("Multiplied polynomial is 0");
		return;
	}
	while(p1!=NULL)
	{
		p2=start2;
		while(p2!=NULL)
		{
			start3=insert(start3,(p1->coeff * p2->coeff),(p1->expo+p2->expo));
			p2=p2->link;
		}
		p1=p1->link;
	}
	printf("Ploynomial multiplication:");
	display(start3);
}
int main() 
{
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	int key,e;
	float c;
	printf("%c Enter details for first node to addition::\n",254);
	printf("-------------------------------------------------\n");
	start1=create(start1);
	display(start1);
	printf("%c Enter details for second node to addition::\n",254);
	printf("--------------------------------------------------\n");
	start2=create(start2);
	display(start2);
	addition(start1, start2);
	printf("\n");
	printf("%c Enter details for first node to subtraction::\n",254);
	printf("----------------------------------------------------\n");
	start1=create(start1);
	display(start1);
	printf("%c Enter details for second node to subtarction::\n",254);
	printf("-----------------------------------------------------\n");
	start2=create(start2);
	display(start2);	
	subtraction(start1,start2);
	printf("\n");
	printf("%c Enter details for first node to multiplication::\n",254);
	printf("----------------------------------------------------\n");
	start1=create(start1);	
	display(start1);
	printf("%c Enter details for second node to multiplication::\n",254);
	printf("-----------------------------------------------------\n");
	start2=create(start2);
	display(start2);
	multiplication(start1,start2);
	return 0;
}
