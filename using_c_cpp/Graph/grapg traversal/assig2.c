#include<stdio.h>
int k=0;
void StrangeMerge(int *A,int m,int *B,int n,int *C) {
    // A has m elements, B has n elements
    int i = 0, j = 0;

    while (k < m+n) {
      if (i == m) {j++; k++;}
      if (j == n)
        {C[k] = A[i];
      i++; k++;}

      if (i != m && j != n) {
        if (A[i] < B[j]) {C[k] = A[i]; i++; k++;}
        if (A[i] == B[j]) {i++; j++;}
        if (A[i] > B[j]) {j++;}
      }
    }
  }
int main()
{
    int a[100],b[100],m,n,c[1000]={0};
    scanf("%d%d",&m,&n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=0;j<m;j++)
        scanf("%d",&b[j]);

    StrangeMerge(a,m,b,n,c);
    for(i=0;i<k-1;i++)
        printf("%d\t",c[i]);
}
