#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
    bool lthread;
    bool rthread;
};
struct node *in_suc(struct node *ptr){
    if(ptr->rthread==true){
        return (ptr->rchild);
    }
    else{
        ptr=ptr->rchild;
        while(ptr->lthread!=true)
            ptr=ptr->lchild;
        return ptr;
    }
}
struct node *in_predec(struct node *ptr){
    if(ptr->lthread==true){
        return (ptr->lchild);
    }
    else{
        ptr=ptr->lchild;
        while(ptr->rthread!=true)
            ptr=ptr->rchild;
        return ptr;
    }
}
void inorder(struct node *root){
    if(root==NULL){
        cout<<"Empty Tree"<<endl;
        return;
    }
    struct node *p=root;
    while(p->lchild!=NULL)
        p=p->lchild;
    cout<<p->data<<endl;
    while(p->rchild!=NULL){
        p=in_suc(p);
        cout<<p->data<<endl;
    }
}
struct node *insert(struct node *root,int key){
    struct node *p=root;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->lthread=true;
    newnode->rthread=true;
    if(root==NULL){
        root=newnode;
        newnode->lchild=NULL;
        newnode->rchild=NULL;
    }
    else{
        while(p!=NULL){
            if(key<p->data){
                if(p->lthread==false)
                    p=p->lchild;
                else
                    break;
            }
            else if(key>p->data){
                if(p->rthread==false)
                    p=p->rchild;
                else
                    break;
            }
            else{
                cout<<"Duplicate Key";
                return root;
            }
        }
        if(p->data>key){
            newnode->lchild=p->lchild;
            p->lchild=newnode;
            p->lthread=false;
            newnode->rchild=p;
        }
        if(p->data<key){
            newnode->rchild=p->rchild;
            p->rchild=newnode;
            p->rthread=false;
            newnode->lchild=p;
        }
        return root;
    }
}
struct node *caseA(struct node *root,struct node *par,struct node *ptr){
    if(par==NULL){
        free(ptr);
        return NULL;
    }
    if(ptr->data>par->data){
        par->rchild=ptr->rchild;
        ptr->lchild=NULL;
        par->rthread=true;
        free(ptr);
    }
    if(par->data>ptr->data){
        par->lchild=ptr->lchild;
        par->lthread=true;
        ptr->rchild=NULL;
        free(ptr);
    }
    return root;
}
struct node *caseB(struct node *root,struct node *par,struct node *ptr){
    struct node *p;
    if(ptr->lthread==false)
        p=ptr->lchild;
    else
        p=ptr->rchild;
    if(par==NULL)
        root=p;
    else if(ptr==par->lchild)
        par->lchild=p;
    else
        par->rchild=p;
    struct node *suc,*pre;
    suc=in_suc(ptr);
    pre=in_predec(ptr);
    if(ptr->lthread==true)
        suc->lchild=suc;
    else
        pre->rchild=suc;
    free(ptr);
    return root;
}