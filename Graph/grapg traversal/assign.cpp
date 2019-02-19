#include <iostream>
using namespace std;
int c=0;
int gcd(int a,int b);
int main() {
	// your code goes here
  int i = 0, j = 0, k = 0;
    for (int m = 1; m <= 5; m = m+1){
      if (gcd(m,9381) > 2){
        i = i + m;
        k = k + m;
      }else{
        j = j + m;
        k = k + m;
      }
     cout<<i<<"\t"<< j<<"\t"<<k<<endl;
    }

}
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
