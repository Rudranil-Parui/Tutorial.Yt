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
    int i,op1,op2;
    for(i=(n-1);i>=0;i--){
        if((postfix[i]=='+')||(postfix[i]=='-')||(postfix[i]=='*')||(postfix[i]=='/')||(postfix[i]=='%')||(postfix[i]=='^')){
            op1=pop();
            op2=pop();
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
    }
    return (pop());
}
