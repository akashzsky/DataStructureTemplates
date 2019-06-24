#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node *right;
};
bool Search(Node* node, int key)
{
    if(node==NULL) return false;
    if( node->key == key ) return true;
    bool res1 = Search(node->left, key);

    /* now recur on right subtree */
    bool res2 = Search(node->right, key);

    return res1 || res2;
}
string findLca(Node* node, int x,int y)
{
    if(node==NULL) return "no";
    if(node->key==x){
        if(Search(node,y))
            return "yes";
        else
            return "no";
    }
    string res = findLca(node->left,x,y);
    if(res =="no")
        res = findLca(node->right, x, y);
    return res;
}
Node * newNode(int val)
{
    Node* node = new Node;
    node->key= val;
    node->left=NULL;
    node->right=NULL;

    return node;
}
Node* insert(Node *node, int val){
    //level order traversal to find the last inserted node in the tree
    queue<Node*> q;
    q.push(node);
    Node * res;
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();

       // cout<<" in the function inside queue temp is "<<temp->key<<endl;
        if(temp==NULL)
        {
            return newNode(val);
            //node=temp;
            //break;
        }
        if(temp->left==NULL){
            temp->left = newNode(val);
            //cout<<"Inserting in left "<<temp->left->key<<endl;
            break;
        }
        else q.push(temp->left);
        if(temp->right==NULL){
            temp->right = newNode(val);
            break;
        }
        else q.push(temp->right);

    }
    return node;
}
int main(){

    Node * root=NULL;
    //root = newNode(10);
    /*root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    */
    int n;
    cout<<" Enter no of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int val; cin>>val;
        root=insert(root,val);
        //cout<<" root is "<<root->key<<"\n";
    }
    int u,v; cin>>u>>v;
    cout<<findLca(root,u,v)<<endl;
}
