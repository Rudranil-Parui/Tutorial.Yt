#include<iostream>
#define MAX 10
using namespace std;
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;
struct node *root=NULL;
struct node *stack[MAX];
int top=-1;
int isEmpty(){
    return (root==NULL)?1:0;
}
void push(struct node *x){
    if(top==MAX-1){
        cout<<"Stack Overflow"<<endl;
        return ;
    }
    stack[++top]=x;
}
struct node *pop(){
    if(isEmpty()==1)
        return NULL;
    return stack[top--];
}
//Preorder Traversal in BST:
void preorder(){
    if(root==NULL){
        cout<<"Tree is empty!";
        return;
    }
    struct node *p=root,*q;
    push(root);
    while(isEmpty()!=1){
        q=pop();
        cout<<q->data<<endl;
    }
    if(p->rchild!=NULL)
        push(p->rchild);
    if(p->lchild!=NULL)
        push(p->lchild);
}
//Inorder Traversal in BST:
void inorder(){
    if(root==NULL){
        cout<<"Tree is empty!";
        return;
    }
    struct node *p=root;
    while(1){
        while(p->lchild!=NULL){
            push(p);
            p=p->lchild;
        }
        while(p->rchild!=NULL){
            cout<<p->data<<endl;
            if(isEmpty()==1)
                return;
            p=pop();
        }
        cout<<p->data<<endl;
        p=p->rchild;
    }
}
//Postorder Traversal in BST:
void postorder(){
    if(root==NULL){
        cout<<"Tree is empty!";
        return;
    }
    struct node *p=root,*q=root;
    while(1){
        while(p->lchild!=NULL){
            push(p);
            p=p->lchild;
        }
        while((p->rchild!=NULL)||(p->rchild!=q)){
            cout<<p->data<<endl;
            q=p;
            if(isEmpty()==1)
                return;
            p=pop();
        }
        push(p);
        p=p->rchild;
    }
}