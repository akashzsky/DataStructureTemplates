#include<bits/stdc++.h>
using namespace std;

int getNextMin(int *arr, int ind,int n)
{
    int min = INT_MAX;
    for(int i=ind;i<n;i++){
        if(arr[i]<min)
            min=arr[i];
    }
    return min;
}
int getNextMax(int *arr, int ind,int n)
{
    int max = INT_MIN;
    for(int i=ind;i<n;i++){
        if(arr[i]<max)
            max=arr[i];
    }
    return max;
}

bool isSameBST(int *a,int *b,int n)
{
    for(int i=0;i<n;i++){
        int eleFromA = a[i];
        int eleFromB = b[i];

        if(eleFromA!=eleFromB) return false;
        int min1= getNextMin(a,i+1,n);
        int max1= getNextMax(a,i+1,n);

        int min2= getNextMin(b,i+1,n);
        int max2= getNextMax(b,i+1,n);

        if(min1!=min2 && max2!=max1)
            return false;
    }
    return true;
}




int main()
{
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n=sizeof(a)/sizeof(a[0]);
    if(isSameBST(a, b, n))
    {
        cout << "BSTs are same";
    }
    else
    {
        cout << "BSTs not same";
    }
}
