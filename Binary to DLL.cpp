#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node* left, *right, *prev;
};

Node * newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->right = node->left = NULL;

    return node;
}


Node* insert(Node * node, int key)
{
    if(node==NULL) return newNode(key);

    if(key<node->key)
        node->left = insert( node->left , key );
    else if(key>node->key)
        node->right = insert( node->right, key);
    else return node;
}

void convert(Node *p, Node** head, Node** prev)
{
    if(!p) return ;

    //static Node* prev=NULL;

    convert(p->left, head, prev);

    if(*prev==NULL){
        *head = p;
    }
    else{
        p->left=*prev;
        (*prev)->right = p;
    }
    *prev=p;


    convert(p->right, head, prev);

    //return *head;
}


void inorder(Node * node)
{
    if(node){
        inorder(node->left);
        cout<<node->key<<" ";
        inorder(node->right);
    }
    else return;
}
void preorder(Node * node)
{
    if(node){
        cout<<node->key<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    else return;
}

int main()
{
    Node * root = NULL;
    root = insert(root, 10);
    root = insert(root, 24);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 45);
    root = insert(root, 15);
    root = insert(root, 45);

    //before conversion inorder of tree
    inorder(root);

//    Node* dnode=NULL;
//
//    //Converting to DLL
//    Node* prev=NULL;
//
//    convert(root,&dnode,&prev);
//
//
//    //after convertion to DLL
//    cout<<"\n cheers here is the DLL nodes \n";
//    while(dnode){
//        cout<<dnode->key<<" ";
//        dnode = dnode->right;
//    }

    cout<<endl;
    cout<<"preorder is: ";
    preorder(root);
}













