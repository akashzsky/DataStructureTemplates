#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
    int flag;
}tree;
typedef struct snode
{
    struct tnode *ptr;
    struct snode *next;
}stack;
tree *insert(tree * , int );
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);
stack *push(stack * , tree *);
stack *pop(stack *);

stack *top=NULL;

tree *t=NULL;
int main()
{

    int op,x;
    while(1)
    {
        printf("\n\n***  Main Menu  ***\n");
        printf("\n 1. INSERT");
        printf("\n 3. preorder traversal");
        printf("\n 4. inorder traversal");
        printf("\n 5. postorder traversal");
        printf("\n 6. exit");
        printf("\n enter ur option");
        scanf("%d",&op);
        switch(op)
        {
        case 1: printf("insert the tree to be inserted");
                scanf("%d",&x);
                t= insert(t,x);
                break;

        case 3: preorder(t);
        break;
        case 4:inorder(t);
        break;
        case 5: postorder(t);
        break;
        case 6: exit(1);
        }
    }
}
stack *pop(stack *top)
{
    stack *temp;
    temp=top;
    if(top==NULL)
    {
        printf("\n stack empty|||UNDERFLOW\n\n");
        return;
    }
    else
    {
       top=top->next;
        free(temp);
    }
    return top;
}
stack *push(stack *top,tree *node)
{
    stack *newnode;

    newnode=(stack*)malloc(sizeof(stack));
    newnode->ptr = node;
    if(top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    return top;
}
tree *insert(tree *t, int x)
{
    if(t==NULL)
    {
        t=(tree*)malloc(sizeof(tree));
        if(t==NULL)
            printf("\n out of memory space");
        else
        {
            t->data=x;
            t->left=t->right=NULL;
        }
    }
    else if(x< t->data)
        t->left=insert(t->left,x);
    else if(x> t->data)

       t->right=insert(t->right,x);
return t;
}
void preorder(tree *node)
{

    stack *curr;
    do
    {
        while(node!=NULL)
        {
            printf("%d  ",node->data);
            if(node->right!=NULL)
                top=push(top,node->right);
            node=node->left;
        }
        if(top!=NULL)
        {
            node=top->ptr;
            top=pop(top);
        }
    }while(top!=NULL || node!=NULL);
}


void inorder(tree *node)
{
    do
    {
        while(node!= NULL)
        {
            top=push(top,node);
            node=node->left;
        }
        if(top!=NULL)
        {
            node=top->ptr;
            printf("%d  ",node->data);
            node=node->right;
            top=pop(top);
        }
    }while(top!=NULL || node!=NULL);
}
void postorder(tree *node)
{
    do
    {
        while(node!=NULL)
        {
            node->flag=0;
            top=push(top,node);
            if(node->right!=NULL)
            {
                node->right->flag=1;
                top=push(top,node->right);
            }
            node=node->left;
        }
        if(top!=NULL)
        {
            node=top->ptr;
            while(node->flag==0)
            {
                printf("%d  ",node->data);
                top=pop(top);
                node=top->ptr;
            }
            top=pop(top);
        }
    }while(top!=NULL || node!=NULL);
}
