#include <iostream>
#define MAX 10
using namespace std;
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} node;
struct node *stack[MAX];
struct node *Q[MAX];
int top = -1;
int front = -1, rear = -1;
int isEmpty()
{
    return ((front == -1) || (front = rear + 1)) ? 1 : 0;
}
int isEmpty_stack(struct node *root)
{
    return (root == NULL) ? 1 : 0;
}
void push(struct node *x)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = x;
}
struct node *pop(struct node *root)
{
    if (isEmpty_stack(root) == 1)
        return NULL;
    return stack[top--];
}
void enqueue(struct node *x)
{
    if (front == -1)
        front = 0;
    Q[++rear] = x;
}
struct node *dequeue()
{
    if (isEmpty() == 1)
        return NULL;
    return Q[front++];
}
int count()
{
    int c = 1;
    while (front != rear)
        c++;
    return c;
}
// Insertion in a BST:
struct node *insert(struct node *root, int key)
{
    struct node *newnode = new struct node;
    newnode->data = key;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    struct node *p = root, *par = NULL;
    while (p != NULL)
    {
        par = p;
        if (p->data > key)
            p = p->lchild;
        else if (p->data < key)
            p = p->rchild;
        else
        {
            cout << "Invalid Input!! Duplicate Key!!" << endl;
            return root;
        }
    }
    if (par == NULL)
        root = newnode;
    else if (par->data > key)
        par->lchild = newnode;
    else
        par->rchild = newnode;
    return root;
}
// Searching a node in BST
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        cout << "Empty Tree!" << endl;
        return NULL;
    }
    struct node *p = root;
    while (p != NULL)
    {
        if (p->data > key)
            p = p->lchild;
        else if (p->data < key)
            p = p->rchild;
        else
            return p;
    }
    return NULL;
}
// Maximum element in BST
struct node *max_search(struct node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return NULL;
    }
    struct node *p = root;
    while (p->rchild != NULL)
        p = p->rchild;
    return p;
}
// Minimum element in BST
struct node *min_search(struct node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return NULL;
    }
    struct node *p = root;
    while (p->lchild != NULL)
        p = p->lchild;
    return p;
}
//-: Deletion in a BST :-
// 1. Node has no child (i.e. Lesf node)
struct node *caseA(struct node *root, struct node *par, struct node *ptr)
{
    //(i) if par==NULL
    //(ii) if (root->lchild==NULL && root->rchild==NULL)
    //(iii) if root==ptr
    if (par == NULL)
    {
        free(ptr);
        return par;
    }
    if (par->data < ptr->data)
        par->rchild = NULL;
    else
        par->lchild = NULL;
    free(ptr);
    return root;
}
// 2. Node has exactly one child
struct node *caseB(struct node *root, struct node *par, struct node *ptr)
{
    struct node *p;
    if (ptr->rchild == NULL)
        p = ptr->lchild;
    if (ptr->lchild == NULL)
        p = ptr->rchild;
    if (par == NULL)
    {
        root = p;
        free(ptr);
    }
    else
    {
        if (par->rchild == ptr)
            par->rchild = p;
        else
            par->lchild = p;
        free(ptr);
    }
    return root;
}
// 3. Node has exactly two children
struct node *caseC(struct node *root, struct node *par, struct node *ptr)
{
    struct node *parsuc = ptr, *suc = ptr->rchild;
    while (suc->lchild != NULL)
    {
        parsuc = suc;
        suc = suc->lchild;
    }
    ptr->data = suc->data;
    if (suc->rchild != NULL)
        root = caseB(root, parsuc, suc);
    else
        root = caseA(root, parsuc, suc);
    return root;
}
// 4. Main Delete fucntion (which can operate the above three cases):
struct node *delete_main(struct node *root, int key)
{
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return NULL;
    }
    struct node *par = NULL, *ptr = root;
    while (ptr != NULL)
    {
        par = ptr;
        if (ptr->data > key)
            ptr = ptr->lchild;
        else if (ptr->data < key)
            ptr - ptr->rchild;
        else
            break;
    }
    if (ptr == NULL)
        cout << key << " Key is not found" << endl;
    else if (ptr->lchild == NULL && ptr->rchild == NULL)
        root = caseA(root, par, ptr);
    else if (ptr->lchild != NULL && ptr->rchild != NULL)
        root = caseC(root, par, ptr);
    else
        root = caseB(root, par, ptr);
    return root;
}
// 5. Height of BST
int height(struct node *root)
{
    struct node *p = root;
    int h = 0;
    enqueue(p);
    h++;
    while (isEmpty() != 1)
    {
        for (int i = 0; i <= count(); i++)
        {
            p = dequeue();
            if (p->lchild != NULL)
                enqueue(p->lchild);
            if (p->rchild != NULL)
                enqueue(p->rchild);
        }
        h++;
    }
    return h;
}
// 1. Preorder Traversal in BST:
void preorder(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!";
        return;
    }
    struct node *p = root, *q;
    push(root);
    while (isEmpty_stack(root) != 1)
    {
        q = pop(root);
        cout << q->data << endl;
    }
    if (p->rchild != NULL)
        push(p->rchild);
    if (p->lchild != NULL)
        push(p->lchild);
}
// 2. Inorder Traversal in BST:
/*void inorder(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!";
        return;
    }
    struct node *p = root;
    while (1)
    {
        while (p->lchild != NULL)
        {
            push(p);
            p = p->lchild;
        }
        while (p->rchild != NULL)
        {
            cout << p->data << endl;
            if (isEmpty_stack(root) == 1)
                return;
            p = pop(root);
        }
        cout << p->data << endl;
        p = p->rchild;
    }
}*/
void inorder(struct node*root){
    if(!root)return;
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
}
// 3. Postorder Traversal in BST:
void postorder(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!";
        return;
    }
    struct node *p = root, *q = root;
    while (1)
    {
        while (p->lchild != NULL)
        {
            push(p);
            p = p->lchild;
        }
        while ((p->rchild != NULL) || (p->rchild != q))
        {
            cout << p->data << endl;
            q = p;
            if (isEmpty_stack(root) == 1)
                return;
            p = pop(root);
        }
        push(p);
        p = p->rchild;
    }
}
// 4. Level order traversal
void levelorder(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    struct node *p = root;
    enqueue(p);
    while (isEmpty() != 1)
    {
        p = dequeue();
        if (p->lchild != NULL)
            enqueue(p->lchild);
        if (p->rchild != NULL)
            enqueue(p->rchild);
        cout << p->data;
    }
}
int main()
{
    struct node *root = NULL, *p;
    int key, n;
    while (1)
    {
        cout << "\nPress 1 to insert a node in BST:" << endl;
        cout << "Press 2 to delete a node in BST:" << endl;
        cout << "Press 3 to searching a node in BST" << endl;
        cout << "Press 4 to find maximum element in BST" << endl;
        cout << "Press 5 to find minimum element in BST" << endl;
        cout << "Press 6 to calculate the height of BST" << endl;
        cout << "Press 7 to display the BST in preorder traversal" << endl;
        cout << "Press 8 to display the BST in inorder traversal" << endl;
        cout << "Press 9 to display the BST in postorder traversal" << endl;
        cout << "Press 10 to display the BST in level order traversal" << endl;
        cout << "Press 11 to exit" << endl;
        cout << "Enter your choice:-" << endl;
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "Enter your number to insert" << endl;
            cin >> n;
            root = insert(root, n);
            break;
        case 2:
            cout << "Enter your number to delete:" << endl;
            cin >> n;
            root = delete_main(root, n);
            break;
        case 3:
            cout << "Enter your number to search:" << endl;
            cin >> n;
            root = search(root, n);
            break;
        case 4:
            p = max_search(root);
            cout << "Maximum element is: " << p->data << endl;
            break;
        case 5:
            p = min_search(root);
            cout << "Minimum element is: " << p->data << endl;
            break;
        case 6:
            n = height(root);
            cout << "Height of the BST " << n << endl;
            break;
        case 7:
            cout << "Preorder traversal of the BST is: -" << endl;
            preorder(root);
            break;
        case 8:
            cout << "Inorder traversal of the BST is: -" << endl;
            inorder(root);
            break;
        case 9:
            cout << "Postorder traversal of the BST is: -" << endl;
            postorder(root);
            break;
        case 10:
            cout << "Level order traversal in BST is: -" << endl;
            levelorder(root);
            break;
        case 11:
            exit(0);
            break;
        }
    }
    return 0;
}