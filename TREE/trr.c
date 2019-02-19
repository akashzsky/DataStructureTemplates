#include<stdio.h>
#include<stdlib.h>
 typedef struct
 {
     int key;
     int *left,*right;

 }tree;
 void buildtree(tree *);
 tree *search(tree *);
