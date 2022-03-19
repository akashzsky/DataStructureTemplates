#include<bits/stdc++.h>
#include<string>
using namespace std;
istream& getline(char *s,streamsize n);
int main()
{
    int t;
    string a;
    char b[100000];
    cin>>t;
    while(t--)
    {
        getline(cin>>std::ws,a);
            int j=1,h[100000],y=1;
         for(int i=0;a[i]!='\0';i++)
         {
            // printf("%d\n",a[i]);
            if(a[i]>122 || a[i]<65)
             {
                 j++;
                 h[y]=i;
                 y++;
             }
         }

         if(j==1)
         {
             if(a[0]>=97 && a[0]<=122)
                a[0]=a[0]-32;
            for(int i=1;a[i]!='\0';i++)
          {
            // printf("%d\n",a[i]);
            if(a[i]>=65 && a[i]<=90)
             {
                 a[i]=a[i]+32;
             }
           }
           cout<<a;

         }
         else
         {


         int l=0,i,first,f=0,m,c=0;
         first=j;

         for(int k=1;k<=j;k++)
         {
              c=0;
            // printf("%c\n",a[i]);


               if(k<j)
               {
                  // cout<<k<<endl;
                   for(i=l;a[i]!='\0';i++)
                 {
                   if(a[i]>=97 && a[i]<=122)
                   {
                       b[f]=a[i]-32;
                       //printf("%c",b[i]);
                   }
                    else
                        b[f]=a[i];
                     f++;
                    b[f]='.';
                    f++;
                     b[f]=' ';
                    f++;
                    l=h[k]+1;
                    break;
                 }
               }
               if(k==j)
               {
                  // cout<<"k is"<<k;
                   m=l;
                  c=1;
               }
             }


           if(c==1)
           {
              if(a[m]>=97 && a[m]<=122)
                {b[f]=a[m]-32;
               // cout<<"yes this is b[f]"<<b[f];
                }
                else
                    b[f]=a[m];
                f++;
               for(int i=m+1;a[i]!='\0';i++)
              {
            // printf("%d\n",a[i]);
               if(a[i]>=65 && a[i]<=90)
               {
                 b[f]=a[i]+32;
                 f++;
               }
                             else
                   {
                       b[f]=a[i];
                f++;}
              }

        }

          for(int i=0;i<f;i++)
            printf("%c",b[i]);

         }
     cout<<endl;
    }
}
