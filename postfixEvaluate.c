#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 50
int stack[MAX];
int top=-1;
char postfix[50];
void push(char);
int pop();
int postfixEvaluate(char [],int);
int postfixEvaluate(char postfix[],int n){
    int i=0,op1,op2;
    while(i!=n){
        if((postfix[i]=='+')||(postfix[i]=='-')||(postfix[i]=='*')||(postfix[i]=='/')||(postfix[i]=='%')||(postfix[i]=='^')){
            op2=pop();
            op1=pop();
            switch(postfix[i]){
                case '+':
                        push(op1+op2);
                        break;
                case '-':
                        push(op1-op2);
                        break;
                case '*':
                        push(op1*op2);
                        break;
                case '/':
                        push(op1/op2);
                        break;
                case '%':
                        push(op1%op2);
                        break;
                case '^':
                        push(pow(op1,op2));
                        break;
            }
        }
        else{
            push(atoi(postfix[i]));
        }
        i++;
    }
    return (pop());
}
