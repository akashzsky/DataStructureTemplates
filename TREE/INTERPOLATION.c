#include<stdio.h>
int interpolation(int *,int ,int ,int );
void main()
{
        int i,n,a[100],ele,pos;
        printf("enter the total no of element ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the element to be searched ");
    scanf("%d",&ele);
    pos=interpolation(a,0,n-1,ele);
    printf("the searched element is at position %d ",pos);

}
int interpolation(int *a,int l,int u,int k)
{
    int p;
    p=l+ ((k-a[l])*(u-l))/(a[u]-a[l]) ;
    if(k=a[p])
        return p;
    else if(k<a[p])
        interpolation(a,l,p-1,k);
    else
        interpolation(a,p+1,u,k);
}
