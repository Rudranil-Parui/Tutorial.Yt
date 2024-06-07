#include<stdio.h>
#include<stdlib.h>
#define MAX 50
char stack[MAX];
int top=-1;
char postfix[50];
void push(char);
char pop();
int priority(char);
void infixTopostfix(char []);
void push(char item){
    stack[++top]=item;
}
char pop(){
    return stack[top--];
}
int priority(char x){
    if(x=='^'){
        return 3;
    }
    if((x=='*')||(x=='/')||(x=='%')){
        return 2;
    }
    if((x=='-')||(x=='+')){
        return 1;
    }
}
void infixTopostfix(char s[]){
    int i=0,j=0;
    while(s[i]!='\0'){
        if(s[i]=='('){
            push(s[i]);
        }
        else if(s[i]==')'){
            /*while((v=pop())!='('){
                postfix[j++]=v;
            }*/
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            char xy=pop();
        }
        else if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='%')||(s[i]=='^')){
            while(top!=-1 && stack[top]!='('){
                if(priority(stack[top])>=priority(s[i])){
                    postfix[j++]=pop();
                }
                else{
                    break;
                }
            }
            push(s[i]);
        }
        else if(s[i]!=' '){
            postfix[j++]=s[i];
        }
        i++;
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix Expression::");
    puts(postfix);
}
int main(){
    char s[50];
    printf("Enter your Infix Expression::");
    gets(s);
    infixTopostfix(s);
    return 0;
}
