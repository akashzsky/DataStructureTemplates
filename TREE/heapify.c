#include<stdio.h>
#include<malloc.h>

void maxheapify(int *,int );
void buildmaxheap(int *);
void heapsort(int *);
void swap(int *a,int *b);
void disp(int *,int );
int heapsize,lenght;
void main()
{
    int *a,i,n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    lenght=n;
    a=(int *)malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
         scanf("%d",&a[i]);
    buildmaxheap(a);
    heapsort(a);
    disp(a,lenght);
}
void maxheapify(int *a,int i)
{
    int l,r,largest,temp;
    l =2*i;
    r =2*i+1;
    if(l<=heapsize && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<=heapsize && a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        maxheapify(a,largest);
    }
}
void buildmaxheap(int *a)
{
    int i,k;
    heapsize = lenght;
    for(i=lenght/2;i>=1;--i)
      {
          maxheapify(a,i);
      }
      return a;
}

void heapsort(int *a)
{
    int i;
    for(i = lenght; i >= 2;--i)
    {
       swap( &a[1] , &a[i] );
        heapsize = heapsize - 1;
        maxheapify(a,1);
    }
}
void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void disp(int *a,int lenght)
{
    int i;
    for(i = 1; i <= lenght ; i++)
        printf(" \n%d ",a[i]);
}
