#include<stdio.h>
#include<stdlib.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char);
char pop();
void push(char item){
    if(top==MAX-1){
        printf("Stack overflow");
        return;
    }
    stack[++top]=item;
}
char pop(){
    return (top==-1)?stack[top--]:'\0';
}
int main(){
    char s[50];
    int i;
    printf("Enter your string::");
    gets(s);
    for(i=0;s[i]!='\0';i++){
        push(s[i]);
    }
    i=0;
    while(top!=-1){
        s[i++]=pop();
    }
    printf("Reverse String::");
    puts(s);
    return 0;
}
