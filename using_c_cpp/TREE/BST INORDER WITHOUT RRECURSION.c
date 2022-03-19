#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
}tree;
typedef struct snode
{
    struct tnode *t;
    struct snode *next;
}stack;
void push(stack **top_ref, tree *t);
tree *pop(stack **top_ref);
int isempty(stack *top);
void inorder(tree *root);
tree *insert(tree * , int );
tree *del(tree *, int);
    tree *t=NULL;

int main()
{

    int op,x;
    while(1)
    {
        printf("\n\n***  Main Menu  ***\n");
        printf("\n 1. INSERT");
   //     printf("\n 2. DELETE");
        printf("\n 3. inorder traversal");
        printf("\n 4. exit");
        printf("\n enter ur option");
        scanf("%d",&op);
        switch(op)
        {
        case 1: printf("insert the tree to be inserted");
                scanf("%d",&x);
            t= insert(t,x);
            break;
        /*case 2: printf("enter the element to be deleted");
                 scanf("%d",&x);
                 t=delete(t,x);
                 break;
*/        case 3: inorder(t);
        break;
        case 4: exit(1);
        }
    }
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
/*tree *del(tree *t,int x)
{

}*/
int isempty(stack *top)
{
    return(top==NULL)? 1:0;
}
void inorder(tree *root)
{
    tree *current =root; // set current to the root
    stack *s=NULL; // initialize stack s
    int done=0;
    while(!done)
    {
        if(current != NULL)
        {
            push(&s,current);
            current=current->left;
        }
        else
        {
            if(!isempty(s))
            {
                current = pop(&s);
                printf("%d\t ", current->data);
                current=current->right;
            }
            else done=1;
        }
    }
}
void push(stack **top_ref,tree *t)
{
    stack *temp=(stack*)malloc(sizeof(stack));
    if(temp==NULL)
    {
        printf("stack overflow");
        return;
    }
    temp->t=t;
    temp->next=(*top_ref);
    (*top_ref)=temp;
}
tree *pop(stack **top_ref)
{
    tree *res;
    stack *top;
    if(isempty(*top_ref))
    {
        printf("stack underflpw");
        return;
    }
    else{
        top=(*top_ref);
    res=top->t;
    (*top_ref)=top->next;
    free(top);
    return res;
    }
}

