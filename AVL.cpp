#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left, *right;
	int height;

	node(int value)
	{
		this->data = value;
		left = right = NULL;
		height = 1;
	}
};

int getHeight(node *root)
{
	return root ? root->height : 0; // if NUll return 0 else return root->height
}

int balanceFactor(node *root)
{
	if (!root)
		return 0;
	return getHeight(root->left) - getHeight(root->right);
}

/*

	  x
	/  \
   y    t1
  / \
t2  t3

after right rotation ->

	  y
	/  \
   t2	x
	   / \
	  t3  t1

*/

node *rightRotate(node *x)
{
	node *y = x->left;
	node *t3 = y->right;

	y->right = x;
	x->left = t3;

	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));

	return y; // y is root now
}

node *leftRotate(node *y)
{
	node *x = y->right;
	node *t3 = x->left;

	x->left = y;
	y->right = t3;

	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));

	return x; // x is root now
}

node *insert(node *root, int value)
{
	if (!root)
		return new node(value); // create a new node and return that new node
	if (value > root->data)
		root->right = insert(root->right, value);
	else if (value < root->data)
		root->left = insert(root->left, value);
	else
	{
		cout << "Already Present in the tree." << endl;
		return root;
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int bf = balanceFactor(root);

	if (bf > 1) // left side's weight is more
	{
		if (value < root->left->data)
			return rightRotate(root);
		else
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	else if (bf < -1)
	{
		if (value > root->right->data)
		{
			return leftRotate(root);
		}
		else
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

node *inorderSuccessor(node *root)
{
	root = root->right;
	while (root->left)
		root = root->left;
	return root;
}

node *erase(node *root, int value)
{
	if (!root)
		return NULL;
	if (value > root->data)
		root->right = erase(root->right, value);
	else if (value < root->data)
		root->left = erase(root->left, value);
	else
	{

		if (!root->left || !root->right) // single pola or no pola
		{
			node *temp = root->right;
			if (root->left)
				temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			node *temp = inorderSuccessor(root);
			root->data = temp->data;
			root->right = erase(root->right, root->data);
		}
	}

	if (root == NULL)
		return NULL;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int bf = balanceFactor(root);
	if (bf > 1)
	{
		if (balanceFactor(root->left) >= 0)
			return rightRotate(root);
		else
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	else if (bf < -1)
	{
		if (balanceFactor(root->right) <= 0)
			return leftRotate(root);
		else
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}

	return root;
}

void breadthFirstSearch(node *root)
{
	if (!root)
		return;
	queue<node *> q;
	q.push(root);
	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	cout << endl;
}

int main()
{
	int size;
	cout << "Enter the number of nodes :";
	cin >> size;

	node *root = NULL;

	while (size--)
	{
		cout << "Enter the value : ";
		int val;
		cin >> val;
		root = insert(root, val);
	}
	breadthFirstSearch(root);
	cout << "Enter how many nodes you want to delete : ";
	cin >> size;
	while (size--)
	{
		int val;
		cout << "Enter data : ";
		cin >> val;
		root = erase(root, val);
	}
	breadthFirstSearch(root);
	return 0;
}