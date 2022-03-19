#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node *right;
};

int max_height(Node* node)
{
    if(node==NULL){
        return 0;
    }

    return max(max_height(node->left)+1, max_height(node->right)+1);
}



Node* searchHelper(Node* node, int x,int y)
{

    if(node==NULL){
        return NULL;
    }

    if(node->key==x || node->key==y) return node;

    Node* leftSide = searchHelper(node->left,x,y);
    Node* rightSide = searchHelper(node->right,x,y);

    if(!leftSide) return rightSide;
    if(!rightSide) return leftSide;

    //when none of them is null, it means it has found in left and right
    return node;

}

Node* findLca(Node* node, int x,int y)
{
    if(node){
        return searchHelper(node,x,y);
    }
    return NULL;
}

void getParents( unordered_map<Node*,Node*> &hash, Node * node, Node* parent)
{
    if(node==NULL) return;

    hash.insert(make_pair(node,parent));

    getParents(hash,node->left,node);
    getParents(hash,node->right,node);

}
void extractLayerFromQueue(queue<Node*> &q)
{
    cout<<"size of queue "<<q.size()<<endl;
    while(!q.empty()){
        cout<<q.front()->key<<" ";
        q.pop();
    }
    cout<<endl;
}
void KthDistantNodes_from_GivenNode(Node * root, Node* node, int targetK)
{
    if(node==NULL){
        cout<<" Node can't be null";
        return;
    }
    unordered_map<Node*,Node*> parentHash;
    getParents(parentHash,root,NULL);

    queue<Node*> q;
    q.push(node);
    //when it is not checked any other node then current level=0
    int currentK=0;

    unordered_map<Node*,bool> seen;
    seen.insert(make_pair(node,true));

    while(!q.empty()){

        if(currentK==targetK){
            extractLayerFromQueue(q);
            return;
        }
        int layerSize = q.size();
        for(int i=0;i<layerSize;i++){
            Node * curr = q.front();
            q.pop();

            if(curr->left && seen.find(curr->left)==seen.end()){
                seen.insert(make_pair(curr->left,true));
                q.push(curr->left);
            }
            if(curr->right && seen.find(curr->right)==seen.end()){
                seen.insert(make_pair(curr->right,true));
                q.push(curr->right);
            }
            Node* parent;
            std::unordered_map<Node*,Node*>::const_iterator got = parentHash.find (curr);
            if(got!=parentHash.end())

                parent= (got)->second;

            if(parent && seen.find(parent)==seen.end()){
                seen.insert(make_pair(parent,true));
                q.push(parent);
            }
        }
        currentK++;
        // left child

    }
}

void sumHelper(Node* node, vector<int> &v, int *i)
{
    if(node==NULL) return;

    sumHelper(node->left, v, i);
    cout<<"here i is " << *i <<endl;
    cout<<"Here node is "<<node->key<<" and v[i-1], v[i+1] ="<<v[*i-1]<<" "<<v[*i+1]<<endl;
    node->key = v[*i-1]+v[*i+1];
    (*i)++;
    sumHelper(node->right,v,i);
}
void StoreInorder(Node* node, vector<int> &v)
{
    if(node==NULL) return;

    StoreInorder(node->left,v);
    v.push_back(node->key);
    StoreInorder(node->right,v);
}


void sumOfSuccPred(Node * node)
{
    vector<int> v;
    //cout<<"here1"<<endl;
    v.push_back(0);

    StoreInorder(node,v);
    //cout<<"here2"<<endl;
    v.push_back(0);
    int ind=1;
    int *i =&ind;
    //for(auto x: v) cout<<x<<" ";
   // cout<<"here3"<<endl;
    sumHelper(node,v,i);
    //cout<<"here4"<<endl;
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
void inorder(Node* temp)
{
    if (!temp)
        return;

    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
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

//---------------------------------
     //Inorder
//cout<<root->key<<endl;
   // inorder(root);

//---------------------------------


    /*LCA
    ----------------------------------
    Node* res=findLca(root,4,6);
    cout<<res->key<<endl;
    -----------------------------------
    */

    /* kth distant layers in a binary tree given the node "root->left" and distance 1
    -----------------------------------------------------------------------------------------
    KthDistantNodes_from_GivenNode(root,root->left,1);
    -----------------------------------------------------------------------------------------
    */

    /*
    FIND MAX HEIGHT OF A BIANRY TREE
    ----------------------------------------
    int h= max_height(root);
    cout<<h<<endl;
    ----------------------------------------
    */


    /* Node=Inorder Succ + Inorder Predecessor */
    //-------------------------------------------------


    cout<<(*root).key<<endl;
    sumOfSuccPred(root);
    cout<<root->key<<endl;
    inorder(root);


}
