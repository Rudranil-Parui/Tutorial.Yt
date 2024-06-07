#include<iostream>
#define MAX 10
using namespace std;
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;
struct node *root=NULL;
struct node *Q[MAX];
int front=-1,rear=-1;
int isEmpty(){
    return ((front==-1)||(front=rear+1))?1:0;
}
void enqueue(struct node *x){
    if(front==-1)
        front=0;
    Q[++rear]=x;
}
struct node *dequeue(){
    if(isEmpty()==1)
        return NULL;
    return Q[front++];
}
void levelorder(){
    if(root==NULL){
        cout<<"Tree is Empty"<<endl;
        return;
    }
    struct node *p=root;
    enqueue(p);
    while(isEmpty()!=1){
        p=dequeue();
        if(p->lchild!=NULL)
            enqueue(p->lchild);
        if(p->rchild!=NULL)
            enqueue(p->rchild);
        cout<<p->data;
    }
}
int main(){
    
    return 0;
}