#include<iostream>
using namespace std;


int main(){

    int d;



    int *p = (int *)operator new(sizeof(int));



    d = 5;

    *p = d;

    cout << ++*p + d++;



    return 0;

}
