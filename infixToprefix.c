#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char);
char pop();
int priority(char);
void infixToprefix(char [],int);
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
    if((x=='+')||(x=='-')){
        return 1;
    }
}
void infixToprefix(char s[],int n){
    int i,j=0;
    char exp[100];
    for(i=(n-1);i>=0;i--){
        if(s[i]==')'){
            push(s[i]);
        }
        else if(s[i]=='('){
            while(stack[top]!=')'){
                exp[j++]=pop();
            }
            pop();
        }
        else if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='%')||(s[i]=='^')){
            while((top!=-1)&&stack[top]!=')'){
                if(priority(stack[top])>priority(s[i])){
                    exp[j++]=pop();
                }
                else{
                    break;
                }
            }
            push(s[i]);
        }
        else if(s[i]!=' '){
            exp[j++]=s[i];
        }
    }
    while(top!=-1){
        exp[j++]=pop();
    }
    exp[j]='\0';
    for(i=0;i<=(n-1);i++){
        push(exp[i]);
    }
    i=0;
    while(top!=-1){
        exp[i]=pop();
        i++;
    }
    printf("Prefix Expression::");
    puts(exp);
}
int main(){
    char s[50];
    printf("Enter your Infix Expression::");
    gets(s);
    infixToprefix(s,strlen(s));
    return 0;
}
