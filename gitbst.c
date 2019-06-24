#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
    int data,ind;
    struct tnode *left;
    struct tnode *right,*p;
}node;
void inorder(node *);
node *insert(node * , int,int);
node *search(node *,int);
node *succ(node *);
node *min(node *);

   node *root;//tree *del(tree *, int);

int main()
{
    root= NULL;
    node *m,*res;
    int op,x,key,i;
    // printf("\n 1. INSERT");
    int n;
    scanf("%d",&n);
    printf("insert the node to be inserted");

    for(i=1;i<=n;i++)
        {
        scanf("%d",&x);
        root= insert(root,x,i);
        printf("root data is %d and index is %d\n",root->data,root->ind);

      }
    while(1)
    {
        printf("\n\n***  Main Menu  ***\n");
        printf("\n 1. Search");
        printf("\n 2. Minimum");
       // printf("\n 3. Maximum");
        printf("\n 3. successor");

        printf("\n 4. exit");
        printf("\n enter ur option");
        scanf("%d",&op);
        switch(op)
        {

        case 1:printf ("enter the node to be searched having data ");
               scanf("%d",&key);
             res=search(root,key);
             printf("searched node is %d\n",res->data);
        break;
        case 2:m= min(root);
         printf("returned node after calling min function is %d\n",m->data);
        break;

        /*case 2: printf("enter the element to be deleted");
                 scanf("%d",&x);
                 t=delete(t,x);
                 break;*/
        case 3:printf ("enter the node data to get it's successor  ");
               scanf("%d",&key);
             res=succ(search(root,key));
             printf("successor node is %d\n",res->data);
        break;
        case 4: exit(1);
        }
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
            return t;
        }
    }
   // printf("after calling insert node detail is %d\n",t->data);
     else if(x< t->data)
        return insert(t->left,x,2*(t->ind));
    else if(x> t->data)

       return insert(t->right,x,2*(t->ind)+1);

}
node *search(node *x,int k)
{
    if(x->data==k || x==NULL)
        return x;
    if(k<x->data)
        return search(x->left,k);
        else
        return search(x->right,k);
}
void inorder(node *t)
{
   if(t != NULL)
   {
     inorder(t->left);
           printf("%d\t", t->data);
     inorder(t->right);

   }
}
node *min(node *t)
{
    node *root=t;
    //printf("root is %d\n",t->data);
   while(t->left != NULL)
   {
      // printf("node left child data is %d\n",(t->left)->data);
     t=t->left;
   }
   //printf("minimum is %d\n",t->data);
    //printf("root is %d\n",root->data);
   return t;
}
node *succ(node *t)
{

   if(t->right!= NULL)
   {
       return min(t->right);
   }
   //return t;
}
