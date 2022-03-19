#include<bits/stdc++.h>
using namespace std;

int * mergeArrays(int *a , int *b)
{
    int *res = new int[8];
    int i,j,k=0;
    for( i=0,j=0;i<4&&j<4;){
        if(a[i]<b[j])
        {
            res[k++]=a[i];
            i++;
        }
        else{
            res[k++]=b[j];
            j++;
        }

    }
    if(i==4 && j<4){
        while(j<4)
        res[k++]=b[j++];
    }
    if(j==4 && i<4){
        while(i<4)
        res[k++]=a[i++];
    }

    return res;
}


int main()
{
    int a[4]={1,4, 6 ,8};
    int b[4]={2, 3 ,5 ,7};

    int *na= mergeArrays(a,b);

    for(int i=0;i<8;i++) cout<<na[i]<<" ";

}
