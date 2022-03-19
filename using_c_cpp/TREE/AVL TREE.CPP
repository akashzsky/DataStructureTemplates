// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get the
// height of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
//Node* newNode(int key)
//{
//	Node* node = new Node();
//	node->key = key;
//	node->left = NULL;
//	node->right = NULL;
//	node->height = 1; // new node is initially
//					// added at leaf
//	return(node);
//}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		{
		    node->left = insert(node->left, key);
		    cout<<"inserted node is "<<node->left->key<<" ";
		}
	else if (key > node->key)
		{

		    node->right = insert(node->right, key);
		    cout<<"inserted node is "<<node->right->key<<" ";
		}
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
//    cout<<"here current node is "<<node->key<<" and height is "<<node->height<<endl;
//    cout<<" Now checking bf "<<endl;
	int balance = getBalance(node);
    cout<<" and balance is now "<<balance<<endl<<endl;
	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key){
        Node* cc=leftRotate(node);
        cout<<"after 2nd insertion "<<cc->key<<endl;
        return cc;
	}


	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Driver Code
int main()
{
	Node *root = NULL;

	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	//cout<<"root height is "<<root->height<<endl;
	cout<<"preorder after 1st ";
	preOrder(root);cout<<endl;
	root = insert(root, 20);
	cout<<"preorder after 2nd ";
	preOrder(root);cout<<endl;
	root = insert(root, 30);cout<<"preorder after 3rd ";
	preOrder(root);cout<<endl;
	root = insert(root, 40);cout<<"preorder after 4th ";
	preOrder(root);cout<<endl;
	root = insert(root, 50);cout<<"preorder after 5th ";
	preOrder(root);cout<<endl;
	root = insert(root, 25);cout<<"preorder after 6th ";
	preOrder(root);cout<<endl;

	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	preOrder(root);

	return 0;
}

// This code is contributed by
// rathbhupendra

