#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
    int data,ind;
    struct tnode *left;
    struct tnode *right,*p;
}node;
node *insert(node * , int,int);
   node *root;
int main()
{
    root= NULL;
    node *m,*res;
    int x,i;
    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
        scanf("%d",&x);
        root= insert(root,x,i);
        printf("I'm root %d\n",root->data);
        }
}
node *insert(node *t, int x,int i)
{
    int n;
    if(t==NULL)
    {
        t=(node*)malloc(sizeof(node));
        if(t==NULL)
            printf("\n out of memory space");
        else
        {
            t->data=x;
            t->left=t->right=NULL;
            t->ind=i;
            printf("%d\t",t->ind);
           // return t;
        }
    }
     else if(x< t->data)
        t->left=insert(t->left,x,2*(t->ind));
    else if(x> t->data)
       t->right= insert(t->right,x,2*(t->ind)+1);
return t;
}

